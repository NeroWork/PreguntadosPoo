#include "gestorPreguntas.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <SFML/System/Time.hpp>
#include <ctime>
#include <iostream>
#include <iterator>
using namespace std;

gestorPreguntas::gestorPreguntas() : cantidad_preguntas(99){
	//Creo variables auxiliares
	string preguntaNro, pregunta, opcionA, opcionB, opcionC, opcionD, opcionE, respuesta;
	ifstream archi("poolPreguntas.txt");
	structDePreguntas aux;
	//mientras haya preguntas con opciones
	while(getline(archi, preguntaNro) && getline(archi, pregunta) && getline(archi, opcionA)
	&& getline(archi, opcionB) && getline(archi, opcionC) && getline(archi, opcionD)
	&& getline(archi, opcionE) && getline(archi, respuesta)){
		//guardo los datos
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
	//Creo un numero random
	srand(time(NULL));
	int cont_aux = 0;
	int nroEntre1Y99 = (rand()%cantidad_preguntas) + 1;
	cout << "Numero random: " << nroEntre1Y99 << endl;
	posicion_Pregunta=nroEntre1Y99;
	list<structDePreguntas>::iterator itaux;
	//Busco esa pregunta entre las de la lista
	for (list<structDePreguntas>::iterator it = listaDePreguntas.begin(); it != listaDePreguntas.end(); it++){
		cont_aux++;
		if( cont_aux == nroEntre1Y99){
			pregunta_Actual = (*it);
			pregunta_Actual.coutTodo();
			itaux = it;
		}
	}
	listaDePreguntas.erase(itaux);
	cantidad_preguntas--;
	cout << "Cantidad de preguntas: " << cantidad_preguntas << endl;
	cout << "Largo de la lista: " << listaDePreguntas.size() << endl;
}

string gestorPreguntas::tirar_OpcionA(){
	return pregunta_Actual.verOpcionA();
}

string gestorPreguntas::tirar_OpcionB(){
	return pregunta_Actual.verOpcionB();
}

string gestorPreguntas::tirar_OpcionC(){
	return pregunta_Actual.verOpcionC();
}

string gestorPreguntas::tirar_OpcionD(){
	return pregunta_Actual.verOpcionD();
}

string gestorPreguntas::tirar_OpcionE(){
	return pregunta_Actual.verOpcionE();
}

string gestorPreguntas::tirar_Respuesta(){
	return pregunta_Actual.verRespuesta();
}

structDePreguntas gestorPreguntas::getPreguntaActual ( ) {
	return pregunta_Actual;
}

//Esta funcion es solo para testear cosas, no tiene utilidad real dentro del juego;
void gestorPreguntas::tirarPreguntaParticular (int num) {
	bool Encontrado = false;
	for (list<structDePreguntas>::iterator it = listaDePreguntas.begin(); it != listaDePreguntas.end(); it++){
		if( (*it).getNroPregunta() == num){
			pregunta_Actual = (*it);
			pregunta_Actual.coutTodo();
			Encontrado = true;
		}
	}
	if(!Encontrado){
		pregunta_Actual=(*listaDePreguntas.begin());
	}
}

