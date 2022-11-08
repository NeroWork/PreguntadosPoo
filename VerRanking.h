#ifndef VERRANKING_H
#define VERRANKING_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "Partida.h"
using namespace std;

struct losCampeones{
	string player1;
	string puntos1;
	string player2;
	string puntos2;
	string player3;
	string puntos3;
};

class VerRanking : public Escena {
private:
	losCampeones champions;
	Texture Fondo_Principal;
	Sprite Sprite_Principal;
	Text textito;
	Font Fuentecita;
	FloatRect m_r_textin;
	Clock relojin;
	Partida partiditaPa;
public:
	VerRanking();
	void Actualizar (Juego & J, RenderWindow &ventanita);
	void Dibujar (RenderWindow & ventanita);
	bool EnteroComparar(string,int);
};

#endif

