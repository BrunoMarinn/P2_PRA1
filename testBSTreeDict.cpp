#include <iostream>
#include "BSTreeDict.h"

int main() {
    BSTreeDict<int> d;

    d.insert("ana", 10);
    d.insert("luis", 20);
    d.insert("pepe", 30);

    std::cout << "entries=" << d.entries() << std::endl;
    std::cout << "search ana=" << d.search("ana") << std::endl;
    std::cout << "remove pepe=" << d.remove("pepe") << std::endl;
    std::cout << "entries=" << d.entries() << std::endl;

    return 0;
}

