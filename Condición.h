#ifndef CONDICION_H
#define CONDICION_H

#include "Color.h"

enum class TipoOrden {
    MAS_ALTA,
    MAS_BAJA
};

class Condicion {
private:
    Color color;
    TipoOrden tipo;

public:
    Condicion(Color color, TipoOrden tipo);

    Color getColor() const;
    TipoOrden getTipo() const;
};

#endif
