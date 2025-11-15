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

/* =========================================
   Nodo genérico para ABB (punteros crudos)
   ========================================= */
template <class T>
class Nodo
{
public:
    T dato;
    Nodo *izq;
    Nodo *der;

    Nodo(T x);
};

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
    Nodo<T> *raiz;

    // ---- helpers básicos ----
    void clearRec(Nodo<T> *p);
    int tamRec(Nodo<T> *p);
    void inordenRec(Nodo<T> *p, std::vector<T> &out);
    Nodo<T> *minNode(Nodo<T> *p);

    // ---- inserción / borrado ----
    Nodo<T> *insertarRec(Nodo<T> *p, T x);
    Nodo<T> *eraseRec(Nodo<T> *p, T x);

    // ---- extensiones de orden ----
    Nodo<T> *lowerBoundHelper(Nodo<T> *p, T x);               // iterativo
    Nodo<T> *predecessorHelper(Nodo<T> *p, T x);              // iterativo
    void rangoRec(Nodo<T> *p, T a, T b, std::vector<T> &out); // recursivo

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

/* =========================================
   Calendar: fachada sobre ABB<Evento>
   ========================================= */
class Calendar
{
private:
    ABB<Evento> tree;

    // claves auxiliares para intervalos
    Evento keyFloor(int ymdhm);
    Evento keyCeil(int ymdhm);

public:
    Calendar();

    void agregarEvento(Evento e);
    void removerEvento(int ymdhm, std::string titulo);

    Evento proximo(int ymdhm);
    std::vector<Evento> entre(int a, int b);
    std::vector<Evento> conflictosEn(int ymdhm);

    int size();
    std::vector<Evento> inorden();
};

//  Ej 1
/*
Implementá la operación lower_bound(x) sobre un ABB (árbol binario de búsqueda) que guarda elementos ordenados por operator<.
Tu tarea es completar el helper iterativo lowerBoundHelper(p, x) que debe encontrar el primer elemento del árbol que sea >= x (usando solo comparaciones con operator<, sin <=/>=).
Si el candidato no existe, lower_bound debe lanzar runtime_error("lower_bound: no encontrado").
Recordá que el recorrido debe ser O(h) (h = altura): usá una búsqueda binaria manteniendo un mejor candidato (best) mientras bajás por el árbol.
*/
template <class T>
Nodo<T> *ABB<T>::lowerBoundHelper(Nodo<T> *p, T x)
{
    Nodo<T> *r = nullptr;

    return r;
}

// Test
void testingLowerBound()
{
    {
        Calendar cal;

        cal.agregarEvento({202510221000, "Standup", ""});
        cal.agregarEvento({202510221000, "Aviso", ""});
        cal.agregarEvento({202510221300, "Almuerzo", ""});

        Evento e = cal.proximo(202510221000);

        cout << e.ymdhm << " " << e.titulo << "\n"; // 202510221000 Aviso
    }

    {
        Calendar cal;

        cal.agregarEvento({202510221000, "A", ""});
        cal.agregarEvento({202510221300, "B", ""});
        cal.agregarEvento({202510221530, "C", ""});

        Evento e = cal.proximo(202510221200);

        cout << e.ymdhm << " " << e.titulo << "\n"; // 202510221300 B
    }

    {
        Calendar cal;
        cal.agregarEvento({202401010900, "A", ""});
        cal.agregarEvento({202401011000, "B", ""});

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
Tu tarea es completar el helper iterativo predecessorHelper(p, x) que debe encontrar el elemento estrictamente menor que x más grande (el “inmediato anterior” a x en el orden del árbol), usando solo comparaciones con operator< (no uses <=/>=).
Si no existe un candidato (todos son ≥ x o el árbol está vacío), predecessor debe lanzar runtime_error("predecessor: no encontrado").
La búsqueda debe ser O(h) (h = altura): mantené un mejor candidato (best) mientras descendés por el árbol, moviéndote a derecha cuando p->dato < x y a izquierda en caso contrario.
*/
template <class T>
Nodo<T> *ABB<T>::predecessorHelper(Nodo<T> *p, T x)
{
    Nodo<T> *r = nullptr;

    return r;
}

// Test
void testingPredecessor()
{
    {
        ABB<Evento> t;

        t.insert({202510221000LL, "A", ""});
        t.insert({202510221300LL, "B", ""});
        t.insert({202510221530LL, "C", ""});

        Evento q = {202510221300LL, "", ""}; // buscamos pred de 13:00
        Evento p = t.predecessor(q);

        cout << p.ymdhm << " " << p.titulo << "\n"; // Esperado: 202510221000 A
    }

    {
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
void ABB<T>::rangoRec(Nodo<T> *p, T a, T b, vector<T> &out)
{
}

// Test
void testingRango()
{
    {

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
        ABB<Evento> t;

        t.insert({202401010900LL, "A", ""});
        t.insert({202401011000LL, "B", ""});

        auto v = t.rango({202501010000LL, "", ""}, {202501010100LL, "~", ""});

        cout << v.size() << "\n"; // Esperado: 0
    }
}