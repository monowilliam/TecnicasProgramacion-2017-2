#include "proceso.h"
#include "unidadp.h"
#include "colap.h"

#include "proceso.cpp"
#include "unidadp.cpp"
#include "colap.cpp"

#include <iostream>
#include <stdio.h>
using namespace std;


int main(){
	ColaPrioridad cp;
	UnidadProcesamiento cpu;
	for(int i=1; i<=10; i++){
		Proceso p(i);
		p.mostrarse();
		cp.adicionar(p);
	}
	while (cp.estaVacia() == false){
		cp.mostrar();
		Proceso q= cp.obtenerPrimero();
		cp.retirar();
		cpu.procesar(q);

		if(q.getEstado() != "Finished"){
			cp.adicionar(q);
		}
	}
	system("pause");
	return 0;
}
