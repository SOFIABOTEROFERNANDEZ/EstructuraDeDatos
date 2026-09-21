#ifndef BARAJA_H
#define BARAJA_H

#include <vector>
#include <string>
#include "Carta.h"

using namespace std;

class Baraja
{
private:
    vector<Carta> cartas;

public:
    Baraja();

    void crearCartas();
    void mezclar();
    Carta sacarCarta();

    int cartasDisponibles();

    vector<Carta> getCartas();
};

#endif