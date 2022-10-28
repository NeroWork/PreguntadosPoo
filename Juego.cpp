#include "Juego.h"
#include <SFML/Window/Event.hpp>

Juego::Juego(Escena *EscenaInicio) : ventanita(VideoMode(1200,600),"PreguntadosPoo") {
	ventanita.setFramerateLimit(60);
	esc_actual = EscenaInicio;
}


void Juego::Cambiar_Escena (Escena * Escena_nueva) {
	esc_siguiente = Escena_nueva;
}

void Juego::Jugar ( ) {
	while(ventanita.isOpen()){
		Event e;
		while(ventanita.pollEvent(e)){
			if(e.type == Event::Closed){
				ventanita.close();
			}
		}
		
		ventanita.clear(Color(255,255,255,255));
		
		esc_actual -> Actualizar(*this);
		esc_actual -> Dibujar(ventanita);
		
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

