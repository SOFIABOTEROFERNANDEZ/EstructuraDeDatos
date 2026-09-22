#include "Juego.h"

#include <fstream>
#include <iostream>

Juego::Juego()
    : rondaActual(1),
      jugadorInicial(0),
      maxNumero(10) {
}

void Juego::configurar() {

    int cantidadJugadores;
    int cantidadColores;

    std::cout
        << "\n=== CONFIGURACION DEL JUEGO ===\n";

    do {

        std::cout
            << "Cantidad de jugadores (2 o mas): ";

        std::cin >> cantidadJugadores;

    } while (cantidadJugadores < 2);


    do {

        std::cout
            << "Cantidad de colores (2 o mas): ";

        std::cin >> cantidadColores;

    } while (cantidadColores < 2);


    colores.clear();

    for (int i = 0;
         i < cantidadColores;
         i++) {

        std::string color;

        std::cout
            << "Nombre del color "
            << i + 1
            << ": ";

        std::cin >> color;

        colores.push_back(color);
    }


    do {

        std::cout
            << "Numero maximo de cada color "
               "(ej. 10): ";

        std::cin >> maxNumero;

    } while (maxNumero < 1);


    baraja =
        Baraja(colores, maxNumero);

    baraja.crearCartas();

    baraja.mezclar();


    int totalCartas =
        baraja.cartasDisponibles();



    if (totalCartas % cantidadJugadores != 0) {

        std::cout
            << "\nLa baraja tiene "
            << totalCartas
            << " cartas y no se puede repartir "
               "equitativamente entre "
            << cantidadJugadores
            << " jugadores.\n";

        std::cout
            << "Cambia la cantidad de jugadores, "
               "colores o numeros.\n";

        jugadores.clear();

        return;
    }


    jugadores.clear();

    for (int i = 0;
         i < cantidadJugadores;
         i++) {

        jugadores.emplace_back(i + 1);
    }


    rondaActual = 1;

    jugadorInicial = 0;


    std::cout
        << "\nJugador 1 comienza la partida.\n";
}

// Repartir Cartas-----------------------------------

  void Juego::repartirCartas() {

    if (
        jugadores.empty() ||
        baraja.cartasDisponibles() == 0
    ) {
        return;
    }


    while (baraja.cartasDisponibles() > 0) {

        for (Jugador& jugador : jugadores) {

            if (baraja.cartasDisponibles() == 0) {
                break;
            }

            jugador.agregarCarta(
                baraja.sacarCarta()
            );
        }
    }
}

// Prueba de disponibilidad de los colores-------------

  bool Juego::colorDisponible(
    const std::string& color
) const {

    for (
        const Jugador& jugador : jugadores
    ) {

        if (jugador.tieneColor(color)) {
            return true;
        }
    }

    return false;
}

// Eleccion de la condicion de la ronda---------------

Condicion Juego::pedirCondicion() const {

    std::cout
        << "\n=== ELIGE LA CONDICION ===\n";


    for (
        int i = 0;
        i < static_cast<int>(colores.size());
        i++
    ) {

        std::cout
            << i + 1
            << ". "
            << colores[i]
            << " mas alto\n";


        std::cout
            << i + 1 +
               static_cast<int>(colores.size())
            << ". "
            << colores[i]
            << " mas bajo\n";
    }


    int opcion;

    int totalOpciones =
        static_cast<int>(colores.size()) * 2;


    do {

        std::cout
            << "Selecciona una opcion: ";

        std::cin >> opcion;


        if (
            opcion < 1 ||
            opcion > totalOpciones
        ) {

            std::cout
                << "Opcion invalida.\n";

            continue;
        }


        int indiceColor;

        TipoOrden orden;


        if (
            opcion <=
            static_cast<int>(colores.size())
        ) {

            indiceColor = opcion - 1;

            orden = TipoOrden::MAYOR;

        } else {

            indiceColor =
                opcion -
                static_cast<int>(colores.size()) -
                1;

            orden = TipoOrden::MENOR;
        }


        if (
            !colorDisponible(
                colores[indiceColor]
            )
        ) {

            std::cout
                << "Ese color ya no esta "
                   "disponible. Elige otro.\n";

            continue;
        }


        return Condicion(
            colores[indiceColor],
            orden
        );

    } while (true);
}

