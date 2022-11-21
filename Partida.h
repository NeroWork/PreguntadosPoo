#ifndef PARTIDA_H
#define PARTIDA_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "gestorPreguntas.h"
#include "Manito.h"
using namespace std;

class Partida : public Escena {
private:
	//cosas del fondo;
	Texture Fondo_Principal;
	Sprite Sprite_Principal;
	float anchoPantalla, altoPantalla;
	
	//Cosas del ranking
	struct losCampeones{
		string player1;
		string puntos1;
		string player2;
		string puntos2;
		string player3;
		string puntos3;
	};
	losCampeones champions;
	
	//textos del menu;
	Text tiempo, text_cant_correctas, text_vidas;
	Font Fuentecita;
	FloatRect m_r_textin;
	
	//manito y reloj;
	Manito menu_manito;
	Clock relojin, relojin_aux;
	
	//Texto Opciones;
	Text Opcion1;
	Text Opcion2;
	Text Opcion3;
	Text Opcion4;
	Text Opcion5;
	Text Pregunta_text;
	
	//extras
	string nombre_Usuario;
	gestorPreguntas gp;
	structDePreguntas preguntaActual;
	int cantidad_Correctas=0, vidas = 3;
	bool derrotado = false;
public:
	Partida(string nombreUsuario);
	void Actualizar (Juego & J, RenderWindow & ventanita);
	void Dibujar (RenderWindow & ventanita);
	int verPuntosJugador();
	void inicializarPregunta();
	void OrdenarOpciones();
	void wrapear();
	void nuevaPregunta();
	void PreguntaExacta(int num);
	void Perder();
	bool EnteroComparar(string campeonpts, int pts);
	void elegirOpcion(string OpcionElegida);
	string verNombreUsuario();
};

#endif

