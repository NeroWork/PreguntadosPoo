#ifndef STRUCTDEPREGUNTAS_H
#define STRUCTDEPREGUNTAS_H
#include <string>
using namespace std;

class structDePreguntas {
	int nroPregunta;
	string Pregunta;
	string OpcionA;
	string OpcionB;
	string OpcionC;
	string OpcionD;
	string OpcionE;
	string Respuesta;
public:
	structDePreguntas();
	void agregarNroPregunta(int nro);
	void agregarPregunta(string x);
	void agregarRespuesta(string x);
	void agregarOpcionA(string x);
	void agregarOpcionB(string x);
	void agregarOpcionC(string x);
	void agregarOpcionD(string x);
	void agregarOpcionE(string x);
	int getNroPregunta();
	string corregir(string x);
	void coutTodo();
	string verOpcionA();
	string verOpcionB();
	string verOpcionC();
	string verOpcionD();
	string verOpcionE();
	string verRespuesta();
	string verPregunta();
};

#endif

