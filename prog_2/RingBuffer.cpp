#include "exception"
#include "RingBuffer.h"

using namespace std;

template<typename T>
RingBuffer<T>::RingBuffer(): buffer(new T[10]), writeIndex(0), readIndex(0), bufferSize(10), isEmpty(true) {}

template<typename T>
RingBuffer<T>::RingBuffer(unsigned size) {
    if (size == 0) {
        throw exception();
    }
    buffer = new T[size];
    readIndex = 0;
    writeIndex = 0;
    isEmpty = true;
    bufferSize = size;
}

template<typename T>
void RingBuffer<T>::push(T x) {
    if ((writeIndex + 1) % bufferSize == readIndex) //проверка на переполненность
        throw exception();
    if (isEmpty) {
        isEmpty = false;
    } else {
        writeIndex = (writeIndex + 1) % bufferSize; //увеличение
    }
    buffer[writeIndex] = x;
}

template<typename T>
T RingBuffer<T>::pop() {
    if (isEmpty)
        throw exception();

    T res = buffer[readIndex];

    if (writeIndex == readIndex) {
        isEmpty = true;
    } else {
        readIndex = (readIndex + 1) % bufferSize;
    }
    return res;
}

template<typename T>
T RingBuffer<T>::seeHead() {
    if (isEmpty)
        throw exception();
    return buffer[readIndex];
}

template<typename T>
unsigned RingBuffer<T>::getBufferSize() {
    return bufferSize;
}

template<typename T>
void RingBuffer<T>::clear() {
    isEmpty = true;
    writeIndex = 0;
    readIndex = 0;
}

template<typename T>
bool RingBuffer<T>::checkEmpty() {
    return isEmpty;
}

template<typename T>
RingBuffer<T>::~RingBuffer() {
    delete[] buffer;
}

template<typename T>
RingBuffer<T>::RingBuffer(const RingBuffer<T> &obj): buffer(new T[obj.bufferSize]),
                                                     bufferSize(obj.bufferSize),
                                                     readIndex(obj.readIndex), writeIndex(obj.writeIndex),
                                                     isEmpty(obj.isEmpty) {
    for (unsigned i = 0; i <= writeIndex; i++) {
        this->buffer[i] = obj.buffer[i];
    }
}

template<typename T>
RingBuffer<T> &RingBuffer<T>::operator=(const RingBuffer<T> &obj) {
    if (&obj == this) {
        return *this;
    }
    delete buffer;

    bufferSize = obj.bufferSize;
    isEmpty = obj.isEmpty;
    readIndex = obj.readIndex;
    writeIndex = obj.writeIndex;
    buffer = new T[obj.bufferSize];

    return *this;
}