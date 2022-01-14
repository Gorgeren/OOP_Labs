#include "tbinarytreeitem.h"
#include <memory>


TreeItem::TreeItem() {
    r;
    count = 0;
    left = nullptr;
    right = nullptr;
}

TreeItem::TreeItem(Rhombus rhombus) {
    r = rhombus;
    count = 1;
    left = nullptr;
    right = nullptr;
}

Rhombus& TreeItem::get_rhombus() {
    return r;
}
int TreeItem::get_count() {
    return count;
}
TreeItem* TreeItem::get_left() {
    return left;
}
TreeItem* TreeItem::get_right() {
    return right;
}

void TreeItem::set_rhombus(Rhombus& rhombus) {
    r = rhombus;
}
void TreeItem::set_count(int count_) {
    count = count_;
}
void TreeItem::set_left(TreeItem* to_left) {
    left = to_left;
}
void TreeItem::set_right(TreeItem* to_right) {
    right = to_right;
}

TreeItem::~TreeItem() {
}