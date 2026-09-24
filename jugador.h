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
    bool jugarCarta(const Carta& carta);
    void sumarPuntos(int cantidad);
    bool tieneColor(const std::string& color) const;

    Carta seleccionarCarta(const Condicion& condicion) const;
    Carta elegirCarta(const Condicion& condicion) const;
};

#endif
