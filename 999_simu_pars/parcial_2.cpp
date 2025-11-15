#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#include <list>
#include <stdexcept>

// Ej 1
/*
Implementar el método bool ArbolBinario::esBSTBalanceado() de la clase ArbolBinario.  Este método debe determinar si el árbol binario almacenado  es simultáneamente un Árbol Binario de Búsqueda (BST) y está Balanceado en Altura.

BST: Para todo nodo, los valores de su subárbol izquierdo son menores y los de su subárbol derecho son mayores.

Balanceado: Para todo nodo, la diferencia de altura (en valor absoluto) entre su subárbol izquierdo y su subárbol derecho es como máximo 1.

Un árbol con raíz nullptr se considera BST y balanceado.

Deberás utilizar 2 metodos auxiliares

    bool esBSTRec(NodoArbol* nodo, int minVal, int maxVal); Metodo recursivo para determinar si el arbol es un BST

    int checkAlturaBalance(NodoArbol* nodo); Metodo recursivo para determinar si el arbol está balanceado.

Un árbol con raíz nullptr se considera balanceado y con altura 0 , devuelve 0.
Devuelve -1 si el arbol no está balanceado. Para determinarlo se debe llamar recursivamente para cada hijo y calcular el factor de balance std::abs(alturaIzq - alturaDer) , si alguno de los hijos está desbalanceado devuelve -1 .
Si está balanceado: El método devuelve la altura real 1 + std::max(alturaIzq, alturaDer)
*/
struct NodoArbol
{
    int valor;
    NodoArbol *izquierda;
    NodoArbol *derecha;
    NodoArbol(int v) : valor(v), izquierda(nullptr), derecha(nullptr) {}
};

class ArbolBinario
{
private:
    NodoArbol *raiz;

public:
    ArbolBinario() : raiz(nullptr) {}

    ~ArbolBinario()
    {
        destruir(raiz);
    }

    void setRaiz(NodoArbol *nuevaRaiz)
    {
        if (raiz != nullptr)
        {
            destruir(raiz);
        }
        raiz = nuevaRaiz;
    }

    bool esBalanceado();

private:
    void destruir(NodoArbol *nodo)
    {
        if (nodo != nullptr)
        {
            destruir(nodo->izquierda);
            destruir(nodo->derecha);
            delete nodo;
        }
    }
    int checkAlturaBalance(NodoArbol *nodo);
};

// RTA
bool ArbolBinario::esBalanceado()
{
    return false;
}

int ArbolBinario::checkAlturaBalance(NodoArbol *nodo)
{
    return -1;
}

// Ej 2
/*
Implementar el método bool Grafo::esBipartito() de la clase Grafo. Este método debe determinar si el grafo no dirigido almacenado es bipartito.

Grafo Bipartito: Un grafo es bipartito si es posible "colorear" cada uno de sus vértices con uno de dos colores (por ejemplo, Color 0 y Color 1) de tal manera que ninguna arista conecte dos vértices del mismo color.



Deberás utilizar un método auxiliar recursivo basado en Recorrido en Profundidad (DFS):

bool esBipartitoRec(int u, int colorActual, int colores[]);

u: El vértice que se está visitando actualmente.
colores[]: Arreglo para almacenar el color de cada vértice.
-1 para "no coloreado"
0 para Color 0
1 para Color 1.
colorActual: El color (0 o 1) que se debe asignar al vértice u.
Asigna el color actual a u , luego calcula el color esperado para los vecinos y se llamar recursivament para las adyacencias que aún no fueron coloreadas.

Devuelve  false , si alguna llamada recursiva devuelve false
Devuelve false, si la adyacencia ya estaba coloreada y tiene el mismo color que u.
Si no aplica ninguno de los casos anteriores para ninguna adyacencia devuelve true
El método principal esBipartito() deberá inicializar el arreglo colores (todo a -1) y llamar a esBipartitoRec para cada vértice que no haya sido coloreado. Devuelve false si alguna llamada a esBipartitoRec devuelve false
*/
class Grafo
{
private:
    int V;
    std::list<int> *adj;

    bool esBipartitoRec(int u, int colorActual, int colores[]);

public:
    Grafo(int V)
    {
        this->V = V;
        this->adj = new std::list<int>[V];
    }

    ~Grafo()
    {
        delete[] adj;
    }

    void agregarArista(int u, int v)
    {
        if (u >= 0 && u < V && v >= 0 && v < V)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    bool esBipartito();
};

// RTA
bool Grafo::esBipartito()
{
    return false;
}

bool Grafo::esBipartitoRec(int u, int colorActual, int colores[])
{
    return false;
}