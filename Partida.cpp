#include "Partida.h"
#include <SFML/Window.hpp>
#include <string>
#include <SFML/System/Vector2.hpp>
#include "Juego.h"
#include "Menu.h"
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

Partida::Partida(string nombreUsuario) :  nombre_Usuario(nombreUsuario){
	//Fondo de Pantalla Partida
	Fondo_Principal.loadFromFile("partida.jpg");
	Sprite_Principal.setTexture(Fondo_Principal);
	Sprite_Principal.setPosition(0, 0);
	//Calculo que tanto debo escalar la imagen para que cubra toda la pantalla
	FloatRect tamFondo = Sprite_Principal.getLocalBounds();
	anchoPantalla = (*((VideoMode::getFullscreenModes()).begin())).width;
	altoPantalla = (*((VideoMode::getFullscreenModes()).begin())).height;
	float scaleX = anchoPantalla/tamFondo.width;
	float scaleY = altoPantalla/tamFondo.height;
	Sprite_Principal.scale(scaleX, scaleY);
	
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
	
	//Texto tiempo
	tiempo.setString("20");
	Fuentecita.loadFromFile("LibreBaskerville-Regular.ttf");
	tiempo.setFont(Fuentecita);
	tiempo.setCharacterSize(60);
	tiempo.setFillColor(Color(255,108,18,255));
	m_r_textin = tiempo.getLocalBounds();
	tiempo.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	tiempo.setPosition(anchoPantalla/1.05,altoPantalla/60);
	
	//Texto vidas;
	text_vidas.setString("3");
	text_vidas.setFont(Fuentecita);
	text_vidas.setCharacterSize(60);
	text_vidas.setFillColor(Color(255,108,18,255));
	m_r_textin = text_vidas.getLocalBounds();
	text_vidas.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	text_vidas.setPosition(anchoPantalla/1.05,altoPantalla/8);
	
	//Texto contador;
	text_cant_correctas.setString("0");
	text_cant_correctas.setFont(Fuentecita);
	text_cant_correctas.setCharacterSize(60);
	text_cant_correctas.setFillColor(Color(255,108,18,255));
	m_r_textin = text_cant_correctas.getLocalBounds();
	text_cant_correctas.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	text_cant_correctas.setPosition(anchoPantalla/1.05,altoPantalla/4);
	
	//Declaro Primer pregunta;
	this->inicializarPregunta();
	this->OrdenarOpciones();
	this->wrapear();
	
	//Reloj
	relojin.restart();
	relojin_aux.restart();
}

void Partida::Actualizar (Juego & J, RenderWindow & ventanita) {
	if(derrotado){
		J.Cambiar_Escena(new Menu);
	}
	
	if(Mouse::isButtonPressed(Mouse::Left) and relojin.getElapsedTime().asSeconds() > 1){
		
		Vector2i posicion_mouse=Mouse::getPosition(ventanita);
		posicion_mouse=(Vector2i)ventanita.mapPixelToCoords(posicion_mouse);
		FloatRect posicion_manito(Vector2f(posicion_mouse),Vector2f(1,1));
		
		string Opcion_Elegida;
		
		if(Opcion1.getGlobalBounds().intersects(posicion_manito)){
			Opcion_Elegida=gp.tirar_OpcionA().substr(0,1);
			this->elegirOpcion(Opcion_Elegida);
		} else {
			if(Opcion2.getGlobalBounds().intersects(posicion_manito)){
				Opcion_Elegida=gp.tirar_OpcionB().substr(0,1);
				this->elegirOpcion(Opcion_Elegida);
			} else {
				if(Opcion3.getGlobalBounds().intersects(posicion_manito)){
					Opcion_Elegida=gp.tirar_OpcionC().substr(0,1);
					this->elegirOpcion(Opcion_Elegida);
				} else {
					if(Opcion4.getGlobalBounds().intersects(posicion_manito)){
						Opcion_Elegida=gp.tirar_OpcionD().substr(0,1);
						this->elegirOpcion(Opcion_Elegida);
					} else{
						if(Opcion5.getGlobalBounds().intersects(posicion_manito)){
							Opcion_Elegida=gp.tirar_OpcionE().substr(0,1);
							this->elegirOpcion(Opcion_Elegida);
						}
					}
				}
			}
		}
		relojin.restart();
	}
	
	//Reloj de 20 a 0;
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
			m_r_textin = tiempo.getLocalBounds();
			tiempo.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
			tiempo.setPosition(anchoPantalla/1.05,altoPantalla/60);
			relojin_aux.restart();
		} else {
			this->elegirOpcion("Z");
		}
	}
	
	//Si presionas escape volves al menu;
	if(Keyboard::isKeyPressed(Keyboard::Escape) and relojin.getElapsedTime().asSeconds() > 0.5){
		J.Cambiar_Escena(new Menu);
		relojin.restart();
	}
}

