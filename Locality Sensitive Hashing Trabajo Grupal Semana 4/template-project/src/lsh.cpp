#include "lsh.h"

int distancia_hamming(const string &a, const string &b) {
    int d = 0;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) d++;
    }
    return d;
}

void insertar(LSH &lsh, const Item &item) {
    lsh.base_datos.push_back(item);
}

Item buscar(const LSH &lsh, const string &query, int &candidatos) {
    string q_b1 = query.substr(0, 3);
    string q_b2 = query.substr(3, 3);

    vector<Item> lista_candidatos;

    for (const auto &item : lsh.base_datos) {
        string item_b1 = item.bits.substr(0, 3);
        string item_b2 = item.bits.substr(3, 3);

        if (item_b1 == q_b1 || item_b2 == q_b2) {
            lista_candidatos.push_back(item);
        }
    }

    candidatos = lista_candidatos.size();

    Item mejor = {"", ""};
    int menor_d = 999;

    for (const auto &c : lista_candidatos) {
        int d = distancia_hamming(query, c.bits);
        if (d < menor_d) {
            menor_d = d;
            mejor = c;
        }
    }

    return mejor;
}