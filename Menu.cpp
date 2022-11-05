#include "Menu.h"
#include <SFML/Window/Keyboard.hpp>
#include "Juego.h"
#include "VerRanking.h"
#include "Manito.h"

Menu::Menu() {
	//Fondo de Pantalla Menu
	Fondo_Principal.loadFromFile("fondo169Leonardium.png");
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
	textoVerRanking.setPosition(anchoPantalla/2.003, altoPantalla/1.8);
	
	
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
		J.Cambiar_Escena(new VerRanking);
		}
		
		//Si presionas el texto Ver Ranking te vas a ver el ranking;
		if(textoVerRanking.getGlobalBounds().intersects(posicion_manito)){
			J.Cambiar_Escena(new VerRanking);
		}
	}
	
	//Si precionas escape se cierra la ventana;
	if(Keyboard::isKeyPressed(Keyboard::Escape) and relojin.getElapsedTime().asSeconds() > 0.5 ){
		ventanita.close();
	}
}

//Se dibuja todo;
void Menu::Dibujar (RenderWindow & ventanita) {
	ventanita.draw(Sprite_Principal);
	ventanita.draw(textoIniciarPartida);
	ventanita.draw(textoVerRanking);
}

