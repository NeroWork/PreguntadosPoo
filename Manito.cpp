#include "Manito.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
using namespace sf;
Manito::Manito() {
	x=600;
	y=300;
	t_manito.loadFromFile("manito.png");
	s_manito.setTexture(t_manito);
	s_manito.setPosition(x,y);
	s_manito.setScale(0.1,0.1);
}

void Manito::Mover_por_mouse(RenderWindow &ventanita){
	Vector2f Posicion_mouse=Vector2f(Mouse::getPosition(ventanita));
	s_manito.setPosition(Posicion_mouse);
}

void Manito::Mover_pabajo ( ) {
	if(relojin.getElapsedTime().asSeconds()>0.01){
		y=y+2;
		s_manito.setPosition(x,y);
		relojin.restart();
	}
}

void Manito::dibujar(RenderWindow &ventanita){
ventanita.draw(s_manito);
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

Vector2f Manito::Posicion_manito(){
	return Vector2f(s_manito.getPosition());
}

Vector2f Manito::Tamano_textura(){
	return Vector2f(t_manito.getSize());
}
