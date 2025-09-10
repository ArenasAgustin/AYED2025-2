#ifndef LIST_BASE_HPP
#define LIST_BASE_HPP

// Definición de la estructura del nodo
template <typename T>
struct Node
{
    T value;       // Valor del nodo
    Node<T> *next; // Puntero al siguiente nodo
    Node(T val);   // Constructor
    ~Node();       // Destructor
    void print();  // Método para imprimir el nodo
};

// Definición de la clase base ListBase
template <typename T>
class ListBase
{
public:
    ListBase();                           // Constructor
    ListBase(Node<T> *head);              // Constructor con nodo inicial
    ~ListBase();                          // Destructor
    void push(T val);                     // Agregar al inicio (NO const - modifica la lista)
    void pop(T val);                      // Eliminar el primer elemento (NO const - modifica la lista)
    bool isEmpty() const;                 // Verificar si está vacía
    T getHead() const;                    // Obtener valor del primer nodo
    int getLenght() const;                // Obtener el tamaño
    virtual ListBase<T> *getTail() const; // Obtener la sublista sin el primer nodo
    virtual void print() const;           // Imprimir la lista

protected:         // Cambiar a protected para que las clases derivadas puedan acceder
    Node<T> *head; // Puntero al primer nodo
    int lenght;    // Tamaño de la lista
};

#endif // LIST_BASE_HPP