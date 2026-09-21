#include "Carta.h"

Carta::Carta(string color, int numero)
{
    this->color = color;
    this->numero = numero;
}

string Carta::getColor()
{
    return color;
}

int Carta::getNumero()
{
    return numero;
}