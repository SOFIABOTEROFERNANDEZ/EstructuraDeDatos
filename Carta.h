#ifndef CARTA_H
#define CARTA_H

#include <string>
using namespace std;

class Carta
{
private:
    string color;
    int numero;

public:
    Carta(string color, int numero);

    string getColor();
    int getNumero();
};

#endif