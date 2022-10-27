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

	//Corrijo la Pregunta;
	size_t posaux = Pregunta.find("Â");
	if(posaux != string::npos){
		Pregunta.erase(posaux, 1);
	}
	
	Pregunta=corregir(Pregunta);
	cout << Pregunta << endl;
	
	//Corrijo las opciones;
	OpcionA=corregir(OpcionA);
	cout << OpcionA << endl;
	
	OpcionB=corregir(OpcionB);
	cout << OpcionB << endl;
	
	OpcionC=corregir(OpcionC);
	cout << OpcionC << endl;
	
	OpcionD=corregir(OpcionD);
	cout << OpcionD << endl;
	
	OpcionE=corregir(OpcionE);
	cout << OpcionE << endl;
	
	cout << Respuesta << endl;
}

int structDePreguntas::getNroPregunta ( ) {
	return nroPregunta;
}


string structDePreguntas::corregir (string x) {
	size_t posaux = x.find("Ã±");
	if(posaux != string::npos){
		x.replace(posaux,2,"ñ");
	}
	return x;
}

