#include "Baraja.h"

#include <algorithm>
#include <random>
#include <stdexcept>

Baraja::Baraja()
    : maxNumero(10) {
}

Baraja::Baraja(const std::vector<std::string>& colores, int maxNumero)
    : colores(colores), maxNumero(maxNumero) {
}

void Baraja::crearCartas() {

    cartas.clear();

    for (const std::string& color : colores) {

        for (int numero = 1; numero <= maxNumero; numero++) {

            cartas.emplace_back(color, numero);
        }
    }
}

void Baraja::mezclar() {

    std::random_device rd;
    std::mt19937 generador(rd());

    std::shuffle(
        cartas.begin(),
        cartas.end(),
        generador
    );
}

Carta Baraja::sacarCarta() {

    if (cartas.empty()) {
        throw std::runtime_error("La baraja no tiene cartas.");
    }

    Carta carta = cartas.back();

    cartas.pop_back();

    return carta;
}

int Baraja::cartasDisponibles() const {

    return static_cast<int>(cartas.size());
}

const std::vector<Carta>& Baraja::getCartas() const {

    return cartas;
}

void Baraja::agregarCarta(const Carta& carta) {

    cartas.push_back(carta);
}

void Baraja::limpiar() {

    cartas.clear();
}

