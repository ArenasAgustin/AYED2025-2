#include "lists.hpp"
#include <iostream>
#include <stdexcept>

// Implementación del constructor
template <typename T>
Node<T>::Node(T val) : value(val), next(nullptr) {}

// Implementación del método print
template <typename T>
void Node<T>::print()
{
    std::cout << "[NODO] valor: " << value << ", siguiente: " << next << std::endl;
}

// Implementación del constructor
template <typename T>
List<T>::List() : head(nullptr), lenght(0) {}
template <typename T>
List<T>::List(Node<T> *head) : head(head), lenght(1) {}

// Implementación del destructor
template <typename T>
List<T>::~List()
{
    std::cout << "Destruyendo lista..." << std::endl;

    while (!isEmpty())
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
}

// Implementación del método push
template <typename T>
void List<T>::push(T val)
{
    Node<T> *newNode = new Node<T>(val);
    newNode->next = head;
    head = newNode;
    lenght++;
}

// Implementación del método isEmpty
template <typename T>
bool List<T>::isEmpty()
{
    return head == nullptr;
}

// Implementación del método getHead
template <typename T>
T List<T>::getHead()
{
    if (isEmpty())
        throw std::runtime_error("La lista está vacía");

    return head->value;
}

// Implementación del método getHead
template <typename T>
int List<T>::getLenght()
{
    return lenght;
}

// Implementación del método getTail
template <typename T>
List<T> *List<T>::getTail()
{
    if (isEmpty())
        throw std::runtime_error("La lista está vacía");

    return new List(head->next);
}

// Implementación del método print
template <typename T>
void List<T>::print()
{
    std::cout << "[LISTA] ";

    if (isEmpty())
    {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    head->print();
    getTail()->print();
}

// Implementación del método get
template <typename T>
T List<T>::get(int index)
{
    if (index < 0 || index >= lenght)
        throw std::runtime_error("El indice no es valido");

    int currentIndex = 0;
    Node<T> *current = head;

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
    if (start < 0 || end > lenght || start >= end)
        throw std::runtime_error("Índices fuera de rango");

    List<T> *slicedList = new List<T>();

    T *tempArray = new T[end - start];
    int tempIndex = 0;

    Node<T> *current = head;
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
template class List<int>;
template class Node<double>;
template class List<double>;
template class Node<std::string>;
template class List<std::string>;