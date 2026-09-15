# Trabajo Grupal - Semana 4: LSH y HyperLogLog

Repositorio que contiene las implementaciones en C++ de algoritmos probabilísticos y de búsqueda aproximada para estructuras de datos avanzadas: **Locality Sensitive Hashing (LSH)** e **HyperLogLog (HLL)**[cite: 1, 4].

---

## Contenido del Repositorio

El proyecto está dividido en dos módulos independientes según el algoritmo aplicado:

### 1. Locality Sensitive Hashing (LSH)
* **Objetivo:** Búsqueda aproximada del vecino más cercano (ANN) sobre documentos clasificados con firmas binarias de 6 bits utilizando la distancia de Hamming[cite: 1, 2].
* **Técnica:** Particionado en bandas (*Banding*) dividiendo las firmas en 2 bloques de 3 bits para filtrar candidatos por colisión antes de evaluar la métrica de distancia[cite: 2, 3].
* **Carpeta:** `Locality Sensitive Hashing Trabajo Grupal Semana 4/`

### 2. HyperLogLog (HLL)
* **Objetivo:** Estimación de cardinalidad (conteo de elementos únicos) en flujos de datos en tiempo real (*streaming*) con memoria constante[cite: 4, 5].
* **Técnica:** Registro de ceros consecutivos sobre hashes de 32 bits distribuidos en $m = 2^b$ cubetas, combinados mediante media armónica y corrección por Linear Counting[cite: 5, 6].
* **Carpeta:** `HyperLogLog Trabajo Grupal Semana 4/`

---

## Estructura General

```text
Trabajo_Grupal_Semana4_LSH_HyperLogLog/
│
├── Locality Sensitive Hashing Trabajo Grupal Semana 4/
│   ├── include/
│   │   └── lsh.h
│   ├── src/
│   │   └── lsh.cpp
│   └── apps/
│       └── app_main.cpp
│
└── HyperLogLog Trabajo Grupal Semana 4/
    ├── include/
    │   └── hyper_log_log.h
    ├── src/
    │   └── hyper_log_log.cpp
    └── apps/
        └── app_main.cpp
```

---

## Compilación y Ejecución

Cada módulo se compila por separado desde su respectiva carpeta utilizando cualquier compilador compatible con C++11 o superior (ej. `g++`).

### Ejecutar Locality Sensitive Hashing

```bash
cd "Locality Sensitive Hashing Trabajo Grupal Semana 4"
g++ -std=c++11 -Iinclude src/lsh.cpp apps/app_main.cpp -o app_lsh
./app_lsh
```

### Ejecutar HyperLogLog

```bash
cd "HyperLogLog Trabajo Grupal Semana 4"
g++ -std=c++11 -Iinclude src/hyper_log_log.cpp apps/app_main.cpp -o app_hll
./app_hll
```

---

## Resultados Esperados

* **LSH:** Permite comprobar cómo el filtrado por bandas descarta registros disímiles y evalúa la distancia de Hamming únicamente sobre los candidatos coincidentes, reduciendo a la mitad las comparaciones necesarias[cite: 1, 3].
* **HyperLogLog:** Procesa eventos con identificadores repetidos y aproxima la cantidad real de elementos únicos sin almacenar el histórico de elementos en memoria[cite: 4, 6].
