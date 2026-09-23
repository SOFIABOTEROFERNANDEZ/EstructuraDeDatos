#ifndef RONDA_H
#define RONDA_H

#include <vector>
#include <utility>
#include "Condicion.h"
#include "Carta.h"
#include "jugador.h"

class Ronda {
private:
    Condicion condicion;

    std::vector<std::pair<int, Carta>> cartasJugadas;

    int ganador;


public:
    Ronda();
    explicit Ronda(const Condicion& condicion);
    void jugar(std::vector<Jugador>& jugadores);
    int elegirGanador() const;
    Condicion getCondicion() const;
    const std::vector<std::pair<int, Carta>>&
    getCartasJugadas() const;
    int getGanador() const;
};

#endif

