#include "HashTable.h"

HashTable::HashTable() : tableSize(10) {
    pEntry = new Entry *[tableSize];
    clear();
}

HashTable::HashTable(unsigned int tableSize) : tableSize(tableSize) {
    pEntry = new Entry *[tableSize];
    clear();
}

int HashTable::hashFunction(int k) const {
    return k % tableSize;
}

void HashTable::add(int k, int v) {
    int h = hashFunction(k);
    while (pEntry[h] != nullptr && pEntry[h]->key != k) {
        h = hashFunction(h + 1);
    }
    if (pEntry[h] != nullptr) {
        delete pEntry[h];
        pEntry[h] = nullptr;
    }
    pEntry[h] = new Entry(k, v);
}

void HashTable::remove(int k) {
    int h = hashFunction(k);
    while (pEntry[h] != nullptr) {
        if (pEntry[h]->key == k)
            break;
        h = hashFunction(h + 1);
    }
    if (pEntry[h] == nullptr) {
        return;
    } else {
        delete pEntry[h];
    }
}

int HashTable::searchKey(int k) {
    int h = hashFunction(k);
    while (pEntry[h] != nullptr && pEntry[h]->key != k) {
        h = hashFunction(h + 1);
    }
    if (pEntry[h] == nullptr)
        return -1;
    else
        return pEntry[h]->value;
}

void HashTable::clear() {
    for (int i = 0; i < tableSize; i++) {
        pEntry[i] = nullptr;
    }
}

bool HashTable::isEmpty() {
    for (int i = 0; i < tableSize; i++) {
        if (pEntry[i] != nullptr) {
            return false;
        }
    }
    return true;
}

HashTable::Iterator &HashTable::Iterator::operator++() {

    id++;
    if (ptr[id] == nullptr) {
        while (ptr[id] == nullptr && id < tableSize - 1) {
            id++;
        }
    }


    return *this;
}

HashTable::Iterator HashTable::begin() {
    return Iterator(*this);
}

HashTable::Iterator HashTable::end() {
    return Iterator(*this, tableSize - 1);
}

int HashTable::Iterator::operator*() {
    if (ptr[id] != nullptr) {
        return ptr[id]->value;
    }
}

bool HashTable::Iterator::operator==(const HashTable::Iterator &other) const {
    return this->ptr == other.ptr && this->id == other.id;
}

HashTable::Iterator &HashTable::Iterator::operator=(const HashTable::Iterator &copy) {
    if (this != &copy) {
        this->ptr = copy.ptr;
        this->id = copy.id;
    }
    return *this;
}
