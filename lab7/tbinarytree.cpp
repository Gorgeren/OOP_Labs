#include "tbinarytree.h"


template <class T>
TBinaryTree<T>::TBinaryTree() {
    root = nullptr;
}

template <class T>
void TBinaryTree<T>::Push( T& rhombus) {
    shared_ptr<TreeElem<T>> curr = root;
    shared_ptr<TreeElem<T>> rootptr = make_shared<TreeElem<T>> (rhombus);

    if (!curr)
    {
        root = rootptr;
    }
    while (curr)
    {
        if (curr->get_rhombus() == rhombus)
        {
            curr->set_count(curr->get_count() + 1);
            return;
        }
        if (rhombus.Area() < curr->get_rhombus().Area())
            if (curr->get_left() == nullptr)
            {
                curr->set_left(rootptr);
                return;
            }
        if (rhombus.Area() >= curr->get_rhombus().Area())
            if (curr->get_right() == nullptr && !(curr->get_rhombus() == rhombus))
            {
                curr->set_right(rootptr);
                return;
            }
        if (curr->get_rhombus().Area() > rhombus.Area())
            curr = curr->get_left();
        else
            curr = curr->get_right();
    }
}

template <class T>
T& TBinaryTree<T>::GetItemNotLess(double area) {
    shared_ptr<TreeElem<T>> curr = root;
    while (curr)
    {
        if (area == curr->get_rhombus().Area())
            return curr->get_rhombus();
        if (area < curr->get_rhombus().Area())
        {
            curr = curr->get_left();
            continue;
        }
        if (area >= curr->get_rhombus().Area())
        {
            curr = curr->get_right();
            continue;
        }
    }
    throw std::out_of_range("out of range");
}

template <class T>
size_t TBinaryTree<T>::Count( T& rhombus) {
    size_t count = 0;
    shared_ptr<TreeElem<T>> curr = root;

    while (curr)
    {
        if (curr->get_rhombus() == rhombus)
            count = curr->get_count();
        if (rhombus.Area() < curr->get_rhombus().Area())
        {
            curr = curr->get_left();
            continue;
        }
        if (rhombus.Area() >= curr->get_rhombus().Area())
        {
            curr = curr->get_right();
            continue;
        }
    }
    return count;
}

template <class T>
void Pop_List(shared_ptr<TreeElem<T>> curr, shared_ptr<TreeElem<T>> parent) {
    if (parent->get_left() == curr)
        parent->set_left(nullptr);
    else
        parent->set_right(nullptr);
}
template <class T>
void Pop_Part_of_Branch(shared_ptr<TreeElem<T>> curr, shared_ptr<TreeElem<T>> parent) {
    if (parent) {
        if (curr->get_left()) {
            if (parent->get_left() == curr)
                parent->set_left(curr->get_left());

            if (parent->get_right() == curr)
                parent->set_right(curr->get_left());

            curr->set_right(nullptr);
            curr->set_left(nullptr);
            return;
        }

        if (curr->get_left() == nullptr) {
            if (parent && parent->get_left() == curr)
                parent->set_left(curr->get_right());

            if (parent && parent->get_right() == curr)
                parent->set_right(curr->get_right());

            curr->set_right(nullptr);
            curr->set_left(nullptr);
            return;
        }
    }
}
template <class T>
void Pop_Root_of_Subtree(shared_ptr<TreeElem<T>> curr, shared_ptr<TreeElem<T>> parent) {
    shared_ptr<TreeElem<T>> replace = curr->get_left();
    shared_ptr<TreeElem<T>> rep_parent = curr;
    while (replace->get_right())
    {
        rep_parent = replace;
        replace = replace->get_right();
    }

    curr->set_rhombus(replace->get_rhombus());
    curr->set_count(replace->get_count());

    if (rep_parent->get_left() == replace)
        rep_parent->set_left(nullptr);
    else
        rep_parent->set_right(nullptr);
    return;
}
template <class T>
void TBinaryTree<T>::Pop( T& rhombus) {

    shared_ptr<TreeElem<T>> curr = root;
    shared_ptr<TreeElem<T>> parent = nullptr;

    while (curr && curr->get_rhombus() != rhombus)
    {
        parent = curr;
        if (curr->get_rhombus().Area() > rhombus.Area())
            curr = curr->get_left();
        else
            curr = curr->get_right();
    }

    if (curr == nullptr)
        return;

    curr->set_count(curr->get_count() - 1);

    if(curr->get_count() <= 0)
    {
        if (curr->get_left() == nullptr && curr->get_right() == nullptr)
        {
            Pop_List(curr, parent);
            return;
        }
        if (curr->get_left() == nullptr || curr->get_right() == nullptr)
        {
            Pop_Part_of_Branch(curr, parent);
            return;
        }
        if (curr->get_left() != nullptr && curr->get_right() != nullptr)
        {
            Pop_Root_of_Subtree(curr, parent);
            return;
        }
    }
}

template <class T>
bool TBinaryTree<T>::Empty() {
    return root == nullptr ? true : false;
}

template <class T>
void Tree_out (std::ostream& os, shared_ptr<TreeElem<T>> curr) {
    if (curr)
    {
        if(curr->get_rhombus().Area() >= 0)
            os << curr->get_count() << "*" << curr->get_rhombus().Area();
        if(curr->get_left() || curr->get_right())
        {
            os << ": [";
            if (curr->get_left())
                Tree_out(os, curr->get_left());
            if(curr->get_left() && curr->get_right())
                os << ", ";
            if (curr->get_right())
                Tree_out(os, curr->get_right());
            os << "]";
        }
    }
}
template <class A>
std::ostream& operator<<(std::ostream& os, const TBinaryTree<A>& tree) {
    shared_ptr<TreeElem<A>> curr = tree.root;
    Tree_out(os, curr);
    return os;
}

template <class T>
void recursive_clear(shared_ptr<TreeElem<T>> curr){
    if(curr)
    {
        if (curr->get_left())
            recursive_clear(curr->get_left());
        curr->set_left(nullptr);
        if (curr->get_right())
            recursive_clear(curr->get_right());
        curr->set_right(nullptr);
    }
}
template <class T>
void TBinaryTree<T>::Clear() {
    if (root->get_left())
        recursive_clear(root->get_left());
    root->set_left(nullptr);
    if (root->get_right())
        recursive_clear(root->get_right());
    root->set_right(nullptr);
    root = nullptr;
}

template <class T>
TBinaryTree<T>::~TBinaryTree() {
}

#include "rhombus.h"
template class TBinaryTree<Rhombus>;
template std::ostream& operator<<(std::ostream& os, const TBinaryTree<Rhombus>& rhombus);