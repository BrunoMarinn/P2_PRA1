#include <iostream>
#include "HashTable.h"

int main() {
    HashTable<int> d(7);

    d.insert("ana", 10);
    d.insert("luis", 20);
    d.insert("pepe", 30);

    std::cout << "entries=" << d.entries() << std::endl;
    std::cout << "search ana=" << d.search("ana") << std::endl;
    std::cout << "op[] luis=" << d["luis"] << std::endl;

    std::cout << "remove pepe=" << d.remove("pepe") << std::endl;
    std::cout << "entries=" << d.entries() << std::endl;

    return 0;
}

