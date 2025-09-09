#include "list_base.hpp"
#include "lists.hpp"
#include <iostream>
#include <stdexcept>

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

// Implementaciones de Stack
// Cosntructores y destructor
template <typename T>
Stack<T>::Stack() : ListBase<T>() {}
template <typename T>
Stack<T>::~Stack() {} // El destructor de la clase base se encarga de la limpieza

// Implementación del método top
template <typename T>
T Stack<T>::top() const
{
    if (this->isEmpty())
        throw std::runtime_error("La pila está vacía");

    return this->head->value;
}

// Implementación del método print de la clase Stack
template <typename T>
void Stack<T>::print() const
{
    std::cout << "[PILA] ";

    if (this->isEmpty())
    {
        std::cout << "La pila está vacía." << std::endl;
        return;
    }

    this->head->print();
    this->getTail()->print();
}

// Como estamos trabajado con archivos separados, necesitamos instanciar las clases genéricas que vamos a usar
// Si no lo hacemos, el compilador no generará el código para estas clases y obtendremos errores de "símbolo no definido" durante el enlace
template class List<int>;
template class Stack<int>;
template class List<double>;
template class Stack<double>;
template class List<std::string>;
template class Stack<std::string>;