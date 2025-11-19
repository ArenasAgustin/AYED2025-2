/*
En este trabajo vas a construir un Calendario sobre un Árbol Binario de Búsqueda (ABB) utilizando punteros crudos y sin contenedores estándar (excepto std::vector y std::string). Los eventos se representarán con una clave temporal entera YYYYMMDDHHMM (por ejemplo, 202510221430) y un título. El ABB debe mantener los eventos ordenados primero por fecha-hora y luego por título, permitiendo insertar, borrar y consultar con complejidad O(h) (h = altura del árbol). Para resolver operaciones típicas de calendario, extenderás el ABB con métodos de orden: lower_bound(x) (primer elemento ≥ x), predecessor(x) (último < x) y rango(a,b) (recorrido inorden acotado). Con esos métodos, la clase Calendar deberá ofrecer: agregar/remover eventos, obtener el próximo evento a partir de una fecha-hora dada, listar eventos en un intervalo y detectar conflictos (eventos con idéntica fecha-hora). Debes respetar el manejo correcto de memoria y la política de no duplicar un evento idéntico (ymdhm, título); se permite más de un evento en el mismo minuto si difiere el título.
*/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

/* =========================
   Modelo de datos: Evento
   ========================= */
struct Evento
{
    long long ymdhm; // clave temporal: YYYYMMDDHHMM
    std::string titulo;
    std::string descripcion;

    bool operator<(Evento &o);
    bool operator==(Evento &o);
};

bool Evento::operator<(Evento &o)
{
    if (ymdhm < o.ymdhm)
        return true;
    if (ymdhm > o.ymdhm)
        return false;
    return titulo < o.titulo;
}

bool Evento::operator==(Evento &o)
{
    return ymdhm == o.ymdhm && titulo == o.titulo;
}

/* =========================================
   NodoABB genérico para ABB (punteros crudos)
   ========================================= */
template <class T>
class NodoABB
{
public:
    T dato;
    NodoABB *izq;
    NodoABB *der;

    NodoABB(T x);
};

template <class T>
NodoABB<T>::NodoABB(T x) : dato(x), izq(nullptr), der(nullptr) {}

/* =========================================
   Árbol Binario de Búsqueda (ABB<T>)
   - Sin balanceo
   - Inserción sin duplicados exactos
   - Extendido con lower_bound / predecessor / rango
   ========================================= */
template <class T>
class ABB
{
private:
    NodoABB<T> *raiz;

    // ---- helpers básicos ----
    void clearRec(NodoABB<T> *p);
    int tamRec(NodoABB<T> *p);
    void inordenRec(NodoABB<T> *p, std::vector<T> &out);
    NodoABB<T> *minNode(NodoABB<T> *p);

    // ---- inserción / borrado ----
    NodoABB<T> *insertarRec(NodoABB<T> *p, T x);
    NodoABB<T> *eraseRec(NodoABB<T> *p, T x);

    // ---- extensiones de orden ----
    NodoABB<T> *lowerBoundHelper(NodoABB<T> *p, T x);            // iterativo
    NodoABB<T> *predecessorHelper(NodoABB<T> *p, T x);           // iterativo
    void rangoRec(NodoABB<T> *p, T a, T b, std::vector<T> &out); // recursivo

public:
    ABB();
    ~ABB();

    bool isEmpty();
    void clear();

    void insert(T x);
    void erase(T x);
    int size();
    std::vector<T> inorden();

    // API pública de orden
    T &lower_bound(T x);
    T &predecessor(T x);
    std::vector<T> rango(T a, T b);
};

// ============ ABB Implementation ============

template <class T>
ABB<T>::ABB() : raiz(nullptr) {}

template <class T>
ABB<T>::~ABB()
{
    clear();
}

template <class T>
void ABB<T>::clearRec(NodoABB<T> *p)
{
    if (p == nullptr)
        return;
    clearRec(p->izq);
    clearRec(p->der);
    delete p;
}

template <class T>
void ABB<T>::clear()
{
    clearRec(raiz);
    raiz = nullptr;
}

template <class T>
bool ABB<T>::isEmpty()
{
    return raiz == nullptr;
}

