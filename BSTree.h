T get(const T& e) const {
    BSNode<T>* cur = root;
    while (cur) {
        if (e < cur->elem) cur = cur->left;
        else if (e > cur->elem) cur = cur->right;
        else return cur->elem;
    }
    throw std::runtime_error("element not found");
}

