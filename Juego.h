#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Escena.h"
#include "Manito.h"
#include <SFML/Audio/Music.hpp>

class Juego {
	Escena *esc_actual, *esc_siguiente = nullptr;
	RenderWindow ventanita;
	Manito w_manito;
	Music musiquin;
friend class Menu;
public:
	Juego(Escena *EscenaInicio);
	void Cambiar_Escena(Escena *Escena_nueva);
	void Jugar();
	~Juego();
};

#endif

