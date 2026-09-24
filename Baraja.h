#ifndef BARAJA_H
#define BARAJA_H

#include <vector>
#include <string>
#include "Carta.h"

class Baraja {
private:
    std::vector<Carta> cartas;
    std::vector<std::string> colores;
    int maxNumero;

public:
    Baraja();
    Baraja(const std::vector<std::string>& colores, int maxNumero);

    void crearCartas();
    void mezclar();
    Carta sacarCarta();

    int cartasDisponibles() const;

    const std::vector<Carta>& getCartas() const;

    void agregarCarta(const Carta& carta);
    void limpiar();
};

#endif
