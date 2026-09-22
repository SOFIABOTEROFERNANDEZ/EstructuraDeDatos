#include "Juego.h"
#include <iostream>
#include <fstream>
using namespace std;


Juego::Juego(int jugadorInicial, int rondaActual)
    : rondaActual(0),
      jugadorInicial(jugadorInicial),
      totalRondas(rondaActual),
      ultimoGanadorIndice(-1)
{
}

void Juego::iniciarJuego()


