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
Carta Jugador::seleccionarCarta(
    const Condicion& condicion
) const {
    if (mano.empty()) {
        throw std::runtime_error(
            "El jugador no tiene cartas."
        );
    }
    int mejorIndice = -1;
    for (int i = 0; i < static_cast<int>(mano.size()); i++) {
        if (mano[i].getColor() != condicion.getColor()) {
            continue;
        }
        if (indice == -1) {
            indice = i;
        }
        else if (
            condicion.getOrden() == TipoOrden::MAYOR &&
            mano[i].getNumero() >
            mano[indice].getNumero()
        ) {
            indice = i;
        }
        else if (
            condicion.getOrden() == TipoOrden::MENOR &&
            mano[i].getNumero() <
            mano[indice].getNumero()
        ) {
            indice = i;
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
void Jugador::sumarPuntos(int cantidad) {
    puntos += cantidad;
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
