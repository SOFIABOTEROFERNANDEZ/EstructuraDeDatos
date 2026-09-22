#include "Jugador.h"

#include <stdexcept>

Jugador::Jugador()
    : id(0), puntos(0) {
}

Jugador::Jugador(int id)
    : id(id), puntos(0) {
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

void Jugador::agregarCarta(const Carta& carta) {

    mano.push_back(carta);
}

bool Jugador::jugarCarta(const Carta& carta) {

    for (auto it = mano.begin(); it != mano.end(); ++it) {

        if (it->getColor() == carta.getColor() &&
            it->getNumero() == carta.getNumero()) {

            mano.erase(it);

            return true;
        }
    }

    return false;
}

void Jugador::sumarPuntos(int cantidad) {

    puntos += cantidad;
}

bool Jugador::tieneColor(const std::string& color) const {

    for (const Carta& carta : mano) {

        if (carta.getColor() == color) {
            return true;
        }
    }

    return false;
}

Carta Jugador::seleccionarCarta(
    const Condicion& condicion
) const {

    if (mano.empty()) {

        throw std::runtime_error(
            "El jugador no tiene cartas."
        );
    }

    int indice = -1;

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

    /*
       Si el jugador no tiene ninguna carta
       del color solicitado, juega la primera
       carta disponible.
    */

    if (indice == -1) {

        indice = 0;
    }

    return mano[indice];
}
