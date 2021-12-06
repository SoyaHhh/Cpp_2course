#include "Iterator.h"
#include "exception"

using namespace std;

template<typename T1>
Iterator<T1>::Iterator(RingBuffer<T1> sRingBuffer) { //создание нового буфера на основе старого
    if (sRingBuffer.checkEmpty())
        throw exception();

    ringBuffer = new RingBuffer(sRingBuffer);
    index = sRingBuffer.readIndex;
}

template<typename T1>
void Iterator<T1>::start() {
    index = ringBuffer->readIndex;
}

template<typename T1>
void Iterator<T1>::next() {
    if (this->finish())
        throw exception();
    index = (index + 1) % ringBuffer->bufferSize; //увеличение прыжок на след индекс
}

template<typename T1>
bool Iterator<T1>::finish() {
    return index == (ringBuffer->writeIndex % ringBuffer->bufferSize); //если считываемый индекс равен размеру буфера то финиш
}

template<typename T1>
T1 Iterator<T1>::getValue() {
    return ringBuffer->buffer[index];
}
