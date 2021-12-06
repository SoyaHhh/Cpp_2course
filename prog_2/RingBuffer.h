#ifndef PROG_2_RINGBUFFER_H
#define PROG_2_RINGBUFFER_H
using namespace std;

template<typename T>
class RingBuffer {
    unsigned readIndex; //количество которое мы считали
    unsigned writeIndex; //количество которое мы записали
    bool isEmpty;
    unsigned bufferSize;
    T *buffer;
public:
    RingBuffer();
    explicit RingBuffer(unsigned size);
    void push(T x);
    T pop();
    T seeHead();
    unsigned getBufferSize();
    void clear();
    bool checkEmpty();
    ~RingBuffer();
    template <typename T1> friend class Iterator;
    RingBuffer(const RingBuffer<T> &obj);
    RingBuffer& operator=(const RingBuffer<T> &obj);

};

#endif //PROG_2_RINGBUFFER_H
