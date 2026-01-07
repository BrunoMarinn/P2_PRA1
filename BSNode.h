#ifndef BSNODE_H
#define BSNODE_H

template <class T>
class BSNode {
public:
    T elem;
    BSNode<T>* left;
    BSNode<T>* right;

    BSNode(T elem,
           BSNode<T>* left = nullptr,
           BSNode<T>* right = nullptr)
        : elem(elem), left(left), right(right) {}
};

#endif

