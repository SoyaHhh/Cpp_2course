#ifndef LAB3_ILIST_H
#define LAB3_ILIST_H

#include "Iterator.h"

template <typename T>
class IList{
public:
    virtual void addElem(T elem, Iterator<T> &it) = 0;
    virtual void deleteElem(Iterator<T> &it) = 0;
    virtual void clear() = 0;
    virtual bool empty() = 0;
    virtual unsigned size() = 0;
};

#endif //LAB3_ILIST_H
