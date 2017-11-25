#include <iostream>
#include "Persona.h"
#include "Persona.cpp"
#include "Estudiante.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Persona p1;
	p1.printInfo();
	
	Persona p2("Pedro",20);
	p2.printInfo();
	p2.cambiarNombre("Carlota");
	p2.printInfo();
	
	Estudiante e1;
	e1.printInfo();
	e1.estudiar(10);
	
	
	return 0;
}
