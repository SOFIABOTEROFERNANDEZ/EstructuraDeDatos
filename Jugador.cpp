#include "Jugador.h"
#include <iostream>

Jugador::Jugador(int id_) : id(id_), puntos(0) {}
void Jugador::agregarCarta(const Carta& carta) {
  mano.push_back(carta);
}
Carta Jugador::jugarCarta(const Condicion& condicion) {
  if (mano.empty()) {
        throw std::runtime_error("El jugador no tiene cartas en la mano.");
    }
