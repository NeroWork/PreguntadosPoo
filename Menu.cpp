#include "Menu.h"
#include <SFML/Window/Keyboard.hpp>
#include "Juego.h"
#include "VerRanking.h"

Menu::Menu() {
	//Fondo de Pantalla Menu
	Fondo_Principal.loadFromFile("fondo1.png");
	Sprite_Principal.setTexture(Fondo_Principal);
	Sprite_Principal.setPosition(0, 0);
	
	//Creacion del Rectangulo donde poner el mensaje
	Vector2f tam(200.f,60.f);
	m_rectangulin.setSize(tam);
	Color colorcin(0,0,255);
	m_rectangulin.setFillColor({0,0,50});
	m_rectangulin.setOrigin(100,30);
	m_rectangulin.setPosition(600,300);
	
	//Texto que se encuentra dentro del rectangulo
	textito.setString("Iniciar Juego");
	Fuentecita.loadFromFile("LibreBaskerville-Regular.ttf");
	textito.setFont(Fuentecita);
	textito.setCharacterSize(30);
	m_r_textin = textito.getLocalBounds();
	textito.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	textito.setPosition(600,300);
}

void Menu::Actualizar (Juego & J) {
	if(Keyboard::isKeyPressed(Keyboard::Space)){
		J.Cambiar_Escena(new VerRanking);
	}
}

void Menu::Dibujar (RenderWindow & ventanita) {
	ventanita.draw(Sprite_Principal);
	ventanita.draw(m_rectangulin);
	ventanita.draw(textito);
}

