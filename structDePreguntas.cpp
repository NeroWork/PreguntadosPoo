#include "structDePreguntas.h"
#include <iostream>
using namespace std;

structDePreguntas::structDePreguntas() {
	
}


void structDePreguntas::agregarNroPregunta (int nro) {
	nroPregunta = nro;
}

void structDePreguntas::agregarPregunta (string x) {
	Pregunta = x;
}

void structDePreguntas::agregarRespuesta (string x) {
	Respuesta = x;
}

void structDePreguntas::agregarOpcionA (string x) {
	OpcionA = x;
}

void structDePreguntas::agregarOpcionB (string x) {
	OpcionB = x;
}

void structDePreguntas::agregarOpcionC (string x) {
	OpcionC = x;
}

void structDePreguntas::agregarOpcionD (string x) {
	OpcionD = x;
}

void structDePreguntas::agregarOpcionE (string x) {
	OpcionE = x;
}

void structDePreguntas::coutTodo ( ) {
	cout << nroPregunta << endl;
	cout << Pregunta << endl;
	cout << OpcionA << endl;
	cout << OpcionB << endl;
	cout << OpcionC << endl;
	cout << OpcionD << endl;
	cout << OpcionE << endl;
	cout << Respuesta << endl;
}

int structDePreguntas::getNroPregunta ( ) {
	return nroPregunta;
}

