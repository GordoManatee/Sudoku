# Proyecto: Sudoku con tabla de clasificacion

Este proyecto consiste en desarrollar un juego de Sudoku con niveles de dificultad y un sistema de tabla de clasificacion que registre a los jugadores, su historial de partidas y tiempos de resolucion. El objetivo es combinar el desarrollo del juego con estructuras de datos eficientes y algoritmos de ordenamiento para organizar la informacion de manera clara y escalable.

## Descripción del avance 1

En el primer avance se implementó un programa en C++ que permitía:

* Registrar jugadores con nombre y contraseña.
* Iniciar sesión con un usuario existente.
* Elegir dificultad para jugar (Facil, Media, Dificil) después de crear cuenta o iniciar sesión.
* Visualizar los jugadores registrados.

Se utilizó una estructura `struct Jugador` para almacenar la información de manera natural y modular, preparando la base para integrar posteriormente el Sudoku y los tiempos de juego.

## Descripción del avance 2

En este segundo avance se mejoró la organización de los datos y se implementó un **algoritmo de ordenamiento (Merge Sort)** para mostrar la **tabla de clasificación ordenada alfabéticamente por nombre de jugador**. Ahora el programa permite:

* Crear usuarios con contraseña.
* Iniciar sesión con un usuario existente.
* Elegir dificultad después de crear cuenta o iniciar sesión.
* Visualizar la **tabla de clasificación organizada** por nombre de jugador.
* Mantener todos los datos en memoria usando la estructura `struct Jugador`.

### Cambios sobre el primer avance

1. **Implementación de tabla de clasificación ordenada:** Se decidió mostrar la lista de jugadores ordenada alfabéticamente usando Merge Sort para aplicar un algoritmo de ordenamiento de manera útil y cumplir con el objetivo de organizar los datos.
2. **Integración de opción de “jugar” después de crear usuario o iniciar sesión:** Esto prepara la base para vincular posteriormente la dificultad y los tiempos de Sudoku con cada usuario.
3. **Eliminación de tiempos de partida por el momento:** Se simplifica la estructura para centrarse en registrar usuarios y organizar los datos, dejando la puerta abierta para incluir los tiempos en futuros avances.
4. **Cambio de “usuarios registrados” a “tabla de clasificación”:** Se adapta la interfaz a la finalidad del proyecto y se mejora la presentación de los datos ordenados.

## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

```bash
g++ main.cpp -std=c++11 -o segundo_avance
```

## Instrucciones para ejecutar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

```bash
./segundo_avance
```

## Descripción de las entradas del avance de proyecto

* El programa solicita al usuario ingresar datos de **registro**: nombre de usuario y contraseña.
* Al iniciar sesión, se solicita nombre y contraseña existentes.
* Después de registrarse o iniciar sesión, el usuario selecciona la dificultad (Facil, Media, Dificil).

Ejemplo de entrada:

```
1
Juan
1234
2
```

## Descripción de las salidas del avance de proyecto

* Mensajes de confirmación de registro o inicio de sesión.
* Dificultad seleccionada para jugar.
* Tabla de clasificación ordenada alfabéticamente por nombre de jugador, mostrando la última dificultad seleccionada.

Ejemplo de salida:

```
Jugador: Ana | Ultima dificultad jugada: Media
Jugador: Juan | Ultima dificultad jugada: Facil
Jugador: Maria | Ultima dificultad jugada: Dificil
```

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

Se implementó **Merge Sort** para ordenar la tabla de clasificación por nombre de jugador. La complejidad de Merge Sort es **O(n log n)** en el mejor, promedio y peor de los casos, lo que permite organizar los datos de manera eficiente incluso con muchos registros. Este análisis permite entender cómo el algoritmo afectará el rendimiento del sistema.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

* **Vector de jugadores:** permite agregar usuarios al final en **O(1)**, acceder a cualquier usuario por índice en **O(1)** y recorrer todos los usuarios en **O(n)**.
* **Estructura `Jugador`:** organiza de forma natural los datos de cada usuario (nombre, contraseña, dificultad).
* **Uso conjunto:** combinar `vector` y `struct` permite almacenar y ordenar la información eficientemente, preparar futuras funcionalidades como registro de tiempos y Sudoku.

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Se eligió **Merge Sort** porque el objetivo es mostrar la tabla de clasificación ordenada alfabéticamente. Merge Sort es eficiente, estable y escalable para cualquier número de jugadores.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.

Se seleccionó **vector + struct** porque permite almacenar múltiples jugadores con información asociada de manera ordenada y flexible. Esto facilita agregar nuevas propiedades en futuros avances (como tiempos y partidas) y permite aplicar algoritmos de ordenamiento y consulta.

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructuras correctos.

Se implementaron funciones específicas para consultar los datos:

* `mostrarClasificacion()`: recorre el vector de jugadores y muestra los datos ordenados.
* `seleccionarDificultad()`: permite asignar información relevante a cada jugador.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

Aunque en este avance los datos se almacenan solo en memoria, el diseño está preparado para **lectura/escritura de archivos** en futuros avances, lo que permitirá cargar usuarios desde un archivo `usuarios.txt` y mantener su progreso.