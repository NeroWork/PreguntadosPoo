#include "opcion_de_menu.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>

opcion_de_menu::opcion_de_menu() {
	Vector2f tam(200.f,60.f);
	m_rectangulin.setSize(tam);
	Color colorcin(0,0,255);
	m_rectangulin.setFillColor({0,0,50});
	m_rectangulin.setOrigin(100,30);
	m_rectangulin.setPosition(600,300);
	textito.setString("Iniciar Juego");
	Fuentecita.loadFromFile("LibreBaskerville-Regular.ttf");
	textito.setFont(Fuentecita);
	textito.setCharacterSize(30);
	m_r_textin = textito.getLocalBounds();
	textito.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	textito.setPosition(600,300);
}


void opcion_de_menu::dibujar (RenderWindow & w) {
	w.draw(m_rectangulin);
	w.draw(textito);
}

