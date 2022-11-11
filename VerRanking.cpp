#include "VerRanking.h"
#include "Juego.h"
#include "Menu.h"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

VerRanking::VerRanking() {
	ifstream archi("Campeones.txt");
	if(archi.is_open()){
		getline(archi,champions.player1);
		getline(archi,champions.puntos1);
		getline(archi,champions.player2);
		getline(archi,champions.puntos2);
		getline(archi,champions.player3);
		getline(archi,champions.puntos3);
	}else{
		cout<<"No lo tenes abierto pa"<<endl;
	};
	archi.close();
	//Fondo de Pantalla Menu
	Fondo_Principal.loadFromFile("FondoRanking.png");
	Sprite_Principal.setTexture(Fondo_Principal);
	Sprite_Principal.setPosition(0, 0);
	
	FloatRect tamFondo = Sprite_Principal.getLocalBounds();
	float anchoPantalla = (*((VideoMode::getFullscreenModes()).begin())).width;
	float altoPantalla = (*((VideoMode::getFullscreenModes()).begin())).height;
	float scaleX = anchoPantalla/tamFondo.width;
	float scaleY = altoPantalla/tamFondo.height;
	Sprite_Principal.scale(scaleX, scaleY);
	
	//Texto que se encuentra dentro del rectangulo
	primeroRAnking.setString(champions.player1);
	Fuentecita.loadFromFile("LibreBaskerville-Regular.ttf");
	primeroRAnking.setFont(Fuentecita);
	primeroRAnking.setCharacterSize(60);
	primeroRAnking.setFillColor(Color(145,0,123,255));
	m_r_textin = primeroRAnking.getLocalBounds();
	primeroRAnking.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	primeroRAnking.setPosition(anchoPantalla/2.003,altoPantalla/2.5);
	relojin.restart();
	
	segundoRanking.setString(champions.player2);
	Fuentecita.loadFromFile("LibreBaskerville-Regular.ttf");
	segundoRanking.setFont(Fuentecita);
	segundoRanking.setCharacterSize(60);
	segundoRanking.setFillColor(Color(145,0,123,255));
	m_r_textin = segundoRanking.getLocalBounds();
	segundoRanking.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	segundoRanking.setPosition(anchoPantalla/2.001,altoPantalla/2.3);
	relojin.restart();
	
	terceroRanking.setString(champions.player3);
	Fuentecita.loadFromFile("LibreBaskerville-Regular.ttf");
	terceroRanking.setFont(Fuentecita);
	terceroRanking.setCharacterSize(60);
	terceroRanking.setFillColor(Color(145,0,123,255));
	m_r_textin = terceroRanking.getLocalBounds();
	terceroRanking.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	terceroRanking.setPosition(anchoPantalla/2.010,altoPantalla/2);
	relojin.restart();
}

bool VerRanking::EnteroComparar(string campeonpts, int pts){
	stringstream cambiador;
	cambiador<<campeonpts;
	int championpts;
	cambiador>>championpts;
	return championpts<pts;
	
}
void VerRanking::Actualizar (Juego & J, RenderWindow &ventanita) {
	if(EnteroComparar(champions.puntos1,partiditaPa.verPuntosJugador())){
		champions.player1="Player1: "+partiditaPa.verNombreUsuario();
		champions.puntos1=partiditaPa.verNombreUsuario();
	}else{
		if(EnteroComparar(champions.puntos2,partiditaPa.verPuntosJugador())){
			champions.player2="Player1: "+partiditaPa.verNombreUsuario();
			champions.puntos2=partiditaPa.verNombreUsuario();
		}else{
			if(EnteroComparar(champions.puntos3,partiditaPa.verPuntosJugador())){
				champions.player3="Player1: "+partiditaPa.verNombreUsuario();
				champions.puntos3=partiditaPa.verNombreUsuario();
			}
		}
	}
	
	ofstream archi("Campeones.txt");
	if(archi.is_open()){
	archi.clear();
	archi<<champions.player1;
	archi<<champions.puntos1;
	archi<<champions.player1;
	archi<<champions.puntos2;
	archi<<champions.player3;
	archi<<champions.puntos3;
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Escape) and relojin.getElapsedTime().asSeconds() > 0.5){
		J.Cambiar_Escena(new Menu);
	}
}

void VerRanking::Dibujar (RenderWindow & ventanita) {
	ventanita.draw(Sprite_Principal);
	ventanita.draw(primeroRAnking);
	ventanita.draw(segundoRanking);
	ventanita.draw(terceroRanking);
}

