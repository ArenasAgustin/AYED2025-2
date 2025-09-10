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
    T get(int index);                   // Obtener valor en índice
    List<T> *slice(int start, int end); // Obtener una sublista
};

// Definición de la clase Lista que hereda de ListBase
template <typename T>
class Queue : public ListBase<T>
{
public:
    Queue();                     // Constructor
    Queue(Node<T> *head);        // Constructor con nodo inicial
    ~Queue();                    // Destructor
    void enqueue(T val);         // Agregar al final
    void dequeue(T val);         // Eliminar el primer elemento
    void print() const override; // Imprimir la lista
private:
    Node<T> *tail; // Puntero al último nodo
};

#endif // LISTS_HPP