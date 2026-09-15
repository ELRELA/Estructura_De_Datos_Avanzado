# Detección de Documentos Similares con LSH

Aplicación en C++ que implementa Locality Sensitive Hashing (LSH) para la búsqueda aproximada del vecino más cercano (ANN) sobre documentos clasificados por firmas binarias de 6 bits bajo la distancia de Hamming[cite: 1, 2].

## Descripción del Problema

En lugar de realizar una búsqueda lineal exhaustiva evaluando distancias contra toda la colección de textos, la aplicación indexa registros con firmas temáticas (como deportes y cine) y aplica un filtro previo para descartar elementos disímiles sin calcular distancias sobre ellos[cite: 1, 2].

## Funcionamiento del Algoritmo

El proceso de descarte opera mediante particionado en bandas (*Banding*) y muestreo de bits (*Bit-Sampling*)[cite: 3]:

* **Particionado en bandas:** Cada firma de 6 bits se segmenta en dos bloques contiguos de 3 bits cada uno (`substr(0, 3)` y `substr(3, 3)`)[cite: 3].
* **Filtrado de candidatos:** Un registro califica como candidato relevante si colisiona con la consulta en al menos una de sus bandas (`item_b1 == q_b1 || item_b2 == q_b2`)[cite: 3].
* **Verificación de similitud:** La función `distancia_hamming` se ejecuta de forma exclusiva sobre la lista de candidatos que superaron el filtro, seleccionando al vecino más cercano[cite: 3].

## Estructura del Proyecto

```text
.
├── include/
│   └── lsh.h
├── src/
│   └── lsh.cpp
└── apps/
    └── app_main.cpp
```

## Compilación y Ejecución

Compilación estándar desde la raíz con `g++`:

```bash
g++ -std=c++11 -Iinclude src/lsh.cpp apps/app_main.cpp -o app_lsh
./app_lsh
```

## Ejemplo de Salida

Ejecución de la consulta `111000` sobre una base de 4 documentos cargados en memoria[cite: 1]:

```text
Query: 111000
Vecino mas cercano: doc_deportes_1 (111000)
Distancia Hamming: 0
Candidatos evaluados: 2 de 4
```

El algoritmo procesa únicamente a los 2 candidatos coincidentes en las bandas temáticas, descartando los registros restantes y reduciendo el costo computacional de la métrica en un 50%[cite: 1, 3].