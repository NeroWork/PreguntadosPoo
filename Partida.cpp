#include "Partida.h"
#include <SFML/Window.hpp>
#include <string>
#include <SFML/System/Vector2.hpp>
#include "Juego.h"
using namespace std;

Partida::Partida() {
	
}

void Partida::Actualizar (Juego & J, RenderWindow & ventanita) {
	if(Mouse::isButtonPressed(Mouse::Left)){
		Vector2i posicion_mouse=Mouse::getPosition(ventanita);
		posicion_mouse=(Vector2i)ventanita.mapPixelToCoords(posicion_mouse);
		FloatRect posicion_manito(Vector2f(posicion_mouse),Vector2f(1,1));
		
		string Opcion_Elegida;
		if(textito.getGlobalBounds().intersects(posicion_manito)){
			Opcion_Elegida=listita_Preguntas.tirar_OpcionA().substr(0,1);
		}
		
		if(textito.getGlobalBounds().intersects(posicion_manito)){
			Opcion_Elegida=listita_Preguntas.tirar_OpcionB().substr(0,1);
		}
		
		if(textito.getGlobalBounds().intersects(posicion_manito)){
			Opcion_Elegida=listita_Preguntas.tirar_OpcionC().substr(0,1);
		}
		
		if(textito.getGlobalBounds().intersects(posicion_manito)){
			Opcion_Elegida=listita_Preguntas.tirar_OpcionD().substr(0,1);
		}
		
		if(textito.getGlobalBounds().intersects(posicion_manito)){
			Opcion_Elegida=listita_Preguntas.tirar_OpcionE().substr(0,1);
		}
		
		if(Opcion_Elegida==listita_Preguntas.tirar_Respuesta()){
			cantidad_Correctas++;
		}
	}
}

void Partida::Dibujar (RenderWindow & ventanita) {
	
}

int Partida::verPuntosJugador(){
	return cantidad_Correctas;
}

string Partida::verNombreUsuario(){
	return nombre_Usuario;
}