// Mostrar Cartas-------------------------

 void Juego::mostrarMano(
    const Jugador& jugador
) const {

    std::cout
        << "Jugador "
        << jugador.getId()
        << " - Cartas: ";


    for (
        const Carta& carta :
        jugador.getMano()
    ) {

        std::cout
            << "["
            << carta.getColor()
            << " "
            << carta.getNumero()
            << "] ";
    }


    std::cout << "\n";
}

// Mostrar estado del curso de la partida------------------

  void Juego::mostrarEstado() const {

    std::cout
        << "\n=== ESTADO DE LA PARTIDA ===\n";


    std::cout
        << "Ronda: "
        << rondaActual
        << "\n";


    for (
        const Jugador& jugador :
        jugadores
    ) {

        std::cout
            << "Jugador "
            << jugador.getId()

            << " | Puntos: "
            << jugador.getPuntos()

            << " | Cartas: "
            << jugador.getMano().size()

            << "\n";
    }
}

// Jugar Ronda--------------------------------------

  void Juego::iniciarRonda() {

    if (jugadores.empty()) {
        return;
    }


    Jugador& jugadorQueElige =
        jugadores[jugadorInicial];


    std::cout
        << "\n========================================\n";

    std::cout
        << "RONDA "
        << rondaActual
        << "\n";

    std::cout
        << "========================================\n";


    std::cout
        << "Jugador "
        << jugadorQueElige.getId()
        << " decide la condicion.\n";


    mostrarMano(jugadorQueElige);


    Condicion condicion =
        pedirCondicion();


    Ronda ronda(condicion);


    std::cout
        << "\nCondicion elegida: "
        << condicion.getColor();


    if (
        condicion.getOrden() ==
        TipoOrden::MAYOR
    ) {

        std::cout
            << " mas alto\n";

    } else {

        std::cout
            << " mas bajo\n";
    }


    std::cout
        << "\nCartas jugadas:\n";


    ronda.jugar(jugadores);


    for (
        const auto& jugada :
        ronda.getCartasJugadas()
    ) {

        std::cout
            << "Jugador "
            << jugada.first
            << " -> ["
            << jugada.second.getColor()
            << " "
            << jugada.second.getNumero()
            << "]\n";
    }


    if (ronda.getGanador() != -1) {

        std::cout
            << "Ganador de la ronda: "
            << "Jugador "
            << ronda.getGanador()
            << " (+1 punto)\n";


        jugadorInicial =
            ronda.getGanador() - 1;

    } else {

        std::cout
            << "No hubo una carta que "
               "cumpliera la condicion.\n";
    }


    rondaActual++;


    mostrarEstado();
}

// Iniciar la partida----------------------------

  void Juego::iniciarJuego() {

    if (jugadores.empty()) {

        std::cout
            << "Primero debes configurar "
               "una partida.\n";

        return;
    }


    repartirCartas();


    std::cout
        << "\nCartas repartidas correctamente.\n";


    while (true) {

        bool quedanCartas = false;


        for (
            const Jugador& jugador :
            jugadores
        ) {

            if (
                !jugador.getMano().empty()
            ) {

                quedanCartas = true;

                break;
            }
        }


        if (!quedanCartas) {
            break;
        }


        iniciarRonda();


        int opcion;


        std::cout
            << "\n1. Continuar\n";

        std::cout
            << "2. Guardar y salir\n";

        std::cout
            << "Selecciona: ";

        std::cin >> opcion;


        if (opcion == 2) {

            if (
                guardarPartida(
                    "partida.txt"
                )
            ) {

                std::cout
                    << "Partida guardada en "
                       "partida.txt\n";
            }

            return;
        }
    }


    std::cout
        << "\n=== PARTIDA TERMINADA ===\n";


    mostrarResultados();
}

// Mostrar resultados-----------------------

 void Juego::mostrarResultados() const {

    std::cout
        << "\n=== RESULTADOS ===\n";


    int mayorPuntaje = -1;


    for (
        const Jugador& jugador :
        jugadores
    ) {

        std::cout
            << "Jugador "
            << jugador.getId()
            << ": "
            << jugador.getPuntos()
            << " puntos\n";


        if (
            jugador.getPuntos() >
            mayorPuntaje
        ) {

            mayorPuntaje =
                jugador.getPuntos();
        }
    }


    std::cout
        << "\nGanador(es): ";


    for (
        const Jugador& jugador :
        jugadores
    ) {

        if (
            jugador.getPuntos() ==
            mayorPuntaje
        ) {

            std::cout
                << "Jugador "
                << jugador.getId()
                << " ";
        }
    }


    std::cout << "\n";
}

