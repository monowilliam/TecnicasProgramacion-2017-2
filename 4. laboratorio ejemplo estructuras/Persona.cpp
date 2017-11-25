#include <iostream>
#include <string.h>
#include "Persona.h"

Persona::Persona(){
	nombre = "No Nombre";
	edad = 0;
}

Persona::Persona(String nNombre, int nEdad){
	nombre = nNombre;
	edad = nEdad;
}

void Persona::printInfo(){
	cout<<endl;
	cout<<"Nombre: "<<nombre<<endl;
	coutt<<"Edad: "<<edad<<endl;
}

void Persona::cambiarNombre(String nNombre){
	nombre = nNombre;
}
