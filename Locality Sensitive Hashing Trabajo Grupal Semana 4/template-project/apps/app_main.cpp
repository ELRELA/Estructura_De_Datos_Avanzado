#include <iostream>
#include "lsh.h"

using namespace std;

int main() {
    LSH lsh;

    insertar(lsh, {"doc_deportes_1", "111000"});
    insertar(lsh, {"doc_deportes_2", "111001"});
    insertar(lsh, {"doc_cine_1",     "000111"});
    insertar(lsh, {"doc_cine_2",     "000110"});

    string query = "111000";
    int evaluados = 0;
    Item res = buscar(lsh, query, evaluados);

    cout << "Query: " << query << "\n";
    cout << "Vecino mas cercano: " << res.id << " (" << res.bits << ")\n";
    cout << "Distancia Hamming: " << distancia_hamming(query, res.bits) << "\n";
    cout << "Candidatos evaluados: " << evaluados << " de 4\n";

    return 0;
}