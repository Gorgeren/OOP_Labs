#include "tbinarytree.h"


TBinaryTree::TBinaryTree() {
    root = nullptr;
}

void TBinaryTree::Push(shared_ptr<Rhombus> rhombus) {
    shared_ptr<TreeItem> curr = root;

    if (curr == nullptr)
        root = make_shared<TreeItem>(rhombus);

    while (curr)
    {
        if (curr->get_rhombus() == rhombus)
        {
            curr->set_count(curr->get_count() + 1);
            return;
        }
        if (rhombus->Area() < curr->get_rhombus()->Area())
            if (curr->get_left() == nullptr)
            {
                curr->set_left(make_shared<TreeItem>(rhombus));
                return;
            }
        if (rhombus->Area() >= curr->get_rhombus()->Area())
            if (curr->get_right() == nullptr && !(curr->get_rhombus() == rhombus))
            {
                curr->set_right(make_shared<TreeItem>(rhombus));
                return;
            }
        if (curr->get_rhombus()->Area() > rhombus->Area())
            curr = curr->get_left();
        else
            curr = curr->get_right();
    }
}

const shared_ptr<Rhombus> TBinaryTree::GetItemNotLess(double area) {
    shared_ptr<TreeItem> curr = root;

    while (curr)
    {
        if (area == curr->get_rhombus()->Area())
            return curr->get_rhombus();
        if (area < curr->get_rhombus()->Area())
        {
            curr = curr->get_left();
            continue;
        }
        if (area >= curr->get_rhombus()->Area())
        {
            curr = curr->get_right();
            continue;
        }
    }
    throw std::out_of_range("out_of_range");

}

size_t TBinaryTree::Count(shared_ptr<Rhombus> rhombus) {
    size_t count = 0;
    shared_ptr<TreeItem> curr = root;

    while (curr)
    {
        if (curr->get_rhombus() == rhombus)
            count = curr->get_count();
        if (rhombus->Area() < curr->get_rhombus()->Area())
        {
            curr = curr->get_left();
            continue;
        }
        if (rhombus->Area() >= curr->get_rhombus()->Area())
        {
            curr = curr->get_right();
            continue;
        }
    }
    return count;
}

void Pop_List(shared_ptr<TreeItem> curr, shared_ptr<TreeItem> parent);
void Pop_Part_of_Branch(shared_ptr<TreeItem> curr, shared_ptr<TreeItem> parent);
void Pop_Root_of_Subtree(shared_ptr<TreeItem> curr, shared_ptr<TreeItem> parent);
void TBinaryTree::Pop( shared_ptr<Rhombus> rhombus) {

    shared_ptr<TreeItem> curr = root;
    shared_ptr<TreeItem> parent = nullptr;

    while (curr && curr->get_rhombus() != rhombus)
    {
        parent = curr;
        if (curr->get_rhombus()->Area() > rhombus->Area())
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

void Pop_List(shared_ptr<TreeItem> curr, shared_ptr<TreeItem> parent) {
    if (parent->get_left() == curr)
        parent->set_left(nullptr);
    else
        parent->set_right(nullptr);
}

void Pop_Part_of_Branch(shared_ptr<TreeItem> curr, shared_ptr<TreeItem> parent) {
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

void Pop_Root_of_Subtree(shared_ptr<TreeItem> curr, shared_ptr<TreeItem> parent) {
    shared_ptr<TreeItem> replace = curr->get_left();
    shared_ptr<TreeItem> rep_parent = curr;
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

bool TBinaryTree::Empty() {
    return root == nullptr ? true : false;
}

void Tree_out (std::ostream& os, shared_ptr<TreeItem> curr);
std::ostream& operator<<(std::ostream& os, const TBinaryTree& tree) {
    shared_ptr<TreeItem> curr = tree.root;
    Tree_out(os, curr);
    return os;
}

void Tree_out (std::ostream& os, shared_ptr<TreeItem> curr) {
    if (curr)
    {
        if(curr->get_rhombus()->Area() >= 0)
            os << curr->get_count() << "*" << curr->get_rhombus()->Area();
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

void recursive_clear(shared_ptr<TreeItem> curr);
void TBinaryTree::Clear() {
    if (root != nullptr) {
        if (root->get_left())
            recursive_clear(root->get_left());
        root->set_left(nullptr);
        if (root->get_right())
            recursive_clear(root->get_right());
        root->set_right(nullptr);
    }
    root = nullptr;
}

void recursive_clear(shared_ptr<TreeItem> curr){
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

TBinaryTree::~TBinaryTree() {
    this->Clear();
}
