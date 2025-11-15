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
    }

    int contarCriticos(int umbral)
    {
    }

    void imprimirCriticos(int umbral)
    {
    }

    RegistroSensoresABB() : raiz(nullptr) {}

private:
    Nodo *raiz;
};

// Test
void testingRegistroSensoresABB()
{
    {
        RegistroSensoresABB sistema;

        sistema.insertar(42);
        sistema.insertar(35);
        sistema.insertar(50);
        sistema.insertar(47);

        sistema.imprimirCriticos(42); // Debe imprimir: Sensores criticos (temp >= 42): 3
    }

    {
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
    }

    // Devuelve true si existe conexión directa entre a y b
    bool estanConectados(const string &a, const string &b)
    {
    }

    // Devuelve cuántos módulos son alcanzables desde el módulo de inicio (incluido), usando DFS
    int alcanzablesDesde(const string &inicio)
    {
    }

private:
    void dfs(const string &actual, set<string> &visitados)
    {
    }
};

// Test
void testingRedDeSensores()
{
    {
        RedDeSensores red;

        red.agregarConexion("A", "B");

        std::cout << (red.estanConectados("A", "B") ? "Si" : "No") << std::endl; // Si
        std::cout << (red.estanConectados("A", "C") ? "Si" : "No") << std::endl; // No
    }

    {
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
        RedDeSensores red;

        red.agregarConexion("M1", "M2");

        std::cout << (red.estanConectados("M2", "M1") ? "Si" : "No") << std::endl; // Si

        red.agregarConexion("A", "B");
        red.agregarConexion("A", "B");

        std::cout << red.alcanzablesDesde("A") << std::endl; // Debe imprimir 2
    }
}