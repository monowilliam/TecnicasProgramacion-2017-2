#include <cstdlib>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
#include "colap.h"

ColaPrioridad::ColaPrioridad(){}


bool comparar(Proceso p, Proceso q){
	return p.getPrioridad()<q.getPrioridad();
}


void ColaPrioridad::adicionar (Proceso p) {
    buffer.sort(comparar);
    buffer.push_back (p);

}


void ColaPrioridad::retirar(){
	buffer.pop_back();
}


Proceso ColaPrioridad::obtenerPrimero(){ //iteradores
	return buffer.back();
}


void ColaPrioridad::mostrar(){
	for(list<Proceso>::iterator i=buffer.begin(); i!=buffer.end(); i++ ){
		i->mostrarse();
	}
	cout << endl;
}


bool ColaPrioridad::estaVacia(){
	return buffer.empty();
}
