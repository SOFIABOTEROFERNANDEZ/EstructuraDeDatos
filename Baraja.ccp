#include "Baraja.h"
#include <algorithm>
#include <random>

Baraja::Baraja()
{
    crearCartas();
}

void Baraja::crearCartas()
{
    vector<string> colores =
    {
        "Azul",
        "Rojo",
        "Verde",
        "Amarillo",
        "Morado",
        "Naranja"
    };

    for (string color : colores)
    {
        for (int numero = 1; numero <= 9; numero++)
        {
            cartas.push_back(Carta(color, numero));
        }
    }
}

void Baraja::mezclar()
{
    random_device semilla;
    mt19937 generador(semilla());

    shuffle(cartas.begin(), cartas.end(), generador);
}

Carta Baraja::sacarCarta()
{
    Carta carta = cartas.back();
    cartas.pop_back();

    return carta;
}

int Baraja::cartasDisponibles()
{
    return cartas.size();
}

vector<Carta> Baraja::getCartas()
{
    return cartas;
}