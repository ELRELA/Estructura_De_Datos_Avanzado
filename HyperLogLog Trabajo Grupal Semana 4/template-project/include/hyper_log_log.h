#ifndef HYPER_LOG_LOG_H
#define HYPER_LOG_LOG_H

#include <vector>
#include <string>
#include <cstdint>

using namespace std;

struct HyperLogLog {
    int b;
    int m;
    vector<int> buckets;
};

HyperLogLog crear_hll(int b_bits);
int contar_ceros(uint32_t valor);
void agregar(HyperLogLog &hll, const string &elemento);
double estimar(const HyperLogLog &hll);

#endif