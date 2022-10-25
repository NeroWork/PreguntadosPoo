#ifndef OPCION_DE_MENU_H
#define OPCION_DE_MENU_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class opcion_de_menu {
	RectangleShape m_rectangulin;
	Text textito;
	Font Fuentecita;
	FloatRect m_r_textin;
public:
	opcion_de_menu();
	void dibujar(RenderWindow &w);
};

#endif

