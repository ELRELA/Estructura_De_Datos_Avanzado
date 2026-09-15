#include <iostream>
#include "tabla_hash.h"

using namespace std;

int main() {
    TablaHash tabla(7);

    cout << "INSERTAR 20260001 Ana 16.5\n";
    tabla.insertar("20260001", {"20260001", "Ana", 16.5});

    cout << "INSERTAR 20260002 Luis 14.0\n";
    tabla.insertar("20260002", {"20260002", "Luis", 14.0});

    cout << "BUSCAR 20260001\n";
    Estudiante e;
    if (tabla.buscar("20260001", e)) {
        cout << "-> Encontrado: " << e.codigo << " " << e.nombres << " " << e.promedio << "\n";
    }

    cout << "ELIMINAR 20260002\n";
    if (tabla.eliminar("20260002")) {
        cout << "-> Eliminado con exito\n";
    }

    tabla.mostrar_estadisticas();

    return 0;
}