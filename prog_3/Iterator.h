#ifndef LAB3_ITERATOR_H
#define LAB3_ITERATOR_H

template <typename U>
struct Node{
    U data;
    Node* next;
    Node* prev;
};

template <typename T>
class Iterator{
public:
    virtual T operator*() = 0;
    virtual Iterator& operator++() = 0;
    virtual Iterator& operator--() = 0;
    virtual bool hasNext() = 0;
    virtual Node<T>* getCurrent() = 0;
    virtual void setCurrent(Node<T>* node) = 0;
};

#endif //LAB3_ITERATOR_H
