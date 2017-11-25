#include "proceso.h"
#include "unidadp.h"
#include "colap.h"

#include "proceso.cpp"
#include "unidadp.cpp"
#include "colap.cpp"

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <pthread.h>
using namespace std;

void *ProcesarThread(void *pid){
	UnidadProcesamiento cpu;
	
	Proceso *p = (Proceso *) pid;

	cpu.procesar (*p);

	pthread_exit (NULL);
}


int main(){
	srand((unsigned)time(0));
	UnidadProcesamiento cpu1, cpu2;
	ColaPrioridad cp;
	pthread_t threads[2], pt1, pt2;
	int rc;

	int nId = 0;

	while(nId++ < 20){
		Proceso p(nId);
		p.mostrarse();
		cp.adicionar(p);
	}

	while (cp.estaVacia() == false){
		cp.mostrar();
		Proceso p1= cp.obtenerPrimero();
		cp.retirar();
		Proceso p2= cp.obtenerPrimero();
		cp.retirar();

		rc = pthread_create(&pt1,NULL,&ProcesarThread, (void*)&p1);
		rc = pthread_create(&pt2,NULL,&ProcesarThread, (void*)&p2);
		pthread_join (pt1,NULL);
		
		if(p2.getEstado() != "Finished")
			cp.adicionar(p2);
		if(p1.getEstado() != "Finished")
			cp.adicionar(p1);
	}
	system("pause");
	return 0;
}
