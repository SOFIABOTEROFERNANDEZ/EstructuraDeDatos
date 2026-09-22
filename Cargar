bool Juego::cargarPartida(
    const std::string& nombreArchivo
) {

    std::ifstream archivo(
        nombreArchivo
    );


    if (!archivo.is_open()) {
        return false;
    }


    size_t cantidadColores;

    archivo
        >> cantidadColores;


    colores.clear();


    for (
        size_t i = 0;
        i < cantidadColores;
        i++
    ) {

        std::string color;

        archivo >> color;

        colores.push_back(color);
    }


    archivo
        >> maxNumero;


    archivo
        >> rondaActual;


    archivo
        >> jugadorInicial;


    size_t cantidadJugadores;

    archivo
        >> cantidadJugadores;


    jugadores.clear();


    for (
        size_t i = 0;
        i < cantidadJugadores;
        i++
    ) {

        int id;

        int puntos;

        size_t cantidadCartas;


        archivo
            >> id
            >> puntos
            >> cantidadCartas;


        Jugador jugador(id);


        for (
            size_t j = 0;
            j < cantidadCartas;
            j++
        ) {

            std::string color;

            int numero;


            archivo
                >> color
                >> numero;


            jugador.agregarCarta(
                Carta(color, numero)
            );
        }


        jugador.sumarPuntos(
            puntos
        );


        jugadores.push_back(
            jugador
        );
    }


    baraja =
        Baraja(
            colores,
            maxNumero
        );


    baraja.limpiar();


    size_t cartasRestantes;


    archivo
        >> cartasRestantes;


    for (
        size_t i = 0;
        i < cartasRestantes;
        i++
    ) {

        std::string color;

        int numero;


        archivo
            >> color
            >> numero;


        baraja.agregarCarta(
            Carta(color, numero)
        );
    }


    archivo.close();


    return true;
}
