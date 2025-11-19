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

La función recursiva esBalanceadoRecursivo(Nodo2*)

La clase BST, que recibe la raíz en su constructor y expone un método bool esBalanceado() que retorna true si el árbol está balanceado
*/
struct Nodo2
{
    int valor;
    Nodo2 *izquierdo;
    Nodo2 *derecho;

    Nodo2(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

class BST
{
private:
    Nodo2 *raiz;

    // Retorna la altura si está balanceado, o -1 si no lo está
    int esBalanceadoRecursivo(Nodo2 *nodo)
    {
        if (nodo == nullptr)
            return 0;

        int izq = esBalanceadoRecursivo(nodo->izquierdo);
        int der = esBalanceadoRecursivo(nodo->derecho);

        if (izq == -1 || der == -1)
            return -1;

        int bal = abs(izq - der);

        if (bal > 1)
            return -1;

        return 1 + max(izq, der);
    }

public:
    BST(Nodo2 *&r) : raiz(r) {}

    bool esBalanceado()
    {
        return esBalanceadoRecursivo(raiz) != -1;
    }
};

// Test
void testingBST()
{
    {
        cout << "TEST 1: testingBST" << endl;

        Nodo2 *raiz = new Nodo2(10);
        raiz->izquierdo = new Nodo2(5);
        raiz->derecho = new Nodo2(15);
        raiz->izquierdo->izquierdo = new Nodo2(3);
        BST *arbol = new BST(raiz);

        cout << (arbol->esBalanceado() ? "Si" : "No") << endl; // Si
    }

    {
        cout << "TEST 2: testingBST" << endl;

        Nodo2 *raiz = new Nodo2(10);
        raiz->izquierdo = new Nodo2(5);
        raiz->izquierdo->izquierdo = new Nodo2(3);
        raiz->izquierdo->izquierdo->izquierdo = new Nodo2(1);
        BST *arbol = new BST(raiz);

        cout << (arbol->esBalanceado() ? "Si" : "No") << endl; // No
    }

    {
        cout << "TEST 3: testingBST" << endl;

        Nodo2 *raiz = new Nodo2(1);
        BST *arbol = new BST(raiz);

        cout << (arbol->esBalanceado() ? "Si" : "No") << endl; // Si
    }

    {
        cout << "TEST 4: testingBST" << endl;

        Nodo2 *raiz = nullptr;
        BST *arbol = new BST(raiz);

        cout << (arbol->esBalanceado() ? "Si" : "No") << endl; // Si
    }

    {
        cout << "TEST 5: testingBST" << endl;

        Nodo2 *raiz = new Nodo2(20);
        raiz->izquierdo = new Nodo2(10);
        raiz->derecho = new Nodo2(30);
        raiz->izquierdo->derecho = new Nodo2(15);
        raiz->derecho->izquierdo = new Nodo2(25);
        raiz->derecho->derecho = new Nodo2(35);
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

Implementa una clase RedDeSensores2 que permita:

Agregar conexiones entre módulos.

Verificar si dos módulos están directamente conectados (de forma iterativa).

Calcular cuántos módulos son alcanzables desde un nodo dado (usando DFS recursivo).
*/
class RedDeSensores2
{
public:
    RedDeSensores2(int cantidadModulos)
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
        int conectados = adyacencias[a][b] == 1 ? 1 : 0;

        cout << "Conexion directa (" << a << " - " << b << "): " << conectados << "\n";
    }

    void imprimirAlcanzables(int desde)
    {
        int *visitados = new int[cantidad]();

        int c = alcanzables(desde, visitados);

        cout << "Modulos alcanzables desde " << desde << ": " << c << "\n";
    }

private:
    int cantidad;
    std::vector<std::vector<int>> adyacencias;

    int alcanzables(int desde, int visitados[])
    {
        visitados[desde] = 1;
        int c = 1;

        for (int i = 0; i < cantidad; i++)
        {
            if (visitados[i] != 1 && adyacencias[desde][i] == 1)
            {
                visitados[i] = 1;
                c += alcanzables(i, visitados);
            }
        }

        return c;
    }
};

// Test
void testingRedDeSensores2()
{
    {
        cout << "TEST 1: testingRedDeSensores2" << endl;

        RedDeSensores2 red(5);

        red.agregarConexion(0, 1);
        red.agregarConexion(1, 2);
        red.agregarConexion(3, 4);

        red.imprimirConexion(0, 1); // Conexion directa (0 - 1): 1
        red.imprimirConexion(1, 3); // Conexion directa (1 - 3): 0
    }

    {
        cout << "TEST 2: testingRedDeSensores2" << endl;

        RedDeSensores2 red(6);

        red.agregarConexion(0, 1);
        red.agregarConexion(1, 2);
        red.agregarConexion(2, 3);

        red.imprimirAlcanzables(0); // Modulos alcanzables desde 0: 4
        red.imprimirAlcanzables(4); // Modulos alcanzables desde 4: 1
    }
}