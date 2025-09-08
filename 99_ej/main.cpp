#include <iostream>
#include "lists.hpp"

int main()
{
    Node<int> *node = new Node<int>(3);
    List<int> *list = new List<int>();

    list->print();
    list->push(1);
    list->print();

    std::cout << list->getHead() << std::endl;
    std::cout << list->getLenght() << std::endl;

    delete list;
    delete node;

    return 0;
}
