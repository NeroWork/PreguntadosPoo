#ifndef PARTIDA_H
#define PARTIDA_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "gestorPreguntas.h"
#include "Manito.h"
using namespace std;

class Partida : public Escena {
private:
	//cosas del fondo;
	Texture Fondo_Principal;
	Sprite Sprite_Principal;
	
	//textos del menu;
	Text tiempo;
	Font Fuentecita;
	FloatRect m_r_textin;
	
	//manito y reloj;
	Manito menu_manito;
	Clock relojin, relojin_aux;
	
	//extras
	string nombre_Usuario;
	gestorPreguntas listita_Preguntas;
	Text textito;
	int cantidad_Correctas=0;
public:
	Partida(string nombreUsuario);
	void Actualizar (Juego & J, RenderWindow & ventanita);
	void Dibujar (RenderWindow & ventanita);
	int verPuntosJugador();
	string verNombreUsuario();
};

#endif

