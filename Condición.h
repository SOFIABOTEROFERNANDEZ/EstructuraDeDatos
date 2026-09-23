#ifndef CONDICION_H
#define CONDICION_H
#include <string>
#include "TipoOrden.h"

class Condicion {
private:
    std::string color;
    TipoOrden orden;
public:
    Condicion();
    Condicion(const std::string& color, TipoOrden orden);

    std::string getColor() const;
    TipoOrden getOrden() const;
};

#endif

