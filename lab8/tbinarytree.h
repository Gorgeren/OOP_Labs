#ifndef TBINARYTREE_H
#define TBINARYTREE_H
#include "tbinarytreeitem.h"

template <class T>
class TBinaryTree {
public:
    // Конструктор по умолчанию.
    TBinaryTree();

    void Push(T& rhombus);
    // Метод получения фигуры из контейнера.
    // Если площадь превышает максимально возможную,
    // метод должен бросить исключение std::out_of_range
    T& GetItemNotLess(double area);
    // Метод, возвращающий количество совпадающих фигур с данными параметрами
    size_t Count(T& rhombus);
    // Метод по удалению фигуры из дерева:
    // Счетчик вершины уменьшается на единицу.
    // Если счетчик становится равен 0,
    // вершина удаляется с заменой на корректный узел поддерева.
    // Если такой вершины нет, бросается исключение std::invalid_argument
    void Pop(T& rhombus);
    // Метод проверки наличия в дереве вершин
    bool Empty();
    // Оператор вывода дерева в формате вложенных списков,
    // где каждый вложенный список является поддеревом текущей вершины:
    // "S0: [S1: [S3, S4: [S5, S6]], S2]",
    // где Si - строка вида количество*площадь_фигуры
    // Пример: 1*1.5: [3*1.0, 2*2.0: [2*1.5, 1*6.4]]
    template <class A>
    friend std::ostream& operator<<(std::ostream& os, const TBinaryTree<A>& tree);
    // Метод, удаляющий все элементы контейнера,
    // но позволяющий пользоваться им.
    void Clear();
    // Деструктор
    virtual ~TBinaryTree();
private:
    shared_ptr<TreeElem<T>> root;
};



#endif