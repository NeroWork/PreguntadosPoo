#ifndef VERRANKING_H
#define VERRANKING_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "Partida.h"
using namespace std;

class VerRanking : public Escena {
private:
	struct losCampeones{
		string player1;
		string puntos1;
		string player2;
		string puntos2;
		string player3;
		string puntos3;
	};
	losCampeones champions;
	Texture Fondo_Principal;
	Sprite Sprite_Principal;
	RectangleShape m_rectangulin;
	Text primeroRAnking;
	Text segundoRanking;
	Text terceroRanking;
	Font Fuentecita;
	FloatRect m_r_textin;
	Clock relojin;
	Partida partiditaPa;
	int AnchoPantalla;
public:
	VerRanking();
	void Actualizar (Juego & J, RenderWindow &ventanita);
	void Dibujar (RenderWindow & ventanita);
	bool EnteroComparar(string,int);
};

#endif

