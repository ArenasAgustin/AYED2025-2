#include <iostream>
#include "lists.hpp"

int main()
{
    Node<int> *node = new Node<int>(3);
    List<int> *list = new List<int>();

    list->print();
    list->push(1);
    list->print();

    return 0;
}
