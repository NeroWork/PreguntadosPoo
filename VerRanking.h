#ifndef VERRANKING_H
#define VERRANKING_H
#include "Escena.h"
#include <SFML/Graphics.hpp>

class VerRanking : public Escena {
private:
	Texture Fondo_Principal;
	Sprite Sprite_Principal;
	RectangleShape m_rectangulin;
	Text textito;
	Font Fuentecita;
	FloatRect m_r_textin;
	Clock relojin;
public:
	VerRanking();
	void Actualizar (Juego & J, RenderWindow &ventanita);
	void Dibujar (RenderWindow & ventanita);
};

#endif

