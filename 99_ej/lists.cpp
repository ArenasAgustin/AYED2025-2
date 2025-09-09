#include "lists.hpp"
#include <iostream>
#include <stdexcept>

// Implementaciones de Node
// Cosntructores y destructor
template <typename T>
Node<T>::Node(T val) : value(val), next(nullptr) {}
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

// Implementación del método getTail
template <typename T>
ListBase<T> *ListBase<T>::getTail() const
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
    getTail()->print();
}

// Implementaciones de List
// Cosntructores y destructor
template <typename T>
List<T>::List() : ListBase<T>() {}
template <typename T>
List<T>::List(Node<T> *head) : ListBase<T>(head) {}
template <typename T>
List<T>::~List() {} // El destructor de la clase base se encarga de la limpieza

// Implementación del método print de la clase List
template <typename T>
void List<T>::print() const
{
    std::cout << "[LISTA] ";

    if (this->isEmpty())
    {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    this->head->print();
    this->getTail()->print();
}

// Implementación del método getTail de la clase List
template <typename T>
List<T> *List<T>::getTail() const
{
    if (this->isEmpty())
        throw std::runtime_error("Está vacía");

    return new List<T>(this->head->next);
}

// Implementación del método get
template <typename T>
T List<T>::get(int index)
{
    if (index < 0 || index >= this->lenght)
        throw std::runtime_error("El indice no es valido");

    int currentIndex = 0;
    Node<T> *current = this->head;

    while (index != currentIndex)
    {
        current = current->next;
        currentIndex++;
    }

    return current->value;
}

// Implementación del método slice
template <typename T>
List<T> *List<T>::slice(int start, int end)
{
    if (start < 0 || end > this->lenght || start >= end)
        throw std::runtime_error("Índices fuera de rango");

    List<T> *slicedList = new List<T>();

    T *tempArray = new T[end - start];
    int tempIndex = 0;

    Node<T> *current = this->head;
    int currentIndex = 0;

    while (current != nullptr && currentIndex < end)
    {
        if (currentIndex >= start)
        {
            tempArray[tempIndex] = current->value;
            tempIndex++;
        }

        current = current->next;
        currentIndex++;
    }

    for (int i = tempIndex - 1; i >= 0; i--)
    {
        slicedList->push(tempArray[i]);
    }

    delete[] tempArray;

    return slicedList;
}

// Como estamos trabajado con archivos separados, necesitamos instanciar las clases genéricas que vamos a usar
// Si no lo hacemos, el compilador no generará el código para estas clases y obtendremos errores de "símbolo no definido" durante el enlace
template class Node<int>;
template class ListBase<int>;
template class List<int>;
template class Node<double>;
template class ListBase<double>;
template class List<double>;
template class Node<std::string>;
template class ListBase<std::string>;
template class List<std::string>;