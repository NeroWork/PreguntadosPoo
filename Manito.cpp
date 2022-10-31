#include "Manito.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
using namespace sf;
Manito::Manito() {
	t_manito.loadFromFile("manito.png");
	s_manito.setTexture(t_manito);
	s_manito.setScale(0.1,0.1);
}

void Manito::Mover_por_mouse(RenderWindow &ventanita){
	Vector2f Posicion_mouse=Vector2f(Mouse::getPosition(ventanita));
	s_manito.setPosition(Posicion_mouse);
}

void Manito::dibujar(RenderWindow &ventanita){
	ventanita.draw(s_manito);
}

Vector2f Manito::Posicion_manito(){
	return Vector2f(s_manito.getPosition());
}

FloatRect Manito::get_size(){
	return s_manito.getGlobalBounds();
}
