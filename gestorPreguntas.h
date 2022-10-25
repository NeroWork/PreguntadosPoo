#ifndef GESTORPREGUNTAS_H
#define GESTORPREGUNTAS_H
#include <list>
#include <string>
#include "structDePreguntas.h"
using namespace std;

class gestorPreguntas {
	list<structDePreguntas> listaDePreguntas;
public:
	gestorPreguntas();
	void tirarPreguntaAleatoria();
private:
};

#endif

