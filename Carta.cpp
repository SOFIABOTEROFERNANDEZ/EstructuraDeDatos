#include "Carta.h"

Carta::Carta(const std::string& color, int numero)
    : color(color), numero(numero) {}

std::string Carta::getColor() const
{
    return color;
}

int Carta::getNumero() const
{
    return numero;
}

int Carta::obtenerNumero() const
{
    return numero;
}
