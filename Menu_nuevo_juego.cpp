#include "Menu_nuevo_juego.h"
#include "Menu.h"
#include <string>
#include <iostream>
#include "Partida.h"
using namespace std;

Menu_nuevo_juego::Menu_nuevo_juego() {
	//Fondo de Pantalla para colocar el nombre del jugador
	Fondo_Principal.loadFromFile("nuevo_juego.jpg");
	Sprite_Principal.setTexture(Fondo_Principal);
	Sprite_Principal.setPosition(0, 0);
	
	//Calculo que tanto debo escalar la imagen para que cubra toda la pantalla
	FloatRect tamFondo = Sprite_Principal.getLocalBounds();
	anchoPantalla = (*((VideoMode::getFullscreenModes()).begin())).width;
	altoPantalla = (*((VideoMode::getFullscreenModes()).begin())).height;
	float scaleX = anchoPantalla/tamFondo.width;
	float scaleY = altoPantalla/tamFondo.height;
	Sprite_Principal.scale(scaleX, scaleY);
	
	//Declaro al presentador
	t_Presentador.loadFromFile("presentador.png");
	t_Presentador.setSmooth(true);
	s_Presentador.setTexture(t_Presentador);
	m_r_textin = s_Presentador.getLocalBounds();
	s_Presentador.setOrigin(0, m_r_textin.height);
	s_Presentador.setPosition(20,altoPantalla);
	s_Presentador.scale(600/anchoPantalla,600/anchoPantalla);
	
	//Texto Presentador
	textoLeo1.setString("Pon tu nombre!");
	Fuentecita.loadFromFile("LibreBaskerville-Regular.ttf");
	textoLeo1.setFont(Fuentecita);
	textoLeo1.setCharacterSize(30);
	textoLeo1.setFillColor(Color(145,0,123,255));
	m_r_textin = textoLeo1.getLocalBounds();
	textoLeo1.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	textoLeo1.setPosition(anchoPantalla/4.8,altoPantalla/1.60);
	
	//Texto del nombre
	textoLeo2.setString("");
	textoLeo2.setFont(Fuentecita);
	textoLeo2.setCharacterSize(60);
	textoLeo2.setFillColor(Color(145,0,123,255));
	m_r_textin = textoLeo2.getLocalBounds();
	textinHeight = m_r_textin.height/2;
	textoLeo2.setOrigin(m_r_textin.width/2,textinHeight);
	textoLeo2.setPosition(anchoPantalla/2,altoPantalla/2.68);
}

//Es el actualizar del Menu_nuevo_juego
void Menu_nuevo_juego::Actualizar (Juego & J, RenderWindow & ventanita) {
	Event e;
	/*Se cambio el segundo while que recibia los eventos, ya que este causaba
	errores al momento de escribir el nombre del ususario*/
	while(ventanita.pollEvent(e)){
		
		if(e.type == Event::TextEntered){
			if(e.text.unicode == 8){
				if(texto_aux.length()>0){
					texto_aux = texto_aux.substr(0,texto_aux.length()-1);
					textoLeo2.setString(texto_aux);
					m_r_textin = textoLeo2.getLocalBounds();
					textoLeo2.setOrigin(m_r_textin.width/2,textinHeight);
				}
			} else{
				if(e.text.unicode == 13){
					if(texto_aux.length()>0){
						J.Cambiar_Escena(new Partida(texto_aux));
					}
				} else {
					if(texto_aux.length() < 12){
						texto_aux = texto_aux + e.text.unicode;
						textoLeo2.setString(texto_aux);
						m_r_textin = textoLeo2.getLocalBounds();
						textoLeo2.setOrigin(m_r_textin.width/2,textinHeight);
					}
				}
			}
		}
	}

	
	//Si precionas escape vuelve al menu principal;
	if(Keyboard::isKeyPressed(Keyboard::Escape) and relojin.getElapsedTime().asSeconds() > 0.5){
		J.Cambiar_Escena(new Menu);
	}
}

//Dibujo todo lo del Menu_nuevo_juego
void Menu_nuevo_juego::Dibujar (RenderWindow & ventanita) {
	ventanita.draw(Sprite_Principal);
	ventanita.draw(textoLeo1);
	ventanita.draw(textoLeo2);
	ventanita.draw(s_Presentador);
}

