#ifndef TVECTOR_ITEM_H
#define TVECTOR_ITEM_H

#include "memory"
#include "new"

template<typename T>
class TVectorItem {
public:
    TVectorItem();

    TVectorItem(const TVectorItem<T> &other);

    TVectorItem(const T &item);

    TVectorItem<T> &operator=(const TVectorItem<T> &other);

    T &GetValue();

    virtual ~TVectorItem();

private:
    T value;
};


#endif