#include <iostream>
#include "list_base.hpp"
#include "lists.hpp"
#include "double_list.cpp"
#include "binary_tree.cpp"

void testingNodeAndList()
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
}

int main()
{
    // Testing Nodos y Listas
    // testingNodeAndList();

    // Testing Listas doblemente enlazadas
    // testingDoubleList();

    // Testing Arboles binarios
    testingBinaryTree();

    return 0;
}
