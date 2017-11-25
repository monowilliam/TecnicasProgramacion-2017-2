#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <iostream>
#include "Persona.cpp"
using namespace std;

class Persona{
	private:
		String nombre;
		int edad;
		
	private:
		Persona();
		Persona(String nNombre, int nEdad);
		void printInfo();
		void cambiarNombre(String nNombres);
};

#endif
