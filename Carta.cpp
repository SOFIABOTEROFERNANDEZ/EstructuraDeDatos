#include "Carta.h"

Carta::Carta() : color(""), numero(0) {
}

Carta::Carta(const std::string& color, int numero)
    : color(color), numero(numero) {
        
}

std::string Carta::getColor() const {
    return color;
}

int Carta::getNumero() const {
    return numero;
}

