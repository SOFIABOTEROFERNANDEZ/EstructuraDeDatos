#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "Carta.h"
#include "Condicion.h"

class Jugador {
private:
    int id;
    std::vector<Carta> mano;
    int puntos;

public:
    Jugador();
    Jugador(int id_);

    int getId() const;
    int getPuntos() const;
    const std::vector<Carta>& getMano() const;

    void agregarCarta(const Carta& carta);
    Carta jugarCarta(const Condicion& condicion);
    void sumarPuntos();
    

};

#endif
