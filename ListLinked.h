#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <stdexcept>
#include "List.h"
#include "Node.h"

template <class T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked() : first(nullptr), n(0) {}

    ~ListLinked() override {
        while (first) {
            Node<T>* tmp = first;
            first = first->next;
            delete tmp;
        }
    }

    int size() override { return n; }

    void prepend(T e) override {
        first = new Node<T>(e, first);
        ++n;
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) throw std::out_of_range("insert");
        if (pos == 0) {
            prepend(e);
            return;
        }
        Node<T>* prev = first;
        for (int i = 0; i < pos - 1; ++i) prev = prev->next;
        prev->next = new Node<T>(e, prev->next);
        ++n;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("get");
        Node<T>* cur = first;
        for (int i = 0; i < pos; ++i) cur = cur->next;
        return cur->data;
    }

    int search(T e) override {
        Node<T>* cur = first;
        int i = 0;
        while (cur) {
            if (cur->data == e) return i;
            cur = cur->next;
            ++i;
        }
        return -1;
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("remove");
        Node<T>* del;
        if (pos == 0) {
            del = first;
            first = first->next;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; ++i) prev = prev->next;
            del = prev->next;
            prev->next = del->next;
        }
        T val = del->data;
        delete del;
        --n;
        return val;
    }
};

#endif

