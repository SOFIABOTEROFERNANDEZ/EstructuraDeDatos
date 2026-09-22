#include "Ronda.h"

Ronda::Ronda()
    : condicion(), ganador(-1) {
}

Ronda::Ronda(const Condicion& condicion)
    : condicion(condicion), ganador(-1) {
}

void Ronda::jugar(std::vector<Jugador>& jugadores) {

    cartasJugadas.clear();

    ganador = -1;

    for (Jugador& jugador : jugadores) {

        if (jugador.getMano().empty()) {
            continue;
        }

        Carta carta =
            jugador.seleccionarCarta(condicion);

        jugador.jugarCarta(carta);

        cartasJugadas.push_back(
            {jugador.getId(), carta}
        );
    }

    ganador = elegirGanador();

    if (ganador != -1) {

        for (Jugador& jugador : jugadores) {

            if (jugador.getId() == ganador) {

                jugador.sumarPuntos(1);

                break;
            }
        }
    }
}

int Ronda::elegirGanador() const {

    int ganadorId = -1;

    int mejorNumero = 0;

    bool encontrado = false;

    for (const auto& jugada : cartasJugadas) {

        const Carta& carta = jugada.second;


        if (carta.getColor() != condicion.getColor()) {
            continue;
        }

        if (!encontrado) {

            encontrado = true;

            mejorNumero = carta.getNumero();

            ganadorId = jugada.first;

            continue;
        }

        if (
            condicion.getOrden() == TipoOrden::MAYOR &&
            carta.getNumero() > mejorNumero
        ) {

            mejorNumero = carta.getNumero();

            ganadorId = jugada.first;
        }

        if (
            condicion.getOrden() == TipoOrden::MENOR &&
            carta.getNumero() < mejorNumero
        ) {

            mejorNumero = carta.getNumero();

            ganadorId = jugada.first;
        }
    }

    return ganadorId;
}

Condicion Ronda::getCondicion() const {

    return condicion;
}

const std::vector<std::pair<int, Carta>>&
Ronda::getCartasJugadas() const {

    return cartasJugadas;
}

int Ronda::getGanador() const {

    return ganador;
}
