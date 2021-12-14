#ifndef PROG_04_HASHTABLE_H
#define PROG_04_HASHTABLE_H

#include "list"

using namespace std;

class HashTable {
    class Entry {
    public:
        int key;
        int value;

        Entry(int key, int value) {
            this->key = key;
            this->value = value;
        }
    };

    class Iterator {
    public:
        explicit Iterator(HashTable &ptr) : tableSize(ptr.tableSize), ptr((ptr.pEntry)), id(0) {};

        Iterator(HashTable &ptr, int id) : tableSize(ptr.tableSize), ptr((ptr.pEntry)), id(id) {};

        Iterator &operator++();

        int operator*();

        bool operator==(const Iterator &other) const;

        bool operator!=(const Iterator &other) const {
            return !(other == *this);
        };

        Iterator &operator=(const Iterator &copy);

    private:
        const unsigned int tableSize;
        unsigned id;
        Entry **ptr;
    };

    Entry **pEntry;
    const unsigned int tableSize;

public:
    HashTable();

    HashTable(unsigned int tableSize);


    int hashFunction(int k) const;

    void add(int k, int v);

    void remove(int k);

    int searchKey(int k);

    void clear();

    bool isEmpty();

    Iterator begin();

    Iterator end();
};

#endif //PROG_04_HASHTABLE_H
