#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include <string>

#include "Baraja.h"
#include "Jugador.h"
#include "Ronda.h"

class Juego {

private:

    std::vector<Jugador> jugadores;

    Baraja baraja;

    int rondaActual;

    int jugadorInicial;

    std::vector<std::string> colores;

    int maxNumero;

    bool colorDisponible(
        const std::string& color
    ) const;

    Condicion pedirCondicion() const;

    void mostrarMano(
        const Jugador& jugador
    ) const;

    void mostrarEstado() const;

public:

    Juego();

    void configurar();

    void repartirCartas();

    void iniciarJuego();

    void iniciarRonda();

    void mostrarResultados() const;

    bool guardarPartida(
        const std::string& nombreArchivo
    ) const;

    bool cargarPartida(
        const std::string& nombreArchivo
    );
};

#endif
