# Trabajo Grupal - Semana 4: LSH y HyperLogLog

Proyecto para el curso de Estructuras de Datos Avanzadas. Contiene la implementación en C++ de dos algoritmos probabilísticos y de búsqueda aproximada:

1. **Locality Sensitive Hashing (LSH):** Búsqueda aproximada del vecino más cercano sobre firmas binarias con distancia de Hamming.
2. **HyperLogLog (HLL):** Estimación de cardinalidad (elementos únicos) en flujos de datos continuos sin guardar los elementos en memoria.

## Estructura del repositorio

```text
Trabajo_Grupal_Semana4_LSH_HyperLogLog/
├── HyperLogLog Trabajo Grupal Semana 4/
│   ├── apps/
│   │   └── app_main.cpp
│   ├── include/
│   │   └── hyper_log_log.h
│   └── src/
│       └── hyper_log_log.cpp
│
└── Locality Sensitive Hashing Trabajo Grupal Semana 4/
    ├── apps/
    │   └── app_main.cpp
    ├── include/
    │   └── lsh.h
    └── src/
        └── lsh.cpp
```

---

## 1. Locality Sensitive Hashing (LSH)

### Descripción
El objetivo de esta parte es evitar la búsqueda por fuerza bruta ($O(N)$) al momento de encontrar documentos similares:
* Las firmas de 6 bits de cada documento se parten en 2 bandas de 3 bits.
* Si un documento coincide con la consulta en al menos una banda (`b1 == q_b1 || b2 == q_b2`), se guarda como candidato.
* La distancia de Hamming formal solo se calcula sobre los candidatos que pasaron el filtro, descartando el resto sin evaluarlo.

### Compilación y ejecución
```bash
cd "Locality Sensitive Hashing Trabajo Grupal Semana 4"
g++ -std=c++11 -Iinclude src/lsh.cpp apps/app_main.cpp -o main
./main
