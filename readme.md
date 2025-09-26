# Proyecto: Sudoku con sistema de clasificacion y dificultad

Este proyecto pone en marcha un sistema sencillo para la tabla clasificatoria de jugadores de un sudoku. La idea principal, demostrar el uso de algoritmos de ordenamiento, para ordenar a los jugadores basándose en el tiempo.

## Descripción del avance 1

En este primer avance, se implementa lo siguiente:

Una estructura `Jugador` para guardar nombre, dificultad y tiempo, es el sistema de clasificaciones del sudoku.
Una función para imprimir la tabla clasificatoria en la pantalla.
El algoritmo Merge Sort para ordenar a los jugadores según el tiempo que tomaron.
Ejemplos de jugadores predefinidos que se ordenan y se muestran en la consola.

## Instrucciones para compilar el avance del proyecto

Debes ejecutar el siguiente comando en la terminal:

`g++ main. cpp -std=c++11 -o primer_avance`

## Instrucciones para ejecutar el avance del proyecto

Hay que ejecutar este comando en la terminal:

`. /primer_avance`

## Descripción de las entradas del avance del proyecto

En este avance, no hay entradas externas de archivos o desde el usuarioy y aun no e implemetado el sudoku.
Los datos de los jugadores se establecen directo en el código:

```cpp
vector jugadores = {
{"Juan", "Facil", 120},
{"Mar", "Dificil", 340},
{"Paris", "Medio", 220},
{"Carlos", "Facil", 95},
{"Luis", "Dificil", 410}
};
```

Cada jugador, bueno, tiene tres datos:

1. Nombre (string).
2. Dificultad (string).
3. Tiempo (entero, en segundos) ah.

## Descripción de las salidas del avance del proyecto

El programa imprime en consola:

1. La clasificación original con los datos, tal como fueron definidos.
2. La clasificación ordenada por tiempo utilizando Merge Sort, así.

Ejemplo de salida que ves:

```
Clasificacion ORIGINAL:
Jugador: Juan | Dificultad: Facil | Tiempo: 120s
Jugador: Mar | Dificultad: Dificil | Tiempo: 340s
Jugador: Paris | Dificultad: Medio | Tiempo: 220s
Jugador: Carlos | Dificultad: Facil | Tiempo: 95s
Jugador: Luis | Dificultad: Dificil | Tiempo: 410s
-------------------------------

Clasificacion ORDENADA por tiempo:
Jugador: Carlos | Dificultad: Facil | Tiempo: 95s
Jugador: Juan | Dificultad: Facil | Tiempo: 120s
Jugador: Paris | Dificultad: Medio | Tiempo: 220s
Jugador: Mar | Dificultad: Dificil | Tiempo: 340s
Jugador: Luis | Dificultad: Dificil | Tiempo: 410s
-------------------------------
```

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Realiza un análisis de complejidad correcto y completo de los algoritmos de ordenamiento empleado en el programa.

En este avance, se implementa el algoritmo Merge Sort, este tiene una complejidad temporal O(n log n) en el mejor, promedio, y peor caso, ya vez.
Esto es lo que obtuve:

Eso hace de esto un algoritmo súper eficiente para clasificar largas listas de datos, esto frente a algoritmos como Bubble Sort o Insertion Sort, cuya complejidad es O(n²).
El despliegue de esta destreza se puede ver en la escogencia de un algoritmo eficiente y en la implementación de la funcion `mergeSort`.

### SICT0302: Tomando decisiones

#### Elige un algoritmo de clasificación conveniente para el problema y lo usa correctamente.

La decisión de usar Merge Sort se debe a que asegura un desempeño estable y clasifica a los jugadores óptimamente sin importar cómo empiezam los datos. En el programa, lo usan bien, dividiendo la lista, clasificando cada mitad recursivamente y fusionando los resultados al final.
El progreso de esta competencia se aprecia en la correcta implementación de las funciones `merge` y `mergeSort` como en la aplicación en el vector de jugadores, antes de imprimir la clasificación final.
