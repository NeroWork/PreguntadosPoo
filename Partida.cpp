#include "Partida.h"
#include <SFML/Window.hpp>
#include <string>
#include <SFML/System/Vector2.hpp>
#include "Juego.h"
#include "Menu.h"
#include <sstream>
using namespace std;

Partida::Partida(string nombreUsuario) :  nombre_Usuario(nombreUsuario){
	//Fondo de Pantalla Menu
	Fondo_Principal.loadFromFile("partida.jpg");
	Sprite_Principal.setTexture(Fondo_Principal);
	Sprite_Principal.setPosition(0, 0);
	//Calculo que tanto debo escalar la imagen para que cubra toda la pantalla
	FloatRect tamFondo = Sprite_Principal.getLocalBounds();
	float anchoPantalla = (*((VideoMode::getFullscreenModes()).begin())).width;
	float altoPantalla = (*((VideoMode::getFullscreenModes()).begin())).height;
	float scaleX = anchoPantalla/tamFondo.width;
	float scaleY = altoPantalla/tamFondo.height;
	Sprite_Principal.scale(scaleX, scaleY);
	
	//Texto tiempo
	tiempo.setString("20");
	Fuentecita.loadFromFile("LibreBaskerville-Regular.ttf");
	tiempo.setFont(Fuentecita);
	tiempo.setCharacterSize(60);
	tiempo.setFillColor(Color(255,108,18,255));
	m_r_textin = tiempo.getLocalBounds();
	tiempo.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	tiempo.setPosition(anchoPantalla/1.05,altoPantalla/60);
	
	relojin.restart();
	relojin_aux.restart();
	
}

void Partida::Actualizar (Juego & J, RenderWindow & ventanita) {
//	if(Mouse::isButtonPressed(Mouse::Left)){
//		Vector2i posicion_mouse=Mouse::getPosition(ventanita);
//		posicion_mouse=(Vector2i)ventanita.mapPixelToCoords(posicion_mouse);
//		FloatRect posicion_manito(Vector2f(posicion_mouse),Vector2f(1,1));
//		
//		string Opcion_Elegida;
//		if(textito.getGlobalBounds().intersects(posicion_manito)){
//			Opcion_Elegida=listita_Preguntas.tirar_OpcionA().substr(0,1);
//		}
//		
//		if(textito.getGlobalBounds().intersects(posicion_manito)){
//			Opcion_Elegida=listita_Preguntas.tirar_OpcionB().substr(0,1);
//		}
//		
//		if(textito.getGlobalBounds().intersects(posicion_manito)){
//			Opcion_Elegida=listita_Preguntas.tirar_OpcionC().substr(0,1);
//		}
//		
//		if(textito.getGlobalBounds().intersects(posicion_manito)){
//			Opcion_Elegida=listita_Preguntas.tirar_OpcionD().substr(0,1);
//		}
//		
//		if(textito.getGlobalBounds().intersects(posicion_manito)){
//			Opcion_Elegida=listita_Preguntas.tirar_OpcionE().substr(0,1);
//		}
//		
//		if(Opcion_Elegida==listita_Preguntas.tirar_Respuesta()){
//			cantidad_Correctas++;
//		}
//	}
	if(relojin_aux.getElapsedTime().asSeconds() >= 1){
		string aux = tiempo.getString();
		stringstream ss;
		ss << aux;
		int x;
		ss >> x;
		if(x > 0){
			x--;
			ss.clear();
			ss << x;
			ss >> aux;
			tiempo.setString(aux);
			relojin_aux.restart();
		}
	}
	if(Keyboard::isKeyPressed(Keyboard::Escape)){
		J.Cambiar_Escena(new Menu);
	}
}

void Partida::Dibujar (RenderWindow & ventanita) {
	ventanita.draw(Sprite_Principal);
	ventanita.draw(tiempo);
}

int Partida::verPuntosJugador(){
	return cantidad_Correctas;
}

string Partida::verNombreUsuario(){
	return nombre_Usuario;
}
