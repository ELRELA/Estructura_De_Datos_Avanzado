#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#include <string>

using namespace std;

struct Estudiante {
    string codigo;
    string nombres;
    double promedio;
};

struct Nodo {
    string clave;
    Estudiante valor;
    Nodo* sig;
    Nodo(string c, Estudiante v, Nodo* s = nullptr) : clave(c), valor(v), sig(s) {}
};

class TablaHash {
private:
    int m;
    int n;
    int colisiones;
    Nodo** tabla;

    int funcion_hash(string k);
    bool es_primo(int x);
    int siguiente_primo(int x);
    void redimensionar();

public:
    TablaHash(int tam_inicial = 7);
    ~TablaHash();

    bool insertar(string clave, Estudiante valor);
    bool buscar(string clave, Estudiante &res);
    bool eliminar(string clave);
    bool actualizar(string clave, Estudiante valor);
    bool contiene(string clave);
    void mostrar_estadisticas();
};

#endif