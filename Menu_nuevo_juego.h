#ifndef MENU_NUEVO_JUEGO_H
#define MENU_NUEVO_JUEGO_H
#include "Escena.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "Manito.h"
#include <SFML/System/Clock.hpp>
#include "Juego.h"
#include <SFML/Graphics/RenderWindow.hpp>

class Menu_nuevo_juego : public Escena{
	Texture Fondo_Principal, t_Presentador;
	Sprite Sprite_Principal, s_Presentador;
	Text textoLeo1, textoLeo2;
	Font Fuentecita;
	FloatRect m_r_textin;
	Manito menu_manito;
	Clock relojin;
public:
	Menu_nuevo_juego();
	void Actualizar (Juego &J, RenderWindow &ventanita);
	void Dibujar (RenderWindow & ventanita);
};

#endif

