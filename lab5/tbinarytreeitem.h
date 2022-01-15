#ifndef ITEM_H
#define ITEM_H
#include "rhombus.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;

class TreeItem {
public:
    TreeItem();
    TreeItem(shared_ptr<Rhombus> rhombus);

    shared_ptr<Rhombus> get_rhombus();
    int get_count();
    shared_ptr<TreeItem> get_left();
    shared_ptr<TreeItem> get_right();

    void set_rhombus(shared_ptr<Rhombus> rhombus);
    void set_count(int count);
    void set_left( shared_ptr<TreeItem> to_left);
    void set_right(shared_ptr<TreeItem> to_right);

    virtual ~TreeItem();
private:
    shared_ptr<Rhombus> r;
    int count;
    shared_ptr<TreeItem> left;
    shared_ptr<TreeItem> right;
};



#endif 