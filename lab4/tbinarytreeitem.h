#ifndef ITEM_H
#define ITEM_H
#include "rhombus.h"
#include <memory>

class TreeItem {
public:
    TreeItem();
    TreeItem(Rhombus rhombus);

    Rhombus& get_rhombus();
    int get_count();
    TreeItem* get_left();
    TreeItem* get_right();

    void set_rhombus(Rhombus& rhombus);
    void set_count( int count);
    void set_left(TreeItem* to_left);
    void set_right(TreeItem* to_right);

    virtual ~TreeItem();
private:
    Rhombus r;
    int count;
    TreeItem* left;
    TreeItem* right;
};



#endif 