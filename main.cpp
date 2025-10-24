#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Estructura para almacenar los datos de un jugador
struct Jugador {
    string nombre;
    string contrasena;
    string dificultad; // Ultima dificultad jugada
};

// Funcion para imprimir la tabla de clasificacion
void mostrarClasificacion(const vector<Jugador>& jugadores) {
    cout << "\n--- Tabla de Clasificacion ---\n";
    if (jugadores.empty()) {
        cout << "No hay jugadores registrados.\n";
        return;
    }
    for (const auto& j : jugadores) {
        cout << "Jugador: " << j.nombre
             << " | Ultima dificultad jugada: " << j.dificultad << "\n";
    }
    cout << "-------------------------------\n";
}

// Funcion para seleccionar dificultad
void seleccionarDificultad(Jugador& jugador) {
    int opcion;
    cout << "\n--- Seleccion de dificultad ---\n";
    cout << "1. Facil\n";
    cout << "2. Media\n";
    cout << "3. Dificil\n";
    cout << "Selecciona una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            jugador.dificultad = "Facil";
            break;
        case 2:
            jugador.dificultad = "Media";
            break;
        case 3:
            jugador.dificultad = "Dificil";
            break;
        default:
            cout << "Opcion no valida, se asigna dificultad Facil por defecto.\n";
            jugador.dificultad = "Facil";
    }

    cout << "Dificultad seleccionada: " << jugador.dificultad << "\n";
    cout << "Comenzando el juego... (proximamente aqui ira el Sudoku)\n";
}

// Funcion para registrar un nuevo usuario
void registrarUsuario(vector<Jugador>& jugadores) {
    Jugador nuevo;
    cout << "\n--- Registro de nuevo jugador ---\n";
    cout << "Nombre de usuario: ";
    cin >> nuevo.nombre;

    // Verificar si el usuario ya existe
    for (const auto& j : jugadores) {
        if (j.nombre == nuevo.nombre) {
            cout << "El nombre de usuario ya esta en uso. Intenta con otro.\n";
            return;
        }
    }

    cout << "Crea una contrasena: ";
    cin >> nuevo.contrasena;
    nuevo.dificultad = "Sin definir";

    jugadores.push_back(nuevo);
    cout << "Usuario registrado exitosamente.\n";

    // Permitir jugar despues de crear usuario
    seleccionarDificultad(jugadores.back());
}

// Funcion para iniciar sesion con un usuario existente
void iniciarSesion(vector<Jugador>& jugadores) {
    string nombre, contrasena;
    cout << "\n--- Iniciar sesion ---\n";
    cout << "Nombre de usuario: ";
    cin >> nombre;
    cout << "Contrasena: ";
    cin >> contrasena;

    for (auto& j : jugadores) {
        if (j.nombre == nombre && j.contrasena == contrasena) {
            cout << "Bienvenido, " << j.nombre << "! Has iniciado sesion correctamente.\n";
            seleccionarDificultad(j);
            return;
        }
    }

    cout << "Usuario o contrasena incorrectos.\n";
}

// Programa principal
int main() {
    vector<Jugador> jugadores;
    int opcion;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Registrar nuevo jugador\n";
        cout << "2. Iniciar sesion\n";
        cout << "3. Ver tabla de clasificacion\n";
        cout << "4. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarUsuario(jugadores);
                break;
            case 2:
                iniciarSesion(jugadores);
                break;
            case 3:
                mostrarClasificacion(jugadores);
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }

    } while (opcion != 4);

    return 0;
}
