#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED

#include "Persona.h"

class Estudiante:public Persona{
	private:
		int codigo,horasEstudio;
	
	public:
		Estudiante();
		void printInfo();
		int estudiar(int horas);
};

#endif
