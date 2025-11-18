# Proyecto: Lista de jugadores

Este proyecto implementa un sistema de gestion de torneos con equipos, partidos y tabla de clasificacion. El programa permite registrar equipos, registrar partidos, actualizar estadisticas automaticamente, consultar informacion y guardar/cargar datos desde archivos.

## Descripcion del avance 1

En este avance se creo la estructura basica del programa: clases principales, menu inicial y primeras funciones de registro de equipos. Se definieron las estructuras de datos fundamentales (vector de equipos) y las operaciones basicas.

### Cambios sobre el primer avance

1. Se agrego la clase Partido: para permitir el registro formal de resultados. Este cambio fue necesario para poder generar estadisticas reales.
2. Se reorganizo el menu principal: para hacerlo mas claro y preparar el avance 3.
3. Se mejoro la estructura Equipo con nuevos atributos: goles, puntos, etc., necesarios para la tabla.


## Descripcion del avance 2

En el avance 2 se implementaron nuevas caracteristicas como el registro de partidos, la actualizacion automatica de estadisticas y la generacion de una tabla de clasificacion interna sin archivos. Tambien se reorganizo el menu principal.

### Cambios sobre el segundo avance

1. Se agrego lectura y escritura de archivos: requerido por la competencia SICT0303.
2. Se implemento tabla de clasificacion en lugar de usuarios registrados: porque es mas relevante al problema del torneo.
3. Se agrego ordenamiento por puntos usando algoritmo eficiente (quicksort): necesario para la tabla de clasificacion.
4. Se modularizo en .h y .cpp: para mejorar claridad y cumplir buenas practicas.

## Descripcion del avance 3

En este avance se completo el sistema agregando la tabla de clasificacion, mecanismos completos de lectura/escritura de archivos, y el reemplazo de la seccion "usuarios registrados" por "tabla de clasificacion". Tambien se mejoro la modularidad con archivos .h separados y se agrego analisis de complejidad.

## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando:

```
g++ main.cpp Equipo.cpp Partido.cpp Utils.cpp -std=c++11 -o tercer_avance
```

## Instrucciones para ejecutar el avance de proyecto

```
./tercer_avance
```

## Descripcion de las entradas del avance de proyecto

El programa utiliza dos archivos de entrada:

1. **equipos.txt**
   Formato:

   ```
   nombre_equipo,puntos,goles_favor,goles_contra
   ```

2. **partidos.txt**
   Formato:

   ```
   equipo_local,equipo_visitante,goles_local,goles_visitante
   ```

Ejemplo de equipos.txt:

```
Tigres,10,12,4
Rayados,7,8,6
```

Ejemplo de partidos.txt:

```
Tigres,Rayados,2,1
```

## Descripcion de las salidas del avance de proyecto

El programa genera y actualiza automaticamente:

* Tabla de clasificacion ordenada por puntos y diferencia de goles.
* archivos equipos.txt y partidos.txt actualizados
* mensajes en consola mostrando informacion consultada por el usuario.

---

# Desarrollo de competencias

## SICT0301: Evalua los componentes

### Analisis de complejidad de algoritmos de ordenamiento

Se uso quicksort para ordenar la tabla de clasificacion.

* Caso promedio: O(n log n)
* Peor caso: O(n^2)
  Se eligio debido a que n (equipos) es pequeno y su promedio es adecuado.

### Analisis de complejidad de todas las estructuras y sus usos

* Vector de equipos: insercion O(1), acceso O(1), busqueda O(n)
* Vector de partidos: insercion O(1), acceso O(1), busqueda O(n)
  El uso es eficiente porque n es pequeno y las operaciones mas frecuentes son accesos directos.

### Analisis del resto de componentes y complejidad final

Funciones principales:

* Registrar equipo: O(1)
* Registrar partido: O(1)
* Actualizar estadisticas: O(1) por partido
* Generar tabla de clasificacion: O(n log n)
  Complejidad total del programa: **O(n log n)** dominada por la generacion de la tabla.

---

## SICT0302: Toma decisiones

### Seleccion de algoritmo de ordenamiento

Se eligio quicksort por su eficiencia promedio y simplicidad de implementacion. Esto es adecuado dado el tamano reducido de equipos.

### Seleccion de estructuras de datos

Se eligieron vectores porque:

* Se requiere acceso rapido
* El tamano cambia poco
* Son faciles de manejar con archivos
  Esto los hace adecuados para el problema.

---

## SICT0303: Implementa acciones cientificas

### Mecanismos para consultar informacion

Se implementaron funciones de busqueda, consulta individual y generacion de tabla. Permiten recuperar datos de forma correcta usando las estructuras existentes.

### Lectura de archivos

Se implementaron funciones que leen linea por linea, separan datos por comas y los convierten a objetos Equipo y Partido.
Se validan formatos antes de procesar.

### Escritura de archivos

Se implementaron funciones que recorren los vectores y escriben en archivos con formato CSV.
Esto asegura que los datos puedan cargarse correctamente mas adelante.

