#include "VerRanking.h"
#include "Juego.h"
#include "Menu.h"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

VerRanking::VerRanking() : partiditaPa("x") {
	//Pasar del txt al struct los campeones
	ifstream archi("Campeones.txt");
	if(archi.is_open()){
		getline(archi,champions.player1);
		getline(archi,champions.puntos1);
		getline(archi,champions.player2);
		getline(archi,champions.puntos2);
		getline(archi,champions.player3);
		getline(archi,champions.puntos3);
	}else{
		cout<<"No lo tenes abierto"<<endl;
	};
	archi.close();
	//Fondo de Pantalla ranking
	Fondo_Principal.loadFromFile("FondoRanking.png");
	Sprite_Principal.setTexture(Fondo_Principal);
	Sprite_Principal.setPosition(0, 0);
	
	FloatRect tamFondo = Sprite_Principal.getLocalBounds();
	float anchoPantalla = (*((VideoMode::getFullscreenModes()).begin())).width;
	float altoPantalla = (*((VideoMode::getFullscreenModes()).begin())).height;
	float scaleX = anchoPantalla/tamFondo.width;
	float scaleY = altoPantalla/tamFondo.height;
	Sprite_Principal.scale(scaleX, scaleY);
	//Textode los jugadores en el ranking y sus puntos
	string aux  = champions.player1;
	primeroRAnking.setString(aux);
	Fuentecita.loadFromFile("LibreBaskerville-Regular.ttf");
	primeroRAnking.setFont(Fuentecita);
	primeroRAnking.setCharacterSize(80);
	primeroRAnking.setFillColor(Color(145,0,123,255));
	m_r_textin = primeroRAnking.getLocalBounds();
	primeroRAnking.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	primeroRAnking.setPosition(anchoPantalla/1.95,altoPantalla/3.45);
	relojin.restart();
	
	aux = champions.puntos1;
	primeroPuntos.setString(aux);
	primeroPuntos.setFont(Fuentecita);
	primeroPuntos.setCharacterSize(60);
	primeroPuntos.setFillColor(Color(145,0,123,255));
	m_r_textin = primeroPuntos.getLocalBounds();
	primeroPuntos.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	primeroPuntos.setPosition(anchoPantalla/1.445,altoPantalla/3.275);
	relojin.restart();
	
	segundoRanking.setString(champions.player2);
	segundoRanking.setFont(Fuentecita);
	segundoRanking.setCharacterSize(80);
	segundoRanking.setFillColor(Color(145,0,123,255));
	m_r_textin = segundoRanking.getLocalBounds();
	segundoRanking.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	segundoRanking.setPosition(anchoPantalla/1.8,altoPantalla/1.75);
	relojin.restart();
	
	segundoPuntos.setString(champions.puntos2);
	segundoPuntos.setFont(Fuentecita);
	segundoPuntos.setCharacterSize(60);
	segundoPuntos.setFillColor(Color(145,0,123,255));
	m_r_textin = segundoPuntos.getLocalBounds();
	segundoPuntos.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	segundoPuntos.setPosition(anchoPantalla/1.45,altoPantalla/1.75);
	relojin.restart();

	terceroRanking.setString(champions.player3);
	terceroRanking.setFont(Fuentecita);
	terceroRanking.setCharacterSize(80);
	terceroRanking.setFillColor(Color(145,0,123,255));
	m_r_textin = terceroRanking.getLocalBounds();
	terceroRanking.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	terceroRanking.setPosition(anchoPantalla/1.8,altoPantalla/1.25);
	relojin.restart();
	
	
	aux = champions.puntos3;
	terceroPuntos.setString(aux);
	terceroPuntos.setFont(Fuentecita);
	terceroPuntos.setCharacterSize(60);
	terceroPuntos.setFillColor(Color(145,0,123,255));
	m_r_textin = terceroPuntos.getLocalBounds();
	terceroPuntos.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	terceroPuntos.setPosition(anchoPantalla/1.45,altoPantalla/1.25);
	
	relojin.restart();
}

void VerRanking::Actualizar (Juego & J, RenderWindow &ventanita) {
	if(Keyboard::isKeyPressed(Keyboard::Escape) and relojin.getElapsedTime().asSeconds() > 0.5){
		J.Cambiar_Escena(new Menu);
	}
}

// Dibujar el fondo y los nombre y puntos de los campeones
void VerRanking::Dibujar (RenderWindow & ventanita) {
	ventanita.draw(Sprite_Principal);
	ventanita.draw(primeroRAnking);
	ventanita.draw(primeroPuntos);
	ventanita.draw(segundoRanking);
	ventanita.draw(segundoPuntos);
	ventanita.draw(terceroRanking);
	ventanita.draw(terceroPuntos);
}

