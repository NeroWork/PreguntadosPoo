#ifndef MENU_H
#define MENU_H
#include "Escena.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "Manito.h"
#include "Menu.h"

class Menu : public Escena {
private:
	Texture Fondo_Principal, t_Presentador;
	Sprite Sprite_Principal, s_Presentador;
	Text textoIniciarPartida, textoVerRanking, textoLeo1, textoLeo2;
	Font Fuentecita;
	FloatRect m_r_textin;
	Manito menu_manito;
	Clock relojin;
public:
	Menu();
	void Actualizar (Juego &J, RenderWindow &ventanita);
	void Dibujar (RenderWindow & ventanita);
};

#endif