template <class T>
int ABB<T>::tamRec(NodoABB<T> *p)
{
    if (p == nullptr)
        return 0;
    return 1 + tamRec(p->izq) + tamRec(p->der);
}

template <class T>
int ABB<T>::size()
{
    return tamRec(raiz);
}

template <class T>
void ABB<T>::inordenRec(NodoABB<T> *p, std::vector<T> &out)
{
    if (p == nullptr)
        return;
    inordenRec(p->izq, out);
    out.push_back(p->dato);
    inordenRec(p->der, out);
}

template <class T>
std::vector<T> ABB<T>::inorden()
{
    std::vector<T> result;
    inordenRec(raiz, result);
    return result;
}

template <class T>
NodoABB<T> *ABB<T>::minNode(NodoABB<T> *p)
{
    while (p != nullptr && p->izq != nullptr)
        p = p->izq;
    return p;
}

template <class T>
NodoABB<T> *ABB<T>::insertarRec(NodoABB<T> *p, T x)
{
    if (p == nullptr)
        return new NodoABB<T>(x);

    if (x < p->dato)
        p->izq = insertarRec(p->izq, x);
    else if (p->dato < x)
        p->der = insertarRec(p->der, x);
    // else: x == p->dato, no insert duplicates

    return p;
}

template <class T>
void ABB<T>::insert(T x)
{
    raiz = insertarRec(raiz, x);
}

template <class T>
NodoABB<T> *ABB<T>::eraseRec(NodoABB<T> *p, T x)
{
    if (p == nullptr)
        return nullptr;

    if (x < p->dato)
    {
        p->izq = eraseRec(p->izq, x);
    }
    else if (p->dato < x)
    {
        p->der = eraseRec(p->der, x);
    }
    else
    {
        // Found node to delete
        if (p->izq == nullptr)
        {
            NodoABB<T> *temp = p->der;
            delete p;
            return temp;
        }
        else if (p->der == nullptr)
        {
            NodoABB<T> *temp = p->izq;
            delete p;
            return temp;
        }
        else
        {
            // Two children: get inorder successor
            NodoABB<T> *succ = minNode(p->der);
            p->dato = succ->dato;
            p->der = eraseRec(p->der, succ->dato);
        }
    }
    return p;
}

template <class T>
void ABB<T>::erase(T x)
{
    raiz = eraseRec(raiz, x);
}

template <class T>
T &ABB<T>::lower_bound(T x)
{
    NodoABB<T> *result = lowerBoundHelper(raiz, x);
    if (result == nullptr)
        throw std::runtime_error("lower_bound: no encontrado");
    return result->dato;
}

template <class T>
T &ABB<T>::predecessor(T x)
{
    NodoABB<T> *result = predecessorHelper(raiz, x);
    if (result == nullptr)
        throw std::runtime_error("predecessor: no encontrado");
    return result->dato;
}

template <class T>
std::vector<T> ABB<T>::rango(T a, T b)
{
    std::vector<T> result;
    rangoRec(raiz, a, b, result);
    return result;
}

/* =========================================
   Calendar: fachada sobre ABB<Evento>
   ========================================= */
class Calendar
{
private:
    ABB<Evento> tree;

    // claves auxiliares para intervalos
    Evento keyFloor(long long ymdhm);
    Evento keyCeil(long long ymdhm);

public:
    Calendar();

    void agregarEvento(Evento e);
    void removerEvento(long long ymdhm, std::string titulo);

    Evento proximo(long long ymdhm);
    std::vector<Evento> entre(long long a, long long b);
    std::vector<Evento> conflictosEn(long long ymdhm);

    int size();
    std::vector<Evento> inorden();
};

// ============ Calendar Implementation ============

Calendar::Calendar() {}

Evento Calendar::keyFloor(long long ymdhm)
{
    return {ymdhm, "", ""};
}

Evento Calendar::keyCeil(long long ymdhm)
{
    return {ymdhm, "~", ""};
}

void Calendar::agregarEvento(Evento e)
{
    tree.insert(e);
}

void Calendar::removerEvento(long long ymdhm, std::string titulo)
{
    Evento e = {ymdhm, titulo, ""};
    tree.erase(e);
}

Evento Calendar::proximo(long long ymdhm)
{
    Evento key = keyFloor(ymdhm);
    return tree.lower_bound(key);
}

