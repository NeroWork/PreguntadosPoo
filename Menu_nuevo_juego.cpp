#include "Menu_nuevo_juego.h"
#include "Menu.h"

Menu_nuevo_juego::Menu_nuevo_juego() {
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
	
	//Declaro al presentador
	t_Presentador.loadFromFile("presentador.png");
	t_Presentador.setSmooth(true);
	s_Presentador.setTexture(t_Presentador);
	m_r_textin = s_Presentador.getLocalBounds();
	s_Presentador.setOrigin(0, m_r_textin.height);
	s_Presentador.setPosition(20,altoPantalla);
	s_Presentador.scale(600/anchoPantalla,600/anchoPantalla);
	
	//Texto Presentador
	textoLeo1.setString("Iniciar Juego");
	Fuentecita.loadFromFile("LibreBaskerville-Regular.ttf");
	textoLeo1.setFont(Fuentecita);
	textoLeo1.setCharacterSize(60);
	textoLeo1.setFillColor(Color(145,0,123,255));
	m_r_textin = textoLeo1.getLocalBounds();
	textoLeo1.setOrigin(m_r_textin.width/2,m_r_textin.height/2);
	textoLeo1.setPosition(anchoPantalla/2.003,altoPantalla/2.5);
}


void Menu_nuevo_juego::Actualizar (Juego & J, RenderWindow & ventanita) {
	//Si precionas escape vuelve al menu principal;
	if(Keyboard::isKeyPressed(Keyboard::Escape) and relojin.getElapsedTime().asSeconds() > 0.5){
		J.Cambiar_Escena(new Menu);
	}
}

void Menu_nuevo_juego::Dibujar (RenderWindow & ventanita) {
	ventanita.draw(Sprite_Principal);
	ventanita.draw(textoLeo1);
	ventanita.draw(s_Presentador);
}

