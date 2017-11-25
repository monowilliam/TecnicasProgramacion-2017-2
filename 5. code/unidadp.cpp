#include <time.h>
#include "proceso.h"
#include "unidadp.h"

const int TIMESLICE=10;

void UnidadProcesamiento::procesar (Proceso &p) {
	p.reducirTiempoCPU (TIMESLICE);

	for (int i=0;i < TIMESLICE;i++) {
		cout << "Procesando tiempo: " << i+1;
		cout << endl;
		this->sleep (4*500);
	}

	if (p.getTiempoCPU() < 0)
		p.setEstado ("Finished");
}


void UnidadProcesamiento::sleep(unsigned int mseconds) {
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
