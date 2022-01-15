#include "tbinarytreeitem.h"
#include <memory>


TreeItem::TreeItem() {
    r;
    count = 0;
    left = nullptr;
    right = nullptr;
}

TreeItem::TreeItem(shared_ptr<Rhombus> rhombus) {
    r = rhombus;
    count = 1;
    left = nullptr;
    right = nullptr;
}

shared_ptr<Rhombus> TreeItem::get_rhombus() {
    return r;
}
int TreeItem::get_count() {
    return count;
}
shared_ptr<TreeItem>TreeItem::get_left() {
    return left;
}
shared_ptr<TreeItem>TreeItem::get_right() {
    return right;
}

void TreeItem::set_rhombus(shared_ptr<Rhombus> rhombus) {
    r = rhombus;
}
void TreeItem::set_count(int count_) {
    count = count_;
}
void TreeItem::set_left(shared_ptr<TreeItem> to_left) {
    left = to_left;
}
void TreeItem::set_right(shared_ptr<TreeItem> to_right) {
    right = to_right;
}

TreeItem::~TreeItem() {
}