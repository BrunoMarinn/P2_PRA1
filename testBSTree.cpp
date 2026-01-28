#include <iostream>
#include "BSTree.h"

int main() {
    BSTree<int> t;

    t.insert(10);
    t.insert(5);
    t.insert(20);
    t.insert(7);

    std::cout << "size=" << t.size() << std::endl;
    std::cout << "search 7=" << t.search(7) << std::endl;

    t.remove(10);
    std::cout << "size=" << t.size() << std::endl;

    return 0;
}

