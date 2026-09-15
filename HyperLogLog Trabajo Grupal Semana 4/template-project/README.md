# Conteo de Usuarios Únicos en Streaming con HyperLogLog

Aplicación en C++ que implementa el algoritmo probabilístico HyperLogLog para estimar la cardinalidad (cantidad de elementos únicos) en flujos de datos continuos sin necesidad de almacenar los elementos en memoria[cite: 4, 5].

## Descripción del Problema

En sistemas de monitoreo de tráfico y análisis de eventos en tiempo real, guardar cada identificador en una tabla hash o conjunto (`std::set`) consume memoria proporcional a la cantidad de datos procesados[cite: 4]. 

Esta aplicación procesa un flujo continuo de usuarios repetidos y utiliza HyperLogLog sobre hashes de 32 bits para calcular el volumen de usuarios únicos, manteniendo un consumo de memoria mínimo y constante independientemente del número de eventos entrantes[cite: 4, 6].

## Funcionamiento del Algoritmo

El procesamiento de cada elemento del flujo se divide en cuatro etapas[cite: 4, 6]:

* **Inicialización de cubetas:** A partir de $b$ bits iniciales se generan $m = 2^b$ cubetas, inicializadas con $-1$ para representar casilleros vacíos[cite: 5, 6].
* **Direccionamiento a cubeta:** Se calcula el hash de 32 bits de la cadena y se extraen los primeros $b$ bits mediante desplazamientos (`hash >> (32 - b)`) para indexar la cubeta de destino[cite: 6].
* **Registro de ceros finales:** Con los bits restantes del hash, la función `contar_ceros` determina la secuencia de ceros consecutivos y actualiza el récord máximo de esa cubeta si el nuevo valor es mayor[cite: 6].
* **Estimación y Linear Counting:** Se calcula la media armónica sobre los valores registrados en todas las cubetas; si la estimación es baja y existen casilleros sin registrar, se aplica la corrección logarítmica de Linear Counting para corregir el sesgo[cite: 6].

## Estructura del Proyecto

```text
.
├── include/
│   └── hyper_log_log.h
├── src/
│   └── hyper_log_log.cpp
└── apps/
    └── app_main.cpp
```

## Compilación y Ejecución

Compilación estándar desde la raíz con `g++` (requiere C++11 o superior):

```bash
g++ -std=c++11 -Iinclude src/hyper_log_log.cpp apps/app_main.cpp -o app_hll
./app_hll
```

## Ejemplo de Salida

Ejecución del programa configurado con $b = 3$ bits (8 cubetas) procesando un flujo de 8 eventos con 5 usuarios únicos reales[cite: 4]:

```text
          PRUEBA DE HYPERLOGLOG (32 BITS)     

 Flujo con bits iniciales:
    - Bits para cubeta (b): 3
    - Cubetas totales (m = 2^b): 8
    - Eventos procesados: 8
    - Elementos unicos reales: 5
    -> Estimacion HLL: 5.42 elementos
```

A pesar de que el stream recibe entradas repetidas, las colisiones sobre los mismos récords de ceros evitan el sobreconteo y aproximan con precisión la cantidad real de entidades únicas[cite: 4, 6].