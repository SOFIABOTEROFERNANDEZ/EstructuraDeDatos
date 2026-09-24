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
    if (indice == -1) {
        indice = 0;
    }
    return mano[indice];
}
Carta Jugador::elegirCarta(const Condicion& condicion) const {
    if (mano.empty()) {
        throw std::runtime_error(
            "El jugador no tiene cartas."
        );
    }
    bool debeRespetarColor =
        tieneColor(condicion.getColor());
    int indiceElegido = -1;
    do {
        std::cout
            << "\nTurno del Jugador "
            << id
            << "\n";
        std::cout << "Tus cartas:\n";
        for (
            int i = 0;
            i < static_cast<int>(mano.size());
            i++
        ) {
            std::cout
                << "  "
                << i + 1
                << ". ["
                << mano[i].getColor()
                << " "
                << mano[i].getNumero()
                << "]\n";
        }
        if (debeRespetarColor) {
            std::cout
                << "Debes jugar una carta de color "
                << condicion.getColor()
                << " (la tienes en tu mano).\n";
        }
        std::cout
            << "Elige una carta (1-"
            << mano.size()
            << "): ";
        int opcion;
        std::cin >> opcion;
        if (
            std::cin.fail()
        ) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrada invalida.\n";
            continue;
        }
        if (
            opcion < 1 ||
            opcion > static_cast<int>(mano.size())
        ) {
            std::cout << "Opcion invalida.\n";
            continue;
        }
        int indice = opcion - 1;
        if (
            debeRespetarColor &&
            mano[indice].getColor() != condicion.getColor()
        ) {
            std::cout
                << "Esa carta no es de color "
                << condicion.getColor()
                << ". Debes jugar una carta de ese color.\n";
            continue;
        }
        indiceElegido = indice;
    } while (indiceElegido == -1);
    return mano[indiceElegido];
}

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
