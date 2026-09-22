#ifndef CARTA_H
#define CARTA_H

#include <string>
using namespace std;

class Carta
{
private:
    std::string color;
    int numero;

public:
    Carta(const std::string& color = "", int numero = 0);

    std::string getColor() const;
    int getNumero() const;
    int obtenerNumero() const;
};

#endif
