#ifndef TITERATOR_H
#define TITERATOR_H
#include <iostream>
#include <memory>

template <class T, class A>
class TIterator {
public:
TIterator(std::shared_ptr<T> iter) {
    ptr = iter;
}
A& operator*() {
    return ptr->get_rhombus();
}

void GoLeft() { 
    if (ptr == NULL) {
        std:: cout << "Root does not exist" << std:: endl;
    }
    else {
        ptr = ptr->get_left();
    }
}
void GoRight() { 
    if (ptr == NULL) {
        std:: cout << "Root does not exist" << std:: endl;
    }
    else {
        ptr = ptr->get_right();
    }
}
bool operator == (TIterator &iterator) {
    return ptr == iterator.ptr;
}
bool operator != (TIterator &iterator) {
    return !(*this == iterator);
}

private:
    std::shared_ptr<T> ptr;
};
#endif