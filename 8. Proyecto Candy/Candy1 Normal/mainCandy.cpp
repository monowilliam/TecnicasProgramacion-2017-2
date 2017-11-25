#include <iostream>
#include <string.h>
#include <stdio.h>
#include "funcionesCandy.cpp"

using namespace std;


int main(){
	tipoTablero t;
	char fichas[] = "@#$%*";
	char cadEtiquetas[] = "abcdefghijklmnopqrstuvwxyz";
	tipoJuego j;
	inicializarTablero(t,5,5,fichas,cadEtiquetas);
	dibujarTablero(t,5,5,j);
	

	j.movimientos=20;
	j.score=0;
	char nomJug[100];
	j.nomJugador=nomJug;
	
	char mov[2];
	nomJugador(j);
	
	while(j.movimientos>0){
		leerMovimiento(j,t,mov);
		imprControlador(j);
		char c1=mov[0];
		char c2=mov[1];
		tipoFicha *f1=obtenerFicha(t,c1);
		tipoFicha *f2=obtenerFicha(t,c2);
		swap(f1,f2);
		dibujarTablero(t,5,5,j);
   }
   ganadorFin(j);
   
	system("pause");
	return 0;
}
