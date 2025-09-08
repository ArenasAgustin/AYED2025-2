#ifndef LISTS_HPP
#define LISTS_HPP

// Definición de la estructura del nodo
template <typename T>
struct Node
{
    T value;       // Valor del nodo
    Node<T> *next; // Puntero al siguiente nodo
    Node(T val);   // Constructor
    void print();  // Método para imprimir el nodo
};

// Definición de la clase Lista
template <typename T>
class List
{
public:
    List();                             // Constructor
    List(Node<T> *head);                // Constructor con nodo inicial
    ~List();                            // Destructor
    void push(T val);                   // Agregar al inicio
    bool isEmpty();                     // Verificar si está vacía
    T getHead();                        // Obtener valor del primer nodo
    int getLenght();                    // Obtener el tamaño
    List<T> *getTail();                 // Obtener la sublista sin el primer nodo
    void print();                       // Imprimir la lista
    List<T> *slice(int start, int end); // Obtener una sublista

private:
    Node<T> *head; // Puntero al primer nodo
    int lenght;    // Tamaño de la lista
};

#endif // LISTS_HPP