#ifndef ITEM_H
#define ITEM_H

#include <memory>
#include <iostream>

using std::shared_ptr;
using std::make_shared;

template <class T>
class TreeElem{
public:
    TreeElem();
    TreeElem(T rhombus);

    T& get_rhombus();
    int get_count();
    shared_ptr<TreeElem<T>> get_left() ;
    shared_ptr<TreeElem<T>> get_right();

    void set_rhombus(T& rhombus);
    void set_count(int count);
    void set_left(shared_ptr<TreeElem<T>> to_left);
    void set_right(shared_ptr<TreeElem<T>> to_right);

    virtual ~TreeElem();
private:
    shared_ptr<T> r;
    int count;
    shared_ptr<TreeElem<T>> left;
    shared_ptr<TreeElem<T>> right;
};



#endif 