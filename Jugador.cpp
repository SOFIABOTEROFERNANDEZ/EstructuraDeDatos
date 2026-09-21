#include "Jugador.h"
#include <iostream>

Jugador::Jugador(int id_) : id(id_), puntos(0) {}
void Jugador::agregarCarta(const Carta& carta) {
  mano.push_back(carta);
}
