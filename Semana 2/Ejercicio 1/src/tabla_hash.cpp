#include "tabla_hash.h"
#include <iostream>
#include <iomanip>

TablaHash::TablaHash(int tam_inicial) {
    m = tam_inicial;
    n = 0;
    colisiones = 0;
    tabla = new Nodo*[m]();
}

TablaHash::~TablaHash() {
    for (int i = 0; i < m; i++) {
        Nodo* act = tabla[i];
        while (act) {
            Nodo* temp = act;
            act = act->sig;
            delete temp;
        }
    }
    delete[] tabla;
}

int TablaHash::funcion_hash(string k) {
    int h = 0;
    for (char c : k) {
        h = (h * 31 + c) % m;
    }
    return (h < 0) ? h + m : h;
}

bool TablaHash::es_primo(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int TablaHash::siguiente_primo(int x) {
    int p = x + 1;
    while (!es_primo(p)) p++;
    return p;
}

void TablaHash::redimensionar() {
    int nuevo_m = siguiente_primo(2 * m);
    Nodo** nueva_tabla = new Nodo*[nuevo_m]();
    int viejo_m = m;

    m = nuevo_m;
    colisiones = 0;

    for (int i = 0; i < viejo_m; i++) {
        Nodo* act = tabla[i];
        while (act) {
            Nodo* sig = act->sig;
            int pos = funcion_hash(act->clave);

            if (nueva_tabla[pos]) colisiones++;

            act->sig = nueva_tabla[pos];
            nueva_tabla[pos] = act;
            act = sig;
        }
    }

    delete[] tabla;
    tabla = nueva_tabla;
}

bool TablaHash::contiene(string clave) {
    int pos = funcion_hash(clave);
    for (Nodo* act = tabla[pos]; act; act = act->sig) {
        if (act->clave == clave) return true;
    }
    return false;
}

bool TablaHash::insertar(string clave, Estudiante valor) {
    if (contiene(clave)) return false;

    if ((double)(n + 1) / m > 0.75) {
        redimensionar();
    }

    int pos = funcion_hash(clave);
    if (tabla[pos]) colisiones++;

    tabla[pos] = new Nodo(clave, valor, tabla[pos]);
    n++;
    return true;
}

bool TablaHash::buscar(string clave, Estudiante &res) {
    int pos = funcion_hash(clave);
    for (Nodo* act = tabla[pos]; act; act = act->sig) {
        if (act->clave == clave) {
            res = act->valor;
            return true;
        }
    }
    return false;
}

bool TablaHash::actualizar(string clave, Estudiante valor) {
    int pos = funcion_hash(clave);
    for (Nodo* act = tabla[pos]; act; act = act->sig) {
        if (act->clave == clave) {
            act->valor = valor;
            return true;
        }
    }
    return false;
}

bool TablaHash::eliminar(string clave) {
    int pos = funcion_hash(clave);
    Nodo* act = tabla[pos];
    Nodo* ant = nullptr;

    while (act) {
        if (act->clave == clave) {
            if (!ant) tabla[pos] = act->sig;
            else ant->sig = act->sig;
            delete act;
            n--;
            return true;
        }
        ant = act;
        act = act->sig;
    }
    return false;
}

void TablaHash::mostrar_estadisticas() {
    int max_len = 0;
    for (int i = 0; i < m; i++) {
        int len = 0;
        for (Nodo* act = tabla[i]; act; act = act->sig) len++;
        if (len > max_len) max_len = len;
    }

    cout << fixed << setprecision(2);
    cout << "\nESTADISTICAS\n";
    cout << "Tamano de la tabla: " << m << "\n";
    cout << "Numero de elementos: " << n << "\n";
    cout << "Factor de carga: " << (double)n / m << "\n";
    cout << "Numero total de colisiones: " << colisiones << "\n";
    cout << "Longitud maxima de las cadenas: " << max_len << "\n";
    cout << "Longitud promedio de las cadenas: " << (double)n / m << "\n\n";
}