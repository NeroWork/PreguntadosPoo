#include "VerRanking.h"
#include "Juego.h"
#include "Menu.h"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

VerRanking::VerRanking() {
//	ifstream archi("Campeones.txt");
//	if(archi.is_open()){
//		getline(archi,champions.player1);
//		getline(archi,champions.puntos1);
//		getline(archi,champions.player2);
//		getline(archi,champions.puntos2);
//		getline(archi,champions.player3);
//		getline(archi,champions.puntos3);
//	}{
//		cout<<"No lo tenes abierto pa"<<endl;
//	};
//	archi.close();
	
	//Fondo de Pantalla Menu
	Fondo_Principal.loadFromFile("FondoRanking.png");
	Sprite_Principal.setTexture(Fondo_Principal);
	Sprite_Principal.setPosition(0, 0);
	//Calculo que tanto debo escalar la imagen para que cubra toda la pantalla
	FloatRect tamFondo = Sprite_Principal.getLocalBounds();
	float anchoPantalla = (*((VideoMode::getFullscreenModes()).begin())).width;
	float altoPantalla = (*((VideoMode::getFullscreenModes()).begin())).height;
	float scaleX = anchoPantalla/tamFondo.width;
	float scaleY = altoPantalla/tamFondo.height;
	Sprite_Principal.scale(scaleX, scaleY);
	
	//Texto que se encuentra dentro del rectangulo
	/*textito.setString("RANKING UWUUUU");
	Fuentecita.loadFromFile("LibreBaskerville-Regular.ttf");
	textito.setFont(Fuentecita);
	textito.setCharacterSize(30);
	m_r_textin = textito.getLocalBounds();
	textito.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	textito.setPosition(600,300);
	relojin.restart();*/
}

bool VerRanking::EnteroComparar(string campeonpts, int pts){
	stringstream cambiador;
	cambiador<<campeonpts;
	int championpts;
	cambiador>>championpts;
	return championpts<pts;
	
}
void VerRanking::Actualizar (Juego & J, RenderWindow &ventanita) {
//	if(EnteroComparar(champions.puntos1,partiditaPa.verPuntosJugador())){
//		champions.player1="Player1: "+partiditaPa.verNombreUsuario();
//	}else{
//		if(EnteroComparar(champions.puntos2,partiditaPa.verPuntosJugador())){
//			champions.player2="Player1: "+partiditaPa.verNombreUsuario();
//		}else{
//			if(EnteroComparar(champions.puntos3,partiditaPa.verPuntosJugador())){
//				champions.player3="Player1: "+partiditaPa.verNombreUsuario();
//			}
//		}
//	}
//	
//	ofstream archi("Campeones.txt");
//	if(archi.is_open()){
//	archi.clear();
//	archi<<champions.player1;
//	archi<<champions.puntos1;
//	archi<<champions.player1;
//	archi<<champions.puntos2;
//	archi<<champions.player3;
//	archi<<champions.puntos3;
//	}
	
	if(Keyboard::isKeyPressed(Keyboard::Escape) and relojin.getElapsedTime().asSeconds() > 0.5){
		J.Cambiar_Escena(new Menu);
	}
}

void VerRanking::Dibujar (RenderWindow & ventanita) {
	ventanita.draw(Sprite_Principal);
	ventanita.draw(textito);
}

