#include "Condicion.h"

Condicion::Condicion(Color color, TipoOrden tipo)
    : color(color), tipo(tipo) {}

Color Condicion::getColor() const {
    return color;
}

TipoOrden Condicion::getTipo() const {
    return tipo;
}