std::vector<Evento> Calendar::entre(long long a, long long b)
{
    Evento keyA = keyFloor(a);
    Evento keyB = keyCeil(b);
    return tree.rango(keyA, keyB);
}

std::vector<Evento> Calendar::conflictosEn(long long ymdhm)
{
    return entre(ymdhm, ymdhm);
}

int Calendar::size()
{
    return tree.size();
}

std::vector<Evento> Calendar::inorden()
{
    return tree.inorden();
}

//  Ej 1
/*
Implementá la operación lower_bound(x) sobre un ABB (árbol binario de búsqueda) que guarda elementos ordenados por operator<.
Tu tarea es completar el helper iterativo lowerBoundHelper(p, x) que debe encontrar el primer elemento del árbol que sea >= x (usando solo comparaciones con operator<, sin <= / >=).
Si el candidato no existe, lower_bound debe lanzar runtime_error("lower_bound: no encontrado").
Recordá que el recorrido debe ser O(h) (h = altura): usá una búsqueda binaria manteniendo un mejor candidato (best) mientras bajás por el árbol.
*/
template <class T>
NodoABB<T> *ABB<T>::lowerBoundHelper(NodoABB<T> *p, T x)
{
    NodoABB<T> *best = nullptr;

    while (p != nullptr)
    {
        if (p->dato < x)
        {
            p = p->der;
        }
        else
        {
            best = p;
            p = p->izq;
        }
    }

    return best;
}

// Test
void testingLowerBound()
{
    {
        std::cout << "TEST 1: testingLowerBound" << std::endl;
        Calendar cal;

        cal.agregarEvento({202510221000LL, "Standup", ""});
        cal.agregarEvento({202510221000LL, "Aviso", ""});
        cal.agregarEvento({202510221300LL, "Almuerzo", ""});

        Evento e = cal.proximo(202510221000);

        cout << e.ymdhm << " " << e.titulo << "\n"; // 202510221000 Aviso
    }

    {
        std::cout << "TEST 2: testingLowerBound" << std::endl;
        Calendar cal;

        cal.agregarEvento({202510221000LL, "A", ""});
        cal.agregarEvento({202510221300LL, "B", ""});
        cal.agregarEvento({202510221530LL, "C", ""});

        Evento e = cal.proximo(202510221200);

        cout << e.ymdhm << " " << e.titulo << "\n"; // 202510221300 B
    }

    {
        std::cout << "TEST 3: testingLowerBound" << std::endl;
        Calendar cal;
        cal.agregarEvento({202401010900LL, "A", ""});
        cal.agregarEvento({202401011000LL, "B", ""});

        try
        {
            Evento e = cal.proximo(202501010000); // todos anteriores a la fecha pedida
            cout << e.ymdhm << " " << e.titulo << "\n";
        }
        catch (const std::runtime_error &ex)
        {
            cout << "ex\n"; // Esperado: "ex"
        }
    }
}

//  Ej 2
/*
Implementá la operación predecessor(x) sobre un ABB (árbol binario de búsqueda) que guarda elementos ordenados por operator<.
Tu tarea es completar el helper iterativo predecessorHelper(p, x) que debe encontrar el elemento estrictamente menor que x más grande (el “inmediato anterior” a x en el orden del árbol), usando solo comparaciones con operator< (no uses <= / >=).
Si no existe un candidato (todos son ≥ x o el árbol está vacío), predecessor debe lanzar runtime_error("predecessor: no encontrado").
La búsqueda debe ser O(h) (h = altura): mantené un mejor candidato (best) mientras descendés por el árbol, moviéndote a derecha cuando p->dato < x y a izquierda en caso contrario.
*/
template <class T>
NodoABB<T> *ABB<T>::predecessorHelper(NodoABB<T> *p, T x)
{
    NodoABB<T> *best = nullptr;

    while (p != nullptr)
    {
        if (p->dato < x)
        {
            best = p;
            p = p->der;
        }
        else
        {
            p = p->izq;
        }
    }

    return best;
}

