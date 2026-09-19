#ifndef RONDA_H
#define RONDA_H

#include <vector>
#include "Condicion.h"
#include "Carta.h"
#include "Jugador.h"

class Ronda {
private:
    Condicion condicion;
    std::vector<Carta> cartasJugadas;
    Jugador* ganador;

public:
   
    Ronda(Condicion condicion);
    void jugar(std::vector<Jugador*>& jugadores);
    Jugador* elegirGanador(std::vector<Jugador*>& jugadores);
    Jugador* getGanador() const;
    const std::vector<Carta>& getCartasJugadas() const;
};

#endif
