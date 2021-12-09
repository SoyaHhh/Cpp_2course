#ifndef LAB3_LINKEDLIST_H
#define LAB3_LINKEDLIST_H

#include <exception>
#include "LinkedList.h"
#include "IList.h"

using namespace std;

template<typename U>
LinkedList<U>::LinkedList(): head(nullptr), len(0) {}

template<typename U>
void LinkedList<U>::addElem(U elem) {
    auto cell = new Node<U>;
    cell -> data = elem;
    if(head == nullptr){
        head = cell;
        head -> next = head;
        head -> prev = head;
    }
    else{
        cell -> next = head -> next;
        head -> next -> prev = cell;
        head -> next = cell;
        cell -> prev = head;
    }
    len++;
}

template<typename U>
bool LinkedList<U>::empty() {
    return head == nullptr;
}

template<typename U>
unsigned LinkedList<U>::size() {
    return len;
}

template<typename U>
LinkedList<U>::listIterator::listIterator(): current(nullptr), list(nullptr){}

template<typename U>
LinkedList<U>::listIterator::listIterator(LinkedList<U> &obj){
    if(obj.head != nullptr){
        current = obj.head;
        list = (&obj);
    }
}

template<typename U>
U LinkedList<U>::listIterator::operator*() {
    return current->data;
}

template<typename U>
LinkedList<U>::listIterator::listIterator(LinkedList<U> &obj, PNode &node) {
    current = node;
    list = (&obj);
}


template<typename U>
typename LinkedList<U>::listIterator LinkedList<U>::listIterator::operator++(int) {
    auto old = (*this);
    ++(*this);
    return old;
}

template<typename U>
typename LinkedList<U>::listIterator &LinkedList<U>::listIterator::operator--() {
    if(current -> prev == list->head->prev){
        current = nullptr;
    }
    else{
        current = current -> prev;
    }
    return (*this);
}

template<typename U>
typename LinkedList<U>::listIterator LinkedList<U>::listIterator::operator--(int) {
    auto old = (*this);
    --(*this);
    return old;
}

template<typename U>
bool LinkedList<U>::listIterator::hasNext() {
    return current->next != list->head;
}

template<typename U>
typename LinkedList<U>::listIterator &LinkedList<U>::listIterator::operator++() {
    current -> next == list -> head ? current = nullptr : current = current -> next;
    return (*this);
}

template<typename U>
typename LinkedList<U>::PNode LinkedList<U>::listIterator::getCurrent() {
    return current;
}

template<typename U>
void LinkedList<U>::listIterator::setCurrent(Node<U> *node) {
    current = node;
}

template<typename U>
bool LinkedList<U>::listIterator::operator==(const LinkedList::listIterator &it) const {
    if(current == nullptr && it.current == nullptr){
        return true;
    }
    else if(current == nullptr || it.current == nullptr || it.list == nullptr || list == nullptr){
        return false;
    }
    else{
        return current == it.current && list && it.list;
    }
}

template<typename U>
bool LinkedList<U>::listIterator::operator!=(const LinkedList::listIterator &it) const {
    return !(*this == it);
}

template<typename U>
LinkedList<U>::listIterator::~listIterator() {
    list = nullptr;
    current = nullptr;
    delete list;
    delete current;
}

template<typename U>
void LinkedList<U>::addElem(U elem, Iterator<U> &it) {
    auto cell = new Node<U>;
    cell -> data = elem;
    cell -> next = it.getCurrent()->next;
    cell -> prev = it.getCurrent()->prev;
    it.getCurrent()->next->prev = cell;
    it.getCurrent()->next = cell;
    len++;
}

template<typename U>
void LinkedList<U>::deleteElem(Iterator<U> &it) {
    PNode tempNode = it.getCurrent();
    if(it.getCurrent() -> next != it.getCurrent()) {
        it.getCurrent()->next->prev = it.getCurrent()->prev;
        it.getCurrent()->prev->next = it.getCurrent()->next;
        it.setCurrent(tempNode->next);
    }
    len--;
    delete tempNode;
}

template<typename U>
typename LinkedList<U>::listIterator LinkedList<U>::searchElem(U elem) {
    if(empty()){
        throw exception();
    }
    PNode temp = head;
    do{
        if(temp->data == elem){
            return listIterator(*this, temp);
        }
        temp = temp -> next;
    }while (temp != head);
    throw exception();
}

template<typename U>
void LinkedList<U>::clear() {
    PNode it = head->next;
    while(it != head){
        PNode old = it;
        it = it -> next;
        delete old;
    }
    head = nullptr;
    len = 0;
}

template<typename U>
LinkedList<U>::~LinkedList() {
    if(!empty()){
        clear();
        delete head;
    }

}

template<typename U>
LinkedList<U>::LinkedList(const LinkedList &obj) {
    head = new Node<U>;
    head->data = obj.head->data;
    PNode it = head;
    PNode oldIterator = obj.head->next;
    while(oldIterator != obj.head) {
        auto temp = new Node<U>;
        it->next = temp;
        temp->prev = it;
        temp->data = oldIterator->data;
        it = it -> next;
        oldIterator = oldIterator -> next;
    }
    head -> prev = it;
    it -> next = head;
    len = obj.len;
}

template<typename U>
LinkedList<U>::LinkedList(LinkedList &&obj) noexcept: head(obj.head), len(obj.len) {
    obj.head = nullptr;
    obj.len = 0;
}

template<typename U>
LinkedList<U> &LinkedList<U>::operator=(const LinkedList<U> &obj) {
    if(*this == obj){
        delete head;
        head = new Node<U>;
        head->data = obj.head->data;
        PNode it = head;
        PNode oldIterator = obj.head->next;
        while(oldIterator != obj.head) {
            auto temp = new Node<U>;
            it->next = temp;
            temp->prev = it;
            temp->data = oldIterator->data;
            it = it -> next;
            oldIterator = oldIterator -> next;
        }
        head -> prev = it;
        it -> next = head;
        len = obj.len;
    }
    return (*this);
}

template<typename U>
LinkedList<U> &LinkedList<U>::operator=(LinkedList &&obj) noexcept {
    if(*this != obj){
        delete head;
        head = obj.head;
        len = obj.len;
        obj.head = nullptr;
        obj.len = 0;
    }
    return (*this);
}


#endif //LAB3_LINKEDLIST_H
