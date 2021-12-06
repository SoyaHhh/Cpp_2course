#include <iostream>
#include "RingBuffer.h"
#include "RingBuffer.cpp"
#include "Iterator.h"
#include "Iterator.cpp"

using namespace std;

int main() {

    RingBuffer<int> a(5);
    a.push(3);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    //a.clear();
    cout << a.seeHead() << endl; //голова
    cout << a.getBufferSize() << endl; //размер буфера
    cout << a.pop() << endl; //забрали первый элемент
    //a.clear();
    Iterator<int> iterator(a);
    iterator.start();
    cout << iterator.getValue()<< endl; //начали со 2 элемента
    iterator.next(); //прыжок
    iterator.next();
    iterator.next();
    cout << iterator.getValue() << endl;
    cout << iterator.finish() << endl; //1 или 0 (прошли очередь или нет)

    return 0;
}
