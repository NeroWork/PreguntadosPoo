#ifndef GESTORPREGUNTAS_H
#define GESTORPREGUNTAS_H
#include <list>
#include <string>
#include "structDePreguntas.h"
using namespace std;

class gestorPreguntas {
	list<structDePreguntas> listaDePreguntas;
	structDePreguntas pregunta_Actual;
	int posicion_Pregunta;
	int cantidad_preguntas;
public:
	gestorPreguntas();
	void tirarPreguntaAleatoria();
	string tirar_OpcionA();
	string tirar_OpcionB();
	string tirar_OpcionC();
	string tirar_OpcionD();
	string tirar_OpcionE();
	string tirar_Respuesta();
	structDePreguntas getPreguntaActual();
private:
};

#endif

