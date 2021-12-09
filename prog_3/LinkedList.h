#ifndef PROG_03_LINKEDLIST_H
#define PROG_03_LINKEDLIST_H

#include "IList.h"
#include "Iterator.h"

using namespace std;

template <typename U>
class LinkedList: public IList<U>{
public:
    //Самые важные методы
    using PNode = Node<U>*; //указатель на узел
    LinkedList();
    void addElem(U elem);
    bool empty();
    unsigned size();
    void clear();
    LinkedList(const LinkedList &obj);
    LinkedList(LinkedList &&obj) noexcept ;
    LinkedList& operator=(const LinkedList<U> &obj);
    LinkedList& operator=(LinkedList &&obj) noexcept;
    ~LinkedList();
    //Итератор
    class listIterator : public Iterator<U>{
    public:
        listIterator();
        explicit listIterator(LinkedList<U> &obj);
        listIterator(LinkedList<U> &obj, PNode &node);
        U operator*();
        listIterator& operator++();
        listIterator operator++(int);
        listIterator& operator--();
        listIterator operator--(int);
        bool operator==(const listIterator &it) const;
        bool operator!=(const listIterator &it) const;
        PNode getCurrent();
        void setCurrent(Node<U>* node);
        bool hasNext();
        ~listIterator();
        friend class LinkedList<U>;
    private:
        PNode current; //текущий узел
        LinkedList<U> *list;
    };
    void addElem(U elem, Iterator<U> &it);
    void deleteElem(Iterator<U> &it);
    listIterator searchElem(U elem);
    listIterator begin(){return listIterator(*this);};
    listIterator end(){return listIterator();};
private:
    PNode head;
    unsigned len;

};

#endif //PROG_03_LINKEDLIST_H
