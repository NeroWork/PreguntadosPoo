#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Juego;

class Escena {
public:
	Escena();
	virtual void Actualizar(Juego &J) = 0;
	virtual void Dibujar(RenderWindow &ventanita) = 0;
};

#endif

