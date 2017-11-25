#ifndef __PROCESO_H__
#define __PROCESO_H__
#include <iostream>
using namespace std;


class Proceso {
	private:
		int id;
		string estado;
		int tiempoCPU;
		int prioridad;
	public:
		Proceso (int id);
		string getEstado ();
		int getPrioridad ();
		void setEstado (string nuevoEstado);
		void mostrarse ();
		int getTiempoCPU();
		void reducirTiempoCPU (int tiempo);
};

#endif






