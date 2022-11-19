#include <SFML/Graphics.hpp>
#include "gestorPreguntas.h"
#include <iostream>
#include "Juego.h"
#include "Menu.h"
using namespace std;
using namespace sf;


int main(int argc, char *argv[]){
	setlocale(LC_ALL, "spanish");
	
	Juego Proyecto(new Menu);
	Proyecto.Jugar();
	return 0;
}

