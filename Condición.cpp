#include "Condicion.h"

Condicion::Condicion()
    : color(""), orden(TipoOrden::MAYOR) {
}

Condicion::Condicion(const std::string& color, TipoOrden orden)
    : color(color), orden(orden) {
}

std::string Condicion::getColor() const {
    return color;
}

TipoOrden Condicion::getOrden() const {
    return orden;
}