int Partida::verPuntosJugador(){
	return cantidad_Correctas;
}

string Partida::verNombreUsuario(){
	return nombre_Usuario;
}

void Partida::inicializarPregunta ( ) {
	gp.tirarPreguntaAleatoria();
	preguntaActual = gp.getPreguntaActual();
}

void Partida::OrdenarOpciones ( ) {
	//opcion1;
	Opcion1.setString(gp.tirar_OpcionA());
	Opcion1.setFont(Fuentecita);
	Opcion1.setCharacterSize(40);
	Opcion1.setFillColor(Color(145,0,123,255));
	m_r_textin = Opcion1.getLocalBounds();
	Opcion1.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	Opcion1.setPosition(anchoPantalla/2,altoPantalla/2.75);
	//opcion2;
	Opcion2.setString(gp.tirar_OpcionB());
	Opcion2.setFont(Fuentecita);
	Opcion2.setCharacterSize(40);
	Opcion2.setFillColor(Color(145,0,123,255));
	m_r_textin = Opcion2.getLocalBounds();
	Opcion2.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	Opcion2.setPosition(anchoPantalla/2,altoPantalla/2.02);
	//opcion3;
	Opcion3.setString(gp.tirar_OpcionC());
	Opcion3.setFont(Fuentecita);
	Opcion3.setCharacterSize(40);
	Opcion3.setFillColor(Color(145,0,123,255));
	m_r_textin = Opcion3.getLocalBounds();
	Opcion3.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	Opcion3.setPosition(anchoPantalla/2,altoPantalla/1.60);
	//opcion4;
	Opcion4.setString(gp.tirar_OpcionD());
	Opcion4.setFont(Fuentecita);
	Opcion4.setCharacterSize(40);
	Opcion4.setFillColor(Color(145,0,123,255));
	m_r_textin = Opcion4.getLocalBounds();
	Opcion4.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	Opcion4.setPosition(anchoPantalla/2,altoPantalla/1.33);
	//opcion5;
	Opcion5.setString(gp.tirar_OpcionE());
	Opcion5.setFont(Fuentecita);
	Opcion5.setCharacterSize(40);
	Opcion5.setFillColor(Color(145,0,123,255));
	m_r_textin = Opcion5.getLocalBounds();
	Opcion5.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	Opcion5.setPosition(anchoPantalla/2,altoPantalla/1.13);
	//pregunta;
	Pregunta_text.setString(preguntaActual.verPregunta());
	Pregunta_text.setFont(Fuentecita);
	Pregunta_text.setCharacterSize(40);
	Pregunta_text.setFillColor(Color(145,0,123,255));
	m_r_textin = Pregunta_text.getLocalBounds();
	Pregunta_text.setOrigin(0,m_r_textin.height/2);
	Pregunta_text.setPosition(anchoPantalla/8,altoPantalla/8);
}

