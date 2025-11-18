#include "ListaJugadores.h"
#include <iostream>
#include <fstream>
using namespace std;

ListaJugadores::ListaJugadores() {
    head = nullptr;
}

ListaJugadores::~ListaJugadores() {
    while (head != nullptr) {
        Nodo* temp = head;
        head = head->sig;
        delete temp;
    }
}

void ListaJugadores::insertar(const Jugador& j) {
    Nodo* nuevo = new Nodo(j);
    nuevo->sig = head;
    head = nuevo;
}

Nodo* ListaJugadores::buscar(const string& nombre) {
    Nodo* temp = head;
    while (temp != nullptr) {
        if (temp->jugador.nombre == nombre)
            return temp;
        temp = temp->sig;
    }
    return nullptr;
}

void ListaJugadores::ordenarPorPartidas() {
    if (!head || !head->sig) return;

    bool cambiado;
    do {
        cambiado = false;
        Nodo* actual = head;

        while (actual->sig != nullptr) {
            if (actual->jugador.partidas < actual->sig->jugador.partidas) {

                Jugador temp = actual->jugador;
                actual->jugador = actual->sig->jugador;
                actual->sig->jugador = temp;

                cambiado = true;
            }
            actual = actual->sig;
        }
    } while (cambiado);
}

void ListaJugadores::mostrarClasificacion() {
    ordenarPorPartidas();

    cout << "\n--- Tabla de Clasificacion ---\n";
    Nodo* temp = head;
    while (temp != nullptr) {
        cout << "Jugador: " << temp->jugador.nombre
             << " | Partidas: " << temp->jugador.partidas
             << " | Ultima dificultad: " << temp->jugador.ultimaDificultad << endl;
        temp = temp->sig;
    }
    cout << "-----------------------------\n";
}

void ListaJugadores::cargarDesdeArchivo(const string& archivo) {
    ifstream in(archivo);
    if (!in.is_open()) return;

    Jugador j;
    while (in >> j.nombre >> j.contrasena >> j.partidas >> j.ultimaDificultad) {
        insertar(j);
    }

    in.close();
}

void ListaJugadores::guardarEnArchivo(const string& archivo) {
    ofstream out(archivo);
    if (!out.is_open()) return;

    Nodo* temp = head;
    while (temp != nullptr) {
        out << temp->jugador.nombre << " "
            << temp->jugador.contrasena << " "
            << temp->jugador.partidas << " "
            << temp->jugador.ultimaDificultad << "\n";
        temp = temp->sig;
    }

    out.close();
}
