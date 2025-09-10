#ifndef LISTS_HPP
#define LISTS_HPP

#include "list_base.hpp"

// Definiciones de la clase Stack
template <typename T>
class Stack : public ListBase<T>
{
public:
    Stack();                     // Constructor
    ~Stack();                    // Destructor
    T top() const;               // Obtener el valor del tope
    void print() const override; // Imprimir la pila
};

// Definición de la clase Lista que hereda de ListBase
template <typename T>
class List : public ListBase<T>
{
public:
    List();                             // Constructor
    List(Node<T> *head);                // Constructor con nodo inicial
    ~List();                            // Destructor
    void print() const override;        // Imprimir la lista
    List<T> *getTail() const override;  // Obtener la sublista sin el primer nodo
    T get(int index);                   // Obtener valor en índice
    List<T> *slice(int start, int end); // Obtener una sublista
};

#endif // LISTS_HPP