#include <iostream>
#include "TableEntry.h"

int main() {
    TableEntry<int> a("uno", 1);
    TableEntry<int> b("uno", 999);
    TableEntry<int> c("dos", 2);

    std::cout << a << std::endl;
    std::cout << (a == b) << std::endl;
    std::cout << (a != c) << std::endl;
    std::cout << (a < c) << std::endl;
    std::cout << (c > a) << std::endl;

    return 0;
}

