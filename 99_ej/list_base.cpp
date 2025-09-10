#include "list_base.hpp"
#include <iostream>
#include <stdexcept>

// Implementaciones de Node
// Cosntructores y destructor
template <typename T>
Node<T>::Node(T val) : value(val), next(nullptr), prev(nullptr) {}
template <typename T>
Node<T>::~Node() {}

// Implementación del método print
template <typename T>
void Node<T>::print()
{
    std::cout << "[NODO] valor: " << value << ", siguiente: " << next << std::endl;
}

// Implementaciones de ListBase
// Cosntructores y destructor
template <typename T>
ListBase<T>::ListBase() : head(nullptr), lenght(0) {}
template <typename T>
ListBase<T>::ListBase(Node<T> *head) : head(head), lenght(1) {}

// Implementación del destructor
template <typename T>
ListBase<T>::~ListBase()
{
    std::cout << "Destruyendo ..." << std::endl;

    while (!isEmpty())
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
}

// Implementación del método push
template <typename T>
void ListBase<T>::push(T val)
{
    Node<T> *newNode = new Node<T>(val);
    newNode->next = head;
    head = newNode;
    lenght++;
}

// Implementación del método pop
template <typename T>
void ListBase<T>::pop(T val)
{
    if (isEmpty())
        throw std::runtime_error("La lista está vacía");

    Node<T> *temp = head;
    head = head->next;
    delete temp;
    lenght--;
}

// Implementación del método isEmpty
template <typename T>
bool ListBase<T>::isEmpty() const
{
    return head == nullptr;
}

// Implementación del método getHead
template <typename T>
T ListBase<T>::getHead() const
{
    if (isEmpty())
        throw std::runtime_error("Está vacía");

    return head->value;
}

// Implementación del método getLenght
template <typename T>
int ListBase<T>::getLenght() const
{
    return lenght;
}

// Implementación del método getRest
template <typename T>
ListBase<T> *ListBase<T>::getRest() const
{
    if (isEmpty())
        throw std::runtime_error("Está vacía");

    return new ListBase<T>(head->next);
}

// Implementación del método print de la clase ListBase
template <typename T>
void ListBase<T>::print() const
{
    std::cout << "[BASE] ";

    if (isEmpty())
    {
        std::cout << "La base está vacía." << std::endl;
        return;
    }

    head->print();
    getRest()->print();
}

// Como estamos trabajado con archivos separados, necesitamos instanciar las clases genéricas que vamos a usar
// Si no lo hacemos, el compilador no generará el código para estas clases y obtendremos errores de "símbolo no definido" durante el enlace
template class Node<int>;
template class ListBase<int>;
template class Node<double>;
template class ListBase<double>;
template class Node<std::string>;
template class ListBase<std::string>;