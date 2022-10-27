#include "Manito.h"
#include <SFML/Graphics/Sprite.hpp>

Manito::Manito() {
	x=600;
	y=300;
	t_manito.loadFromFile("manito.png");
	s_manito.setTexture(t_manito);
	s_manito.setPosition(x,y);
	s_manito.setScale(0.1,0.1);
}

void Manito::Mover_pabajo ( ) {
	if(relojin.getElapsedTime().asSeconds()>0.01){
		y=y+2;
		s_manito.setPosition(x,y);
		relojin.restart();
	}
}

void Manito::dibujar(RenderWindow &w){
w.draw(s_manito);
}

void Manito::Mover_parriba ( ) {
	if(relojin.getElapsedTime().asSeconds()>0.01){
		y=y-2;
		s_manito.setPosition(x,y);
		relojin.restart();
	}
}

void Manito::Mover_paderecha ( ) {
	if(relojin.getElapsedTime().asSeconds()>0.01){
		x=x+2;
		s_manito.setPosition(x,y);
		relojin.restart();
	}
}

void Manito::Mover_paizquierda ( ) {
	if(relojin.getElapsedTime().asSeconds()>0.01){
		x=x-2;
		s_manito.setPosition(x,y);
		relojin.restart();
	}
}

