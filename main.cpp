#include <iostream>
#include "ListaJugadores.h"
using namespace std;

void seleccionarDificultad(Jugador& j) {
    int opc;
    cout << "\nSelecciona dificultad:\n1. Facil\n2. Media\n3. Dificil\n> ";
    cin >> opc;

    switch (opc) {
        case 1: j.ultimaDificultad = "Facil"; break;
        case 2: j.ultimaDificultad = "Media"; break;
        case 3: j.ultimaDificultad = "Dificil"; break;
        default: j.ultimaDificultad = "Facil"; break;
    }

    j.partidas++;
    cout << "\nIniciando juego... (Sudoku próximamente)\n";
}

int main() {
    ListaJugadores lista;
    lista.cargarDesdeArchivo("jugadores.txt");

    int opcion;
    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Registrar usuario\n";
        cout << "2. Iniciar sesion\n";
        cout << "3. Ver tabla de clasificacion\n";
        cout << "4. Salir\n";
        cout << "> ";
        cin >> opcion;

        switch (opcion) {

            case 1: {
                Jugador nuevo;
                cout << "\nNombre: "; cin >> nuevo.nombre;
                cout << "Contrasena: "; cin >> nuevo.contrasena;
                lista.insertar(nuevo);
                cout << "Usuario registrado.\n";
                break;
            }

            case 2: {
                string name, pass;
                cout << "\nUsuario: "; cin >> name;
                cout << "Contrasena: "; cin >> pass;

                Nodo* n = lista.buscar(name);
                if (n && n->jugador.contrasena == pass) {
                    cout << "Bienvenido " << name << "!\n";
                    seleccionarDificultad(n->jugador);
                } else {
                    cout << "Datos incorrectos.\n";
                }
                break;
            }

            case 3:
                lista.mostrarClasificacion();
                break;

            case 4:
                lista.guardarEnArchivo("jugadores.txt");
                cout << "\nDatos guardados. Saliendo...\n";
                break;

            default:
                cout << "Opción no válida.\n";
        }

    } while (opcion != 4);

    return 0;
}
