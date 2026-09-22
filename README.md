# Manual Oficial del Juego de Cartas Acumulativo

## 1. Descripción General del Proyecto
Este proyecto implementa un juego de cartas digital por turnos, de naturaleza acumulativa y estratégica. El objetivo principal de la mecánica es desafiar a los participantes a gestionar su baraja de manera táctica para acumular la mayor cantidad de puntos posibles a lo largo de las rondas. El sistema distribuye de forma aleatoria una cantidad equitativa de cartas a cada jugador al inicio de la partida. Las cartas combinan diferentes atributos de color y valor numérico, permitiendo escalar el juego a múltiples colores y rangos numéricos configurables.

---

## 2. Componentes del Sistema
* **Baraja y Cartas:** El juego soporta múltiples colores de cartas (escalable según la configuración del sistema). Cada carta posee un color determinado y un valor numérico entero, emulando la dinámica clásica de juegos de cartas por colores y numeración.
* **Jugadores:** Participan dos o más jugadores en una misma sesión de juego, cada uno con una mano de cartas privada y un contador de puntuación acumulada.
* **Sistema de Turnos:** Una estructura secuencial que gestiona el orden de participación, la elección de condiciones y la evaluación de lanzamientos.

---

## 3. Dinámica y Mecánica de la Partida

1. **Reparto Inicial:** Al comenzar la partida, el sistema reparte de manera equitativa y aleatoria un conjunto de cartas a cada jugador desde la baraja principal.
2. **Apertura de Ronda:** Al iniciar cada ronda, el jugador en turno ejerce su rol de líder y tiene la potestad de elegir un comando o condición estratégica que le otorgue ventaja con base en las cartas que posee en su mano. 
3. **Restricciones y Opciones de Condición:** Las opciones de condiciones disponibles dependen directamente de la cantidad de colores activos en la partida. Por cada color presente, se habilitan dos opciones principales:
   * El valor más alto de dicho color.
   * El valor más bajo de dicho color.
4. **Lanzamiento Obligatorio y Simultáneo:** Una vez anunciada la condición por el líder de la ronda, todos los jugadores deben seleccionar y tirar una carta de su mano. 
   * *Regla de participación:* En caso de que un jugador no posea una carta del color exacto solicitado por la condición, de igual manera está obligado a tirar otra carta disponible en su mano para participar en la ronda. Ningún jugador puede pasar su turno sin lanzar una carta.
5. **Evaluación de Resultados y Puntuación:** El sistema revisa de forma automática todas las cartas lanzadas sobre la mesa. Gana la ronda el jugador cuya carta cumpla de manera óptima con la condición impuesta entre todos los participantes. El ganador obtiene los puntos correspondientes a la ronda.
6. **Descarte Definitivo:** Las cartas que han sido jugadas en la ronda actual salen del juego de manera permanente y no pueden volver a ser utilizadas.
7. **Sucesión de Liderazgo:** El ganador de la ronda actual se convierte automáticamente en el líder para la siguiente ronda, adquiriendo el derecho de fijar la nueva condición táctica.

---

## 4. Reglas y Condiciones de Victoria
* **Obligatoriedad de tirada:** Todos los participantes deben aportar obligatoriamente una carta por ronda, independientemente de si disponen o no del color condicionado.
* **Eliminación de cartas jugadas:** Las cartas utilizadas en cada enfrentamiento se descartan de forma definitiva del juego, reduciendo progresivamente las opciones en las manos de los jugadores hasta vaciarlas por completo.
* **Condición de Fin de Partida:** La partida concluye oficialmente cuando se han agotado todas las cartas de las manos de los jugadores.
* **Victoria Absoluta:** El ganador absoluto y campeón de la partida es aquel jugador que, al término de todas las rondas, logre acumular el mayor puntaje total.
