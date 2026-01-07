V search(std::string key) override {
    TableEntry<V> probe(key);
    TableEntry<V> found = tree->get(probe);
    return found.value;
}

V remove(std::string key) override {
    TableEntry<V> probe(key);
    TableEntry<V> found = tree->get(probe);
    tree->remove(probe);
    return found.value;
}

