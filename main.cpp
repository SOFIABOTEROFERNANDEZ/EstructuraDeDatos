#include "Juego.h"

#include <iostream>
#include <string>

int main() {

    Juego juego;

    int opcion;

    do {

        std::cout << "\n=== JUEGO DE CARTAS ===\n";
        std::cout << "1. Nueva partida\n";
        std::cout << "2. Cargar partida\n";
        std::cout << "3. Salir\n";
        std::cout << "Selecciona: ";

        std::cin >> opcion;

        switch (opcion) {

            case 1:
                juego.configurar();
                juego.iniciarJuego();
                break;

            case 2: {

                std::string nombreArchivo;

                std::cout << "Nombre del archivo a cargar: ";
                std::cin >> nombreArchivo;

                if (juego.cargarPartida(nombreArchivo)) {

                    std::cout << "Partida cargada correctamente.\n";

                    juego.iniciarJuego();

                } else {

                    std::cout << "No se pudo cargar la partida.\n";
                }

                break;
            }

            case 3:
                std::cout << "Hasta luego!\n";
                break;

            default:
                std::cout << "Opcion invalida.\n";
                break;
        }

    } while (opcion != 3);

    return 0;
}
