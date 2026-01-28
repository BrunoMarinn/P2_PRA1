#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V>
class TableEntry {
public:
    std::string key;
    V value;

    TableEntry(std::string key, V value) : key(key), value(value) {}
    TableEntry(std::string key) : key(key), value() {}
    TableEntry() : key(""), value() {}

    template <typename W>
    friend bool operator==(const TableEntry<W>& e1, const TableEntry<W>& e2);

    template <typename W>
    friend bool operator!=(const TableEntry<W>& e1, const TableEntry<W>& e2);

    template <typename W>
    friend bool operator<(const TableEntry<W>& e1, const TableEntry<W>& e2);

    template <typename W>
    friend bool operator>(const TableEntry<W>& e1, const TableEntry<W>& e2);

    template <typename W>
    friend std::ostream& operator<<(std::ostream& out, const TableEntry<W>& e);
};

template <typename W>
bool operator==(const TableEntry<W>& e1, const TableEntry<W>& e2) {
    return e1.key == e2.key;
}

template <typename W>
bool operator!=(const TableEntry<W>& e1, const TableEntry<W>& e2) {
    return !(e1 == e2);
}

template <typename W>
bool operator<(const TableEntry<W>& e1, const TableEntry<W>& e2) {
    return e1.key < e2.key;
}

template <typename W>
bool operator>(const TableEntry<W>& e1, const TableEntry<W>& e2) {
    return e1.key > e2.key;
}

template <typename W>
std::ostream& operator<<(std::ostream& out, const TableEntry<W>& e) {
    out << e.key << "->" << e.value;
    return out;
}

#endif

