#ifndef MANITO_H
#define MANITO_H
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;

class Manito {
	Texture t_manito;
	Sprite s_manito;
	int x,y;
    Clock relojin;
public:
	Manito();
	void Mover_pabajo();
	void Mover_parriba();
	void Mover_paderecha();
	void Mover_paizquierda();
	void dibujar(RenderWindow &w);
};

#endif