// Test
void testingPredecessor()
{
    {
        std::cout << "TEST 1: testingPredecessor" << std::endl;
        ABB<Evento> t;

        t.insert({202510221000LL, "A", ""});
        t.insert({202510221300LL, "B", ""});
        t.insert({202510221530LL, "C", ""});

        Evento q = {202510221300LL, "", ""}; // buscamos pred de 13:00
        Evento p = t.predecessor(q);

        cout << p.ymdhm << " " << p.titulo << "\n"; // Esperado: 202510221000 A
    }

    {
        std::cout << "TEST 2: testingPredecessor" << std::endl;
        ABB<Evento> t;

        t.insert({202510221000LL, "A", ""});
        t.insert({202510221300LL, "B", ""});

        try
        {
            Evento q = {202010221000LL, "", ""}; // x menor que todos
            Evento p = t.predecessor(q);

            cout << p.ymdhm << " " << p.titulo << "\n";
        }
        catch (const runtime_error &e)
        {
            cout << "ex\n"; // Esperado: ex
        }
    }

    {
        std::cout << "TEST 3: testingPredecessor" << std::endl;
        ABB<Evento> t;
        long long T = 202510221000LL;

        t.insert({T, "Aviso", ""});
        t.insert({T, "Reunion", ""});
        t.insert({T, "Standup", ""});

        Evento q = {202510221000LL, "Reunion", ""}; // predecessor del par (T,"Reunion")
        Evento p = t.predecessor(q);

        cout << p.ymdhm << " " << p.titulo << "\n"; // Esperado: 202510221000 Aviso
    }
}

//  Ej 3
/*
Implementá el recorrido de rango en un ABB.
Completá el helper recursivo rangoRec(p, a, b, out) que debe:

No hacer nada si p == nullptr.

Visitar izquierda solo si pueden existir valores en rango: a < p->dato.

Agregar p->dato a out si está en el intervalo: !(p->dato < a) && !(b < p->dato) (equivalente a a ≤ p->dato ≤ b).

Visitar derecha solo si pueden existir valores en rango: p->dato < b.

El wrapper rango(a,b) crea el vector, llama al helper y lo retorna.
*/
template <class T>
void ABB<T>::rangoRec(NodoABB<T> *p, T a, T b, vector<T> &out)
{
    if (p == nullptr)
        return;

    if (p->dato < a)
        rangoRec(p->der, a, b, out);
    else if (!(p->dato < a) && !(b < p->dato))
    {
        out.push_back(p->dato);
        rangoRec(p->izq, a, b, out);
        rangoRec(p->der, a, b, out);
    }
    else if (b < p->dato)
        rangoRec(p->izq, a, b, out);
}

// Test
void testingRango()
{
    {
        std::cout << "TEST 1: testingRango" << std::endl;
        ABB<Evento> t;

        t.insert({202510221000LL, "A", ""});
        t.insert({202510221100LL, "B", ""});
        t.insert({202510221200LL, "C", ""});
        t.insert({202510221300LL, "D", ""});

        auto v = t.rango({202510221100LL, "", ""}, {202510221200LL, "~", ""});

        for (size_t i = 0; i < v.size(); ++i)
        {
            if (i)
                cout << " | ";
            cout << v[i].ymdhm << " " << v[i].titulo;
        }
        cout << "\n"; // Esperado (orden): 202510221100 B | 202510221200 C
    }

    {
        std::cout << "TEST 2: testingRango" << std::endl;
        ABB<Evento> t;
        long long T = 202510221000LL;

        t.insert({T, "Aviso", ""});
        t.insert({T, "Reunion", ""});
        t.insert({T, "Standup", ""});
        t.insert({202510221200LL, "Clase", ""});

        auto v = t.rango({202510221000LL, "", ""}, {202510221000LL, "~", ""});

        for (auto &e : v)
            cout << e.ymdhm << " " << e.titulo << "\n";
        // Esperado (orden lex por título a las 10:00):
        // 202510221000 Aviso
        // 202510221000 Reunion
        // 202510221000 Standup
    }

    {
        std::cout << "TEST 3: testingRango" << std::endl;
        ABB<Evento> t;

        t.insert({202401010900LL, "A", ""});
        t.insert({202401011000LL, "B", ""});

        auto v = t.rango({202501010000LL, "", ""}, {202501010100LL, "~", ""});

        cout << v.size() << "\n"; // Esperado: 0
    }
}