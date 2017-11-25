#include "Estudiante.h"
#include <iostream>
#include <string.h>

Estudiante::Estudiante(){
	codigo=999;
	horasEstudio=0;
}

void Estudiante::printInfo(){
	Persona::printInfo();
	cout<<"Codigo: " <<codigo<<endl;
	cout<<"Horas de Estudio: "<<horasEstudio<<endl;
}

int Estudiante::Estudiar(int horas){
	horasEstudio += horas;
}


