#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;

// Ej 1
/*
Durante la fase crítica de descenso en Marte, la computadora de vuelo de la misión CONAE-Marte utiliza un árbol binario de decisiones para seleccionar maniobras según condiciones (velocidad, altitud, temperatura externa, etc.).

Para garantizar tiempos de respuesta razonables, este árbol debe estar balanceado, es decir:

La diferencia de alturas entre subárbol izquierdo y derecho en cada nodo es a lo sumo 1

Ambos subárboles también son balanceados

El árbol vacío se considera balanceado

Implementá desde cero:

La función recursiva esBalanceadoRecursivo(Nodo*)

La clase BST, que recibe la raíz en su constructor y expone un método bool esBalanceado() que retorna true si el árbol está balanceado
*/
struct Nodo
{
    int valor;
    Nodo *izquierdo;
    Nodo *derecho;

    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

class BST
{
private:
    Nodo *raiz;

    // Retorna la altura si está balanceado, o -1 si no lo está
    int esBalanceadoRecursivo(Nodo *nodo)
    {
    }

public:
    BST(Nodo *&r) : raiz(r) {}

    bool esBalanceado()
    {
    }
};

// Test
void testingBST()
{
    {
        Nodo *raiz = new Nodo(10);
        raiz->izquierdo = new Nodo(5);
        raiz->derecho = new Nodo(15);
        raiz->izquierdo->izquierdo = new Nodo(3);
        BST *arbol = new BST(raiz);

        cout << (arbol->esBalanceado() ? "Si" : "No") << endl; // Si
    }

    {
        Nodo *raiz = new Nodo(10);
        raiz->izquierdo = new Nodo(5);
        raiz->izquierdo->izquierdo = new Nodo(3);
        raiz->izquierdo->izquierdo->izquierdo = new Nodo(1);
        BST *arbol = new BST(raiz);

        cout << (arbol->esBalanceado() ? "Si" : "No") << endl; // No
    }

    {
        Nodo *raiz = new Nodo(1);
        BST *arbol = new BST(raiz);

        cout << (arbol->esBalanceado() ? "Si" : "No") << endl; // Si
    }

    {
        Nodo *raiz = nullptr;
        BST *arbol = new BST(raiz);

        cout << (arbol->esBalanceado() ? "Si" : "No") << endl; // Si
    }

    {
        Nodo *raiz = new Nodo(20);
        raiz->izquierdo = new Nodo(10);
        raiz->derecho = new Nodo(30);
        raiz->izquierdo->derecho = new Nodo(15);
        raiz->derecho->izquierdo = new Nodo(25);
        raiz->derecho->derecho = new Nodo(35);
        BST *arbol = new BST(raiz);

        cout << (arbol->esBalanceado() ? "Si" : "No") << endl; // Si
    }
}

// Ej 2
/*
Estás desarrollando el software para un sistema embebido distribuido (por ejemplo, una red IoT de sensores industriales).
Cada nodo del sistema es un módulo (sensor, actuador, controlador) y está conectado a otros mediante enlaces directos (por ejemplo, bus CAN o I2C).

Debes representar esta red como un grafo no dirigido, donde:

Cada módulo es un nodo.

Las conexiones físicas entre ellos son aristas.

Tu tarea:

Implementa una clase RedDeSensores que permita:

Agregar conexiones entre módulos.

Verificar si dos módulos están directamente conectados (de forma iterativa).

Calcular cuántos módulos son alcanzables desde un nodo dado (usando DFS recursivo).
*/
class RedDeSensores
{
public:
    RedDeSensores(int cantidadModulos)
    {
        cantidad = cantidadModulos;
        adyacencias.reserve(cantidad);
        adyacencias.resize(cantidad, std::vector<int>(cantidad, 0));
    }

    void agregarConexion(int a, int b)
    {
        adyacencias[a][b] = 1;
        adyacencias[b][a] = 1;
    }

    void imprimirConexion(int a, int b)
    {
        // cout << "Conexion directa (" << a << " - " << b << "): " << c << "\n";
    }

    void imprimirAlcanzables(int desde)
    {
        // cout << "Modulos alcanzables desde " << desde << ": " << c << "\n";
    }

private:
    int cantidad;
    std::vector<std::vector<int>> adyacencias;

    int alcanzables(int d, int v[])
    {
    }
};

// Test
void testingRedDeSensores()
{
    {
        RedDeSensores red(5);

        red.agregarConexion(0, 1);
        red.agregarConexion(1, 2);
        red.agregarConexion(3, 4);

        red.imprimirConexion(0, 1); // Conexion directa (0 - 1): Si
        red.imprimirConexion(1, 3); // Conexion directa (1 - 3): No
    }

    {
        RedDeSensores red(6);

        red.agregarConexion(0, 1);
        red.agregarConexion(1, 2);
        red.agregarConexion(2, 3);

        red.imprimirAlcanzables(0); // Modulos alcanzables desde 0: 4
        red.imprimirAlcanzables(4); // Modulos alcanzables desde 4: 1
    }
}