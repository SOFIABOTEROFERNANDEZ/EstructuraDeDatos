#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include "Carta.h"
#include "Condicion.h"

class Jugador {
private:
    int id;
    std::vector<Carta> mano;
    int puntos;

public:
    // Constructor
    Jugador(int id_);

    // Métodos principales
    void agregarCarta(const Carta& carta);
    Carta jugarCarta(const Condicion& condicion);
    void sumarPuntos();
    
    // Getters y utilidades
    int getId() const;
    int getPuntos() const;
    const std::vector<Carta>& getMano() const;
};

#endif
