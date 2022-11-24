#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Escena.h"
#include "Manito.h"

class Juego {
	Escena *esc_actual, *esc_siguiente = nullptr;
	RenderWindow ventanita;
	Manito w_manito;
	Image icon;
friend class Menu;
public:
	Juego(Escena *EscenaInicio);
	void Cambiar_Escena(Escena *Escena_nueva);
	void Jugar();
	~Juego();
};

#endif