void Partida::wrapear (){
	float tam_rec = anchoPantalla/1.25;
	cout << "Limite tamanio: " << tam_rec << endl;
	string aux = Pregunta_text.getString();
	Vector2f vec_aux;
	bool encontrado = false;
	size_t pos_aux = 0;
	for(int i=0;i<aux.length();i++) {
		vec_aux = Pregunta_text.findCharacterPos(i);
		if(vec_aux.x >= tam_rec and !encontrado){
			cout << "Suma total encontrada: " << vec_aux.x << endl;
			cout << "Encontrada: " << i << endl;
			encontrado = true;
			pos_aux = i;
		}
	}
	
	if(encontrado == true){
//		size_t pos_new = aux.find(" ",pos_aux);
		size_t pos_new = 0;
		size_t pos_mayor = 0;
		while(pos_mayor < pos_aux){
			pos_new = pos_mayor;
			pos_mayor = aux.find(" ", pos_new+1);
			cout << "pos_mayor: " << pos_mayor << endl;
		}
		cout << "pos new : " << pos_new << endl;
		aux = aux.erase(pos_new,1);
		aux.insert(pos_new,"\n");
		cout << "texto modificado: " << aux << endl;
		Pregunta_text.setString(aux);
		m_r_textin = Pregunta_text.getLocalBounds();
		Pregunta_text.setOrigin(0,m_r_textin.height/2);
		Pregunta_text.setPosition(anchoPantalla/8,altoPantalla/8);
		this->wrapear();
	}
}

void Partida::elegirOpcion (string OpcionElegida) {
	if(OpcionElegida==gp.tirar_Respuesta()){
		cantidad_Correctas++;
		int auxint = cantidad_Correctas;
		stringstream ss;
		ss << auxint;
		string aux;
		ss >> aux;
		text_cant_correctas.setString(aux);
	} else {
		vidas--;
		stringstream ss;
		ss << vidas;
		string aux;
		ss >> aux;
		text_vidas.setString(aux);
		if (vidas <= 0){
			this->Perder();
		}
	}
	this->nuevaPregunta();
}

void Partida::nuevaPregunta () {
	this->inicializarPregunta();
	this->OrdenarOpciones();
	this->wrapear();
	tiempo.setString("20");
}

//Funcion para comparar los puntos del nuevo jugador y los campeones
bool Partida::EnteroComparar(string campeonpts, int pts){
	stringstream cambiador;
	cambiador<<campeonpts;;
	int championpts;
	cambiador>>championpts;
	return championpts<pts;
	
}

void Partida::Perder ( ) {
	//Ver si el nuevo jugador entra en el ranking
	if(EnteroComparar(champions.puntos1,cantidad_Correctas)){
		champions.player3=champions.player2;
		champions.puntos3=champions.puntos2;
		champions.player2=champions.player1;
		champions.puntos2=champions.puntos1;
		champions.player1=nombre_Usuario;
		champions.puntos1=text_cant_correctas.getString();
		
	}else{
		if(EnteroComparar(champions.puntos2,cantidad_Correctas)){
			champions.player3=champions.player2;
			champions.puntos3=champions.puntos2;
			champions.player2=nombre_Usuario;
			champions.puntos2=text_cant_correctas.getString();
		}else{
			if(EnteroComparar(champions.puntos3,cantidad_Correctas)){
				champions.player3=nombre_Usuario;
				champions.puntos3=text_cant_correctas.getString();
			}
		}
	}
	
	//Pasar de nuevo los campeones al txt
	ofstream archi("Campeones.txt");
	if(archi.is_open()){
		archi.clear();
		archi<<champions.player1<<endl;
		archi<<champions.puntos1<<endl;
		archi<<champions.player2<<endl;
		archi<<champions.puntos2<<endl;
		archi<<champions.player3<<endl;
		archi<<champions.puntos3<<endl;
	}else{
		cout<<"No esta abierto"<<endl;
	}
	archi.close();
	
	derrotado=true;
}

void Partida::Dibujar (RenderWindow & ventanita) {
	ventanita.draw(Sprite_Principal);
	ventanita.draw(tiempo);
	ventanita.draw(Opcion1);
	ventanita.draw(Opcion2);
	ventanita.draw(Opcion3);
	ventanita.draw(Opcion4);
	ventanita.draw(Opcion5);
	ventanita.draw(Pregunta_text);
	ventanita.draw(text_vidas);
	ventanita.draw(text_cant_correctas);
	
}
