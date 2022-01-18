#include "tbinarytreeitem.h"
#include <memory>


template <class T>
TreeElem<T>::TreeElem() {
    r = nullptr;
    count = 0;
    left = nullptr;
    right = nullptr;
}

template <class T>
TreeElem<T>::TreeElem(T rhombus) {
    r = make_shared<T>(rhombus);
    count = 1;
    left = nullptr;
    right = nullptr;
}

template <class T>
 T& TreeElem<T>::get_rhombus() {
    return *r;
}
template <class T>
int TreeElem<T>::get_count() {
    return count;
}
template <class T>
shared_ptr<TreeElem<T>> TreeElem<T>::get_left() {
    return left;
}
template <class T>
shared_ptr<TreeElem<T>> TreeElem<T>::get_right() {
    return right;
}

template <class T>
void TreeElem<T>::set_rhombus( T& rhombus){
    r = make_shared<T>(rhombus);
}
template <class T>
void TreeElem<T>::set_count( int count_) {
    count = count_;
}
template <class T>
void TreeElem<T>::set_left(shared_ptr<TreeElem<T>> to_left) {
    left = to_left;
}
template <class T>
void TreeElem<T>::set_right(shared_ptr<TreeElem<T>> to_right) {
    right = to_right;
}

template <class T>
TreeElem<T>::~TreeElem() {
}

#include "rhombus.h"
template class TreeElem<Rhombus>;