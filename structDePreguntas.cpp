#include "structDePreguntas.h"
#include <iostream>
using namespace std;

structDePreguntas::structDePreguntas() {
	
}

//Gaurdar el numero, la pregunta, las opciones y la respuesta de la pregunta
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

//Mostrar toda la pregunta y corregirla para que aparezcan las ? y los ?
void structDePreguntas::coutTodo ( ) {
	cout << nroPregunta << endl;

	//Corrijo la Pregunta;
	size_t posaux = Pregunta.find("?");
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

//Mostrar el numero de la pregunta
int structDePreguntas::getNroPregunta ( ) {
	return nroPregunta;
}


//Funcion para corregir la pregunta
string structDePreguntas::corregir (string x) {
	size_t posaux = x.find("ñ");
	if(posaux != string::npos){
		x.replace(posaux,2,"?");
		x = this->corregir(x);
	}
	return x;
}

//Mostrar las opciones y la respuesta
string structDePreguntas::verOpcionA(){
	return OpcionA;
}

string structDePreguntas::verOpcionB(){
	return OpcionB;
}

string structDePreguntas::verOpcionC(){
	return OpcionC;
}

string structDePreguntas::verOpcionD(){
	return OpcionD;
}

string structDePreguntas::verOpcionE(){
	return OpcionE;
}

string structDePreguntas::verRespuesta(){
	return Respuesta;
}

string structDePreguntas::verPregunta ( ) {
	return Pregunta;
}

