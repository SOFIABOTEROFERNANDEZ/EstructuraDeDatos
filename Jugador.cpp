#include "Jugador.h"
#include <iostream>
#include <stdexcept>

Jugador::Jugador()
    : id(0), puntos(0) {
}
Jugador::Jugador(int id)
    : id(id), puntos(0) {
}
void Jugador::agregarCarta(const Carta& carta) {
    mano.push_back(carta);
}


Carta Jugador::jugarCarta(const Condicion& condicion) {
    if (mano.empty()) {
        throw std::runtime_error("El jugador no tiene cartas en la mano.");
    }

    int mejorIndice = -1;

    // Buscar entre las cartas de la mano las que coincidan con el color de la condicion
    for (size_t i = 0; i < mano.size(); ++i) {
        if (mano[i].getColor() == condicion.getColor()) {
            if (mejorIndice == -1) {
                mejorIndice = static_cast<int>(i);
            } else {
                bool esMejor = false;
                if (condicion.getTipo() == TipoOrden::MAS_ALTA) {
                    esMejor = mano[i].obtenerNumero() > mano[mejorIndice].obtenerNumero();
                } else { // MAS_BAJA
                    esMejor = mano[i].obtenerNumero() < mano[mejorIndice].obtenerNumero();
                }

                if (esMejor) {
                    mejorIndice = static_cast<int>(i);
                }
            }
        }
    }

    // Si no tiene cartas del color pedido
    if (mejorIndice == -1) {
        mejorIndice = 0;
        for (size_t i = 1; i < mano.size(); ++i) {
            if (mano[i].obtenerNumero() < mano[mejorIndice].obtenerNumero()) {
                mejorIndice = static_cast<int>(i);
            }
        }
    }

    // Extraer la carta elegida de la mano y retornarla
    Carta cartaSeleccionada = mano[mejorIndice];
    mano.erase(mano.begin() + mejorIndice);

    return cartaSeleccionada;
}

void Jugador::sumarPuntos() {
    puntos++;
}

int Jugador::getId() const {
    return id;
}

int Jugador::getPuntos() const {
    return puntos;
}

const std::vector<Carta>& Jugador::getMano() const {
    return mano;
}
