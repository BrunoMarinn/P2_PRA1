#ifndef BSTREE_H
#define BSTREE_H

#include <stdexcept>
#include "BSNode.h"

template <class T>
class BSTree {
private:
    BSNode<T>* root;

    void destroy(BSNode<T>* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    void insert(BSNode<T>*& node, const T& e) {
        if (!node) {
            node = new BSNode<T>(e);
        } else if (e < node->elem) {
            insert(node->left, e);
        } else if (e > node->elem) {
            insert(node->right, e);
        }
    }

    bool search(BSNode<T>* node, const T& e) const {
        if (!node) return false;
        if (e == node->elem) return true;
        if (e < node->elem) return search(node->left, e);
        return search(node->right, e);
    }

    BSNode<T>* remove(BSNode<T>* node, const T& e) {
        if (!node) return nullptr;

        if (e < node->elem) {
            node->left = remove(node->left, e);
        } else if (e > node->elem) {
            node->right = remove(node->right, e);
        } else {
            if (!node->left) {
                BSNode<T>* r = node->right;
                delete node;
                return r;
            }
            if (!node->right) {
                BSNode<T>* l = node->left;
                delete node;
                return l;
            }
            BSNode<T>* min = node->right;
            while (min->left) min = min->left;
            node->elem = min->elem;
            node->right = remove(node->right, min->elem);
        }
        return node;
    }

public:
    BSTree() : root(nullptr) {}
    ~BSTree() { destroy(root); }

    void insert(const T& e) { insert(root, e); }

    bool search(const T& e) const { return search(root, e); }

    void remove(const T& e) { root = remove(root, e); }

    T get(const T& e) const {
        BSNode<T>* cur = root;
        while (cur) {
            if (e == cur->elem) return cur->elem;
            if (e < cur->elem) cur = cur->left;
            else cur = cur->right;
        }
        throw std::runtime_error("not found");
    }
};

#endif

