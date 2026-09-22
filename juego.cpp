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
{
    int numJugadores = 0;
    cout << "=== Juego de Cartas ===\n";
    while (numJugadores < 2)
    {
        cout << "Numero de jugadores (minimo 2): ";
        cin >> numJugadores;
    }

    jugadores.clear();
    for (int i = 0; i < numJugadores; i++)
    {
        jugadores.push_back(Jugador(i + 1));
    }

    if (jugadorInicial < 0 || jugadorInicial >= numJugadores)
    {
        jugadorInicial = 0;
    }

    coloresDisponibles.clear();
    for (const Carta& c : baraja.getCartas())
    {
        bool existe = false;
        for (const string& col : coloresDisponibles)
        {
            if (col == c.getColor()) { existe = true; break; }
        }
        if (!existe) coloresDisponibles.push_back(c.getColor());
    }

    baraja.mezclar();
    repartirCartas();

    rondaActual = 0;
    while (rondaActual < totalRondas)
    {
        bool alguienSinCartas = false;
        for (Jugador& j : jugadores)
        {
            if (j.cartasEnMano() == 0) { alguienSinCartas = true; break; }
        }
        if (alguienSinCartas)
        {
            cout << "\nYa no quedan cartas suficientes para todos, termina el juego.\n";
            break;
        }

        rondaActual++;
        cout << "\n--- Ronda " << rondaActual << " ---\n";
        iniciarRonda();
        cambioJugadorInicial();
    }

    mostrarResultados();
}

void Juego::repartirCartas()
