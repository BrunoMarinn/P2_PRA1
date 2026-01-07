#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}
};

#endif

