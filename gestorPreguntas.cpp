#include "gestorPreguntas.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <SFML/System/Time.hpp>
#include <ctime>
#include <iostream>
using namespace std;

gestorPreguntas::gestorPreguntas() {
	string preguntaNro, pregunta, opcionA, opcionB, opcionC, opcionD, opcionE, respuesta;
	ifstream archi("poolPreguntas.txt");
	structDePreguntas aux;
	while(getline(archi, preguntaNro) && getline(archi, pregunta) && getline(archi, opcionA)
	&& getline(archi, opcionB) && getline(archi, opcionC) && getline(archi, opcionD)
	&& getline(archi, opcionE) && getline(archi, respuesta)){
		stringstream ssAux;
		int nroaux=0;
		size_t sizeaux = preguntaNro.find(":");
		ssAux << preguntaNro.substr(9,sizeaux-9);
		ssAux >> nroaux;
		aux.agregarNroPregunta(nroaux);
		aux.agregarPregunta(pregunta);
		aux.agregarOpcionA(opcionA);
		aux.agregarOpcionB(opcionB);
		aux.agregarOpcionC(opcionC);
		aux.agregarOpcionD(opcionD);
		aux.agregarOpcionE(opcionE);
		respuesta = respuesta.substr(8,1);
		aux.agregarRespuesta(respuesta);
		listaDePreguntas.push_back(aux);
	}
	archi.close();
}


void gestorPreguntas::tirarPreguntaAleatoria ( ) {
	srand(time(NULL));
	int nroEntre1Y99 = (rand()%99) + 1;
	for (auto x : listaDePreguntas){
		if(x.getNroPregunta() == nroEntre1Y99){
			x.coutTodo();
		}
	}
}

