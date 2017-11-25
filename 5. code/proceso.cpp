#include <cstdlib>
#include <iostream>
using namespace std;
#include "proceso.h"

Proceso::Proceso (int id){
	this->id     = id;
	string arregloEstados[] = {"Running  ", "Waiting  ", "Finished"};
	estado = arregloEstados [rand() % 3];
	tiempoCPU = rand () % 100;
	prioridad = rand () % 10;
}

void Proceso::mostrarse () {
	cout <<"ID: "<< id <<"\t Estado: "<< estado <<"\t TiempoCPU: "<< tiempoCPU <<"\t Prioridad: "<< prioridad << endl;
}

string Proceso::getEstado () {
	return estado;
}

int Proceso::getPrioridad () {
	return prioridad;
}

int Proceso::getTiempoCPU () {
	return tiempoCPU;
}

void Proceso::setEstado (string nuevoEstado) {
	estado = nuevoEstado;
}

void Proceso::reducirTiempoCPU (int tiempo) {
	tiempoCPU -= tiempo;
}	
