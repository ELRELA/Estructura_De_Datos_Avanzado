#ifndef LSH_H
#define LSH_H

#include <string>
#include <vector>

using namespace std;

struct Item {
    string id;
    string bits;
};

struct LSH {
    vector<Item> base_datos;
};

int distancia_hamming(const string &a, const string &b);
void insertar(LSH &lsh, const Item &item);
Item buscar(const LSH &lsh, const string &query, int &candidatos);

#endif