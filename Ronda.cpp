#include "Ronda.h"

Ronda::Ronda(Condicion condicion)
    : condicion(condicion), ganador(nullptr) {}

void Ronda::jugar(std::vector<Jugador*>& jugadores) {
    cartasJugadas.clear();
    for (Jugador* jugador : jugadores) {
        Carta cartaTirada = jugador->jugarCarta(condicion);
        cartasJugadas.push_back(cartaTirada);
    }

    ganador = elegirGanador(jugadores);

   
    if (ganador != nullptr) {
        ganador->sumarPuntos();
    }
}

Jugador* Ronda::elegirGanador(std::vector<Jugador*>& jugadores) {
    int indiceGanador = -1;

    for (size_t i = 0; i < cartasJugadas.size(); i++) {
        if (cartasJugadas[i].getColor() == condicion.getColor()) {
            if (indiceGanador == -1) {
                indiceGanador = static_cast<int>(i);
            } else {
                bool esMejor = false;
                if (condicion.getTipo() == TipoOrden::MAS_ALTA) {
                    esMejor = cartasJugadas[i].obtenerNumero()
                              > cartasJugadas[indiceGanador].obtenerNumero();
                } else {
                    esMejor = cartasJugadas[i].obtenerNumero()
                              < cartasJugadas[indiceGanador].obtenerNumero();
                }
                if (esMejor) {
                    indiceGanador = static_cast<int>(i);
                }
            }
        }
    }

    
    if (indiceGanador == -1) {
        return nullptr;
    }

    return jugadores[indiceGanador];
}

Jugador* Ronda::getGanador() const {
    return ganador;
}

const std::vector<Carta>& Ronda::getCartasJugadas() const {
    return cartasJugadas;
}
