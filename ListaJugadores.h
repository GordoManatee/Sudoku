#ifndef LISTA_JUGADORES_H
#define LISTA_JUGADORES_H

#include "Jugador.h"
#include <string>

struct Nodo {
    Jugador jugador;
    Nodo* sig;
    Nodo(const Jugador& j) : jugador(j), sig(nullptr) {}
};

class ListaJugadores {
private:
    Nodo* head;

public:
    ListaJugadores();
    ~ListaJugadores();

    void insertar(const Jugador& j);
    Nodo* buscar(const string& nombre);

    void ordenarPorPartidas();     // algoritmo de ordenamiento
    void mostrarClasificacion();   // imprime tabla ordenada

    void cargarDesdeArchivo(const string& archivo);
    void guardarEnArchivo(const string& archivo);
};

#endif
