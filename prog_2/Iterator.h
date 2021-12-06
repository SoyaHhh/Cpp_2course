#ifndef PROG_2_ITERATOR_H
#define PROG_2_ITERATOR_H

#include "RingBuffer.h"

template<typename T1>
class Iterator {
private:
    RingBuffer<T1> *ringBuffer;
    unsigned index;
public:
    explicit Iterator(RingBuffer<T1> ringBuffer);
    void start();
    void next();
    bool finish();
    T1 getValue();
};


#endif //PROG_2_ITERATOR_H
