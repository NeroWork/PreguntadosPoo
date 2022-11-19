#include "Menu.h"
#include <SFML/Window/Keyboard.hpp>
#include "Juego.h"
#include "VerRanking.h"
#include "Manito.h"
#include <iostream>
#include "Menu_nuevo_juego.h"
using namespace std;

Menu::Menu() {
	//Fondo de Pantalla Menu
	Fondo_Principal.loadFromFile("fondo169_1920_1080.png");
	Sprite_Principal.setTexture(Fondo_Principal);
	Sprite_Principal.setPosition(0, 0);
	//Calculo que tanto debo escalar la imagen para que cubra toda la pantalla
	FloatRect tamFondo = Sprite_Principal.getLocalBounds();
	float anchoPantalla = (*((VideoMode::getFullscreenModes()).begin())).width;
	float altoPantalla = (*((VideoMode::getFullscreenModes()).begin())).height;
	float scaleX = anchoPantalla/tamFondo.width;
	float scaleY = altoPantalla/tamFondo.height;
	Sprite_Principal.scale(scaleX, scaleY);
	
	//Texto de inicio de partida;
	textoIniciarPartida.setString("Iniciar Juego");
	Fuentecita.loadFromFile("LibreBaskerville-Regular.ttf");
	textoIniciarPartida.setFont(Fuentecita);
	textoIniciarPartida.setCharacterSize(60);
	textoIniciarPartida.setFillColor(Color(145,0,123,255));
	m_r_textin = textoIniciarPartida.getLocalBounds();
	textoIniciarPartida.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	textoIniciarPartida.setPosition(anchoPantalla/2.003,altoPantalla/2.5);
	
	//Texto ver ranking;
	textoVerRanking.setString("Ver Ranking");
	textoVerRanking.setFont(Fuentecita);
	textoVerRanking.setCharacterSize(60);
	textoVerRanking.setFillColor(Color(145,0,123,255));
	m_r_textin = textoVerRanking.getLocalBounds();
	textoVerRanking.setOrigin(m_r_textin.width/2, m_r_textin.height/2);
	textoVerRanking.setPosition(anchoPantalla/2.003, altoPantalla/1.82);
	
	//Texto LEO1;
	textoLeo1.setString("Presiona ESC");
	textoLeo1.setFont(Fuentecita);
	textoLeo1.setCharacterSize(35);
	textoLeo1.setFillColor(Color(145,0,123,255));
	m_r_textin = textoLeo1.getLocalBounds();
	textoLeo1.setOrigin(m_r_textin.width/2, m_r_textin.height/2);
	textoLeo1.setPosition(anchoPantalla/4.8, altoPantalla/1.63);
	
	//Texto LEO2;
	textoLeo2.setString("para salir!");
	textoLeo2.setFont(Fuentecita);
	textoLeo2.setCharacterSize(35);
	textoLeo2.setFillColor(Color(145,0,123,255));
	m_r_textin = textoLeo2.getLocalBounds();
	textoLeo2.setOrigin(m_r_textin.width/2, m_r_textin.height/2);
	textoLeo2.setPosition(anchoPantalla/4.8, altoPantalla/1.52);
	
	//Declaro al presentador
	t_Presentador.loadFromFile("presentador.png");
	t_Presentador.setSmooth(true);
	s_Presentador.setTexture(t_Presentador);
	m_r_textin = s_Presentador.getLocalBounds();
	s_Presentador.setOrigin(0, m_r_textin.height);
	s_Presentador.setPosition(20,altoPantalla);
	s_Presentador.scale(600/anchoPantalla,600/anchoPantalla);
	
	
	//Inicio reloj;
	relojin.restart();
}

void Menu::Actualizar (Juego & J, RenderWindow &ventanita) {
	//Si presionas click izquierdo sobre una opcion, se acciona;
	if(Mouse::isButtonPressed(Mouse::Left)){
		Vector2i posicion_mouse=Mouse::getPosition(J.ventanita);
		posicion_mouse=(Vector2i)J.ventanita.mapPixelToCoords(posicion_mouse);
		FloatRect posicion_manito(Vector2f(posicion_mouse),Vector2f(1,1));
		
		//Si presionas el texto Iniciar Partida te vas a una nueva partida;
		if(textoIniciarPartida.getGlobalBounds().intersects(posicion_manito)){
		J.Cambiar_Escena(new Menu_nuevo_juego);
		}
		
		//Si presionas el texto Ver Ranking te vas a ver el ranking;
		if(textoVerRanking.getGlobalBounds().intersects(posicion_manito)){
			J.Cambiar_Escena(new VerRanking);
		}
	}
	
	//Si precionas escape se cierra la ventana;
	if(Keyboard::isKeyPressed(Keyboard::Escape) and relojin.getElapsedTime().asSeconds() > 0.5 ){
		ventanita.close();
		relojin.restart();
	}
}

//Se dibuja todo;
void Menu::Dibujar (RenderWindow & ventanita) {
	ventanita.draw(Sprite_Principal);
	ventanita.draw(textoIniciarPartida);
	ventanita.draw(textoVerRanking);
	ventanita.draw(textoLeo1);
	ventanita.draw(textoLeo2);
	ventanita.draw(s_Presentador);
}

