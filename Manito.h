#ifndef MANITO_H
#define MANITO_H
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;

class Manito {
	Texture t_manito;
	Sprite s_manito;
public:
	Manito();
	Vector2f Posicion_manito();
	FloatRect get_size();
	void dibujar(RenderWindow &ventanita);
	void Mover_por_mouse(RenderWindow &ventanita);
};

#endif

