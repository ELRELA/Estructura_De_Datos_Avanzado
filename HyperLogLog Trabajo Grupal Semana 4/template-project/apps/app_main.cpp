#include <iostream>
#include <iomanip>
#include <vector>
#include "hyper_log_log.h"

using namespace std;

int main() {
    cout << fixed << setprecision(2);

    cout << "          PRUEBA DE HYPERLOGLOG (32 BITS)     \n\n";

    int b = 3;
    HyperLogLog hll = crear_hll(b);

    cout << " Flujo con bits iniciales:\n";
    cout << "    - Bits para cubeta (b): " << hll.b << "\n";
    cout << "    - Cubetas totales (m = 2^b): " << hll.m << "\n";

    vector<string> stream = {
        "usuario_1", "usuario_2", "usuario_3", "usuario_1",
        "usuario_4", "usuario_2", "usuario_5", "usuario_1"
    };

    for (const auto &usuario : stream) {
        agregar(hll, usuario);
    }

    cout << "    - Eventos procesados: " << stream.size() << "\n";
    cout << "    - Elementos unicos reales: 5\n";
    cout << "    -> Estimacion HLL: " << estimar(hll) << " elementos\n\n";

    return 0;
}