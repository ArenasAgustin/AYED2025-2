#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;

// Ej 1
/*
En los sistemas embebidos modernos, como los utilizados en estaciones meteorológicas o plantas industriales, es común que múltiples sensores envíen lecturas periódicas. Para mantener eficiencia, un microcontrolador almacena estas lecturas (temperaturas) en un Árbol Binario de Búsqueda (ABB).

Vas a implementar una clase RegistroSensoresABB que permita:

Insertar temperaturas registradas en el ABB.

Usar recursividad para contar cuántas temperaturas son iguales o mayores a cierto umbral (por ejemplo, para detectar condiciones críticas).

Imprimir directamente ese conteo en un formato predefinido.

Detalles importantes:
Implementá un método insertar(int temperatura) para almacenar una lectura.

Implementá el método recursivo contarCriticos(int umbral) para contar valores mayores o iguales al umbral.

Implementá el método imprimirCriticos(int umbral) que imprima exactamente:

Sensores criticos (temp >= <umbral>): <cantidad>
*/
struct Nodo
{
    int temp;
    Nodo *izq;
    Nodo *der;

    Nodo(int t) : temp(t), izq(nullptr), der(nullptr) {}
};

class RegistroSensoresABB
{
public:
    void insertar(int temperatura)
    {
        Nodo *node = new Nodo(temperatura);

        if (raiz == nullptr)
        {
            raiz = node;
            return;
        }

        Nodo *current = raiz;

        while (true)
        {
            if (current->temp > temperatura)
            {
                if (current->izq != nullptr)
                {
                    current = current->izq;
                }
                else
                {
                    current->izq = node;
                    return;
                }
            }
            else
            {
                if (current->der != nullptr)
                {
                    current = current->der;
                }
                else
                {
                    current->der = node;
                    return;
                }
            }
        }
    }

    int contarCriticos(int umbral)
    {
        return contarCritRec(umbral, raiz);
    }

    void imprimirCriticos(int umbral)
    {
        int c = contarCriticos(umbral);

        cout << "Sensores criticos (temp >= " << umbral << "): " << c << endl;
    }

    void imprimir()
    {
        imprimirRec(raiz);
    }

    RegistroSensoresABB() : raiz(nullptr) {}

private:
    Nodo *raiz;

    int contarCritRec(int umbral, Nodo *current)
    {
        if (current == nullptr)
            return 0;

        if (current->temp >= umbral)
            return 1 + contarCritRec(umbral, current->izq) + contarCritRec(umbral, current->der);
        else
            return contarCritRec(umbral, current->der);
    }

    void imprimirRec(Nodo *current)
    {
        if (current == nullptr)
            return;

        cout << "Nodo" << current->temp << endl;

        cout << "Izq: " << endl;
        imprimirRec(current->izq);

        cout << "Der: " << endl;
        imprimirRec(current->der);
    }
};

// Test
void testingRegistroSensoresABB()
{
    {
        cout << "TEST 1: testingRegistroSensoresABB" << endl;
        RegistroSensoresABB sistema;

        sistema.insertar(42);
        sistema.insertar(35);
        sistema.insertar(50);
        sistema.insertar(47);

        sistema.imprimirCriticos(42); // Debe imprimir: Sensores criticos (temp >= 42): 3
    }

    {
        cout << "TEST 2: testingRegistroSensoresABB" << endl;
        RegistroSensoresABB sistema;

        sistema.insertar(10);
        sistema.insertar(5);
        sistema.insertar(3);
        sistema.insertar(7);
        sistema.insertar(20);

        sistema.imprimirCriticos(8); // Debe imprimir: Sensores criticos (temp >= 8): 2
    }
}

// Ej 2
/*
Durante la misión CONAE-Marte, la nave y sus módulos auxiliares (sensores térmicos, cámaras, actuadores, procesadores) se comunican entre sí a través de buses de datos (como CAN o I2C). Para mantener un funcionamiento seguro y eficiente, es necesario analizar cómo están conectados físicamente entre ellos.

Cada módulo es un nodo, y cada conexión directa es una arista. Estas conexiones forman una red no dirigida que debe ser modelada para realizar diagnósticos en vuelo.

Implementá una clase RedDeSensores que permita:

agregarConexion(mod1, mod2): agregar una conexión directa bidireccional entre módulos.

estanConectados(mod1, mod2): devolver true si mod1 y mod2 tienen una conexión directa.

alcanzablesDesde(modInicio): devolver cuántos módulos pueden alcanzarse desde modInicio, utilizando búsqueda DFS recursiva.
*/
class RedDeSensores
{
private:
    map<string, vector<string>> grafo;

public:
    // Agrega una conexión bidireccional entre dos módulos
    void agregarConexion(const string &a, const string &b)
    {
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    // Devuelve true si existe conexión directa entre a y b
    bool estanConectados(const string &a, const string &b)
    {
        for (std::vector<string>::iterator it = grafo[a].begin(); it != grafo[a].end(); it++)
        {
            if (*it == b)
                return true;
        }

        return false;
    }

    // Devuelve cuántos módulos son alcanzables desde el módulo de inicio (incluido), usando DFS
    int alcanzablesDesde(const string &inicio)
    {
        set<string> visitados;
        visitados.insert(inicio);

        dfs(inicio, visitados);

        int c = 0;

        for (std::set<string>::iterator it = visitados.begin(); it != visitados.end(); it++)
        {
            c++;
        }

        return c;
    }

private:
    void dfs(const string &actual, set<string> &visitados)
    {
        for (std::vector<string>::iterator it = grafo[actual].begin(); it != grafo[actual].end(); it++)
        {
            if (!visitados.count(*it))
            {
                visitados.insert(*it);
                dfs(*it, visitados);
            }
        }
    }
};

// Test
void testingRedDeSensores()
{
    {
        cout << "TEST 1: testingRedDeSensores" << endl;
        RedDeSensores red;

        red.agregarConexion("A", "B");

        std::cout << (red.estanConectados("A", "B") ? "Si" : "No") << std::endl; // Si
        std::cout << (red.estanConectados("A", "C") ? "Si" : "No") << std::endl; // No
    }

    {
        cout << "TEST 2: testingRedDeSensores" << endl;
        RedDeSensores red;

        red.agregarConexion("CPU", "Sensor1");
        red.agregarConexion("Sensor1", "Sensor2");
        red.agregarConexion("Sensor2", "Actuador");

        std::cout << red.alcanzablesDesde("CPU") << std::endl; // Debe imprimir 4
        red.agregarConexion("X", "Y");
        red.agregarConexion("A", "B");

        std::cout << red.alcanzablesDesde("X") << std::endl;           // Debe imprimir 2
        std::cout << red.alcanzablesDesde("Desconocido") << std::endl; // Debe imprimir 1
    }

    {
        cout << "TEST 3: testingRedDeSensores" << endl;
        RedDeSensores red;

        red.agregarConexion("M1", "M2");

        std::cout << (red.estanConectados("M2", "M1") ? "Si" : "No") << std::endl; // Si

        red.agregarConexion("A", "B");
        red.agregarConexion("A", "B");

        std::cout << red.alcanzablesDesde("A") << std::endl; // Debe imprimir 2
    }
}