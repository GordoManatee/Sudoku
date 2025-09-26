#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Estructura para almacenar la informacion del jugador
struct Jugador {
    string nombre;
    string dificultad;
    int tiempo; // en segundos
};

// Funcion para imprimir la tabla de clasificacion
void imprimirClasificacion(const vector<Jugador>& jugadores) {
    cout << "\n--- Tabla de Clasificacion ---\n";
    for (const auto& j : jugadores) {
        cout << "Jugador: " << j.nombre
             << " | Dificultad: " << j.dificultad
             << " | Tiempo: " << j.tiempo << "s\n";
    }
    cout << "-------------------------------\n";
}

// Merge utilizado en Merge Sort
void merge(vector<Jugador>& jugadores, int izquierda, int medio, int derecha) {
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;

    vector<Jugador> L(n1);
    vector<Jugador> R(n2);

    for (int i = 0; i < n1; i++) L[i] = jugadores[izquierda + i];
    for (int j = 0; j < n2; j++) R[j] = jugadores[medio + 1 + j];

    int i = 0, j = 0, k = izquierda;

    while (i < n1 && j < n2) {
        if (L[i].tiempo <= R[j].tiempo) {
            jugadores[k] = L[i];
            i++;
        } else {
            jugadores[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        jugadores[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        jugadores[k] = R[j];
        j++;
        k++;
    }
}

// Implementacion de Merge Sort
void mergeSort(vector<Jugador>& jugadores, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        mergeSort(jugadores, izquierda, medio);
        mergeSort(jugadores, medio + 1, derecha);
        merge(jugadores, izquierda, medio, derecha);
    }
}

int main() {
    // Datos de ejemplo
    vector<Jugador> jugadores = {
        {"Juan", "Facil", 120},
        {"Mar", "Dificil", 340},
        {"Paris", "Medio", 220},
        {"Carlos", "Facil", 95},
        {"Luis", "Dificil", 410}
    };

    cout << "Clasificacion ORIGINAL:";
    imprimirClasificacion(jugadores);

    // Ordenar por tiempo usando Merge Sort
    mergeSort(jugadores, 0, jugadores.size() - 1);

    cout << "\nClasificacion ORDENADA por tiempo:";
    imprimirClasificacion(jugadores);

    return 0;
}
