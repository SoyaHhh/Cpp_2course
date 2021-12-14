#include <iostream>
#include "HashTable.h"

int main() {
    HashTable p;
    p.add(10, 14);
    p.add(88, 66);
    p.add(43, 92);
    p.add(0, 321321);
    p.add(111, 222);

    cout << p.searchKey(111) << endl;
    cout << p.searchKey(0) << endl;

    p.remove(111);
    cout << p.searchKey(111) << endl;

    for (auto it = p.begin(); it != p.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}
