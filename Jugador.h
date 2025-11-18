#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
using namespace std;

struct Jugador {
    string nombre;
    string contrasena;
    int partidas;         // número de partidas jugadas
    string ultimaDificultad;

    Jugador() : partidas(0), ultimaDificultad("Sin definir") {}
};

#endif
