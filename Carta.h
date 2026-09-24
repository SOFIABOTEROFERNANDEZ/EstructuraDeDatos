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
    Carta();
    Carta(const std::string& color, int numero);

    std::string getColor() const;
    int getNumero() const;
};

#endif

