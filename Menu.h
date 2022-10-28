#ifndef MENU_H
#define MENU_H
#include "Escena.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>

class Menu : public Escena {
private:
	Texture Fondo_Principal;
	Sprite Sprite_Principal;
	RectangleShape m_rectangulin;
	Text textito;
	Font Fuentecita;
	FloatRect m_r_textin;
public:
	Menu();
	void Actualizar (Juego & J);
	void Dibujar (RenderWindow & ventanita);
};

#endif
