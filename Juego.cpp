#include "Juego.h"
#include <SFML/Window/Event.hpp>

Juego::Juego(Escena *EscenaInicio) : ventanita(VideoMode((*((VideoMode::getFullscreenModes()).begin())).width,(*((VideoMode::getFullscreenModes()).begin())).height),"PreguntadosPoo", Style::Fullscreen) {
	ventanita.setFramerateLimit(60);
	esc_actual = EscenaInicio;
	ventanita.setMouseCursorVisible(false);
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
		
		esc_actual -> Actualizar(*this, ventanita);
		esc_actual -> Dibujar(ventanita);
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

