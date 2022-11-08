#ifndef PARTIDA_H
#define PARTIDA_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "gestorPreguntas.h"
using namespace std;

class Partida : public Escena {
private:
	string nombre_Usuario;
	gestorPreguntas listita_Preguntas;
	Text textito;
	int cantidad_Correctas;
public:
	Partida();
	void Actualizar (Juego & J, RenderWindow & ventanita);
	void Dibujar (RenderWindow & ventanita);
	int verPuntosJugador();
	string verNombreUsuario();
};

#endif

