#include "hyper_log_log.h"
#include <cmath>
#include <functional>

using namespace std;

HyperLogLog crear_hll(int b_bits) {
    HyperLogLog hll;
    hll.b = b_bits;
    hll.m = 1 << b_bits;
    hll.buckets.assign(hll.m, -1);
    return hll;
}

int contar_ceros(uint32_t valor) {
    if (valor == 0) return 0;
    int ceros = 0;
    while (valor % 2 == 0) {
        ceros++;
        valor /= 2;
    }
    return ceros;
}

void agregar(HyperLogLog &hll, const string &elemento) {
    uint32_t hash_completo = static_cast<uint32_t>(hash<string>{}(elemento));

    int bits_a_descartar = 32 - hll.b;
    int cubeta = hash_completo >> bits_a_descartar;

    uint32_t hash_sin_inicio = hash_completo << hll.b;
    uint32_t bits_restantes = hash_sin_inicio >> hll.b;

    int ceros_finales = contar_ceros(bits_restantes);

    if (ceros_finales > hll.buckets[cubeta]) {
        hll.buckets[cubeta] = ceros_finales;
    }
}

double estimar(const HyperLogLog &hll) {
    double suma_inversa = 0.0;
    int casilleros_vacios = 0;

    for (int ceros : hll.buckets) {
        if (ceros == -1) {
            casilleros_vacios++;
            suma_inversa += 1.0;
        } else {
            suma_inversa += pow(2.0, -ceros);
        }
    }

    double media_armonica = static_cast<double>(hll.m) / suma_inversa;
    double estimacion = 0.79 * hll.m * media_armonica;

    if (estimacion <= 2.5 * hll.m && casilleros_vacios > 0) {
        estimacion = hll.m * log(static_cast<double>(hll.m) / casilleros_vacios);
    }

    return estimacion;
}