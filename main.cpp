#include <SFML/Graphics.hpp>
#include "Manito.h"
#include "opcion_de_menu.h"
#include "gestorPreguntas.h"
#include <iostream>
using namespace std;
using namespace sf;





int main(int argc, char *argv[]){
	setlocale(LC_ALL, "spanish");
	RenderWindow w(VideoMode(1200,600),"Parcial de calculo");
	w.setFramerateLimit(60);
	Texture t;
	Sprite s ; 
	
	t.loadFromFile("maxresdefault.jpg");
	s.setTexture(t);
	s.setPosition(0, 0);
	
	opcion_de_menu iniciar_partida;
	
	Manito selector;
	
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			w.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			selector.Mover_pabajo();
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			selector.Mover_parriba();
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			selector.Mover_paderecha();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			selector.Mover_paizquierda();
		}
		w.clear(Color(255,255,255,255));
		w.draw(s);
		iniciar_partida.dibujar(w);
		selector.dibujar(w);
		w.display();
	}
	gestorPreguntas x;
	x.tirarPreguntaAleatoria();
	return 0;
}

