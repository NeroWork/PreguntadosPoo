#include "Juego.h"
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <SFML/Audio/Music.hpp>
using namespace std;

Juego::Juego(Escena *EscenaInicio) : ventanita(VideoMode((*((VideoMode::getFullscreenModes()).begin())).width,(*((VideoMode::getFullscreenModes()).begin())).height),"PreguntadosPoo", Style::Fullscreen) {
	ventanita.setFramerateLimit(60);
	esc_actual = EscenaInicio;
	ventanita.setMouseCursorVisible(false);

	if(!musiquin.openFromFile("Musiquin.wav")){
		cout<<"No se puede cargar la musica"<<endl;
	}
	musiquin.setVolume(20);
	musiquin.setLoop(true);
	musiquin.play();
}


void Juego::Cambiar_Escena (Escena * Escena_nueva) {
	esc_siguiente = Escena_nueva;
}

void Juego::Jugar ( ) {
	while(ventanita.isOpen()){
		
		Event e;
		if(ventanita.pollEvent(e)){
			if(e.type == Event::Closed){
				musiquin.stop();
				ventanita.close();
			}
		}
		
		ventanita.clear(Color(255,255,255,255));
		
		esc_actual -> Dibujar(ventanita);
		esc_actual -> Actualizar(*this, ventanita);
		w_manito.dibujar(ventanita);
		w_manito.Mover_por_mouse(ventanita);
		
		if(esc_siguiente){
			delete esc_actual;
			esc_actual = esc_siguiente;
			esc_siguiente = nullptr;
		}
		
		ventanita.display();
	}
}

Juego::~Juego ( ) {
	
}

