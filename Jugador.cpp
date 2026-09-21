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
