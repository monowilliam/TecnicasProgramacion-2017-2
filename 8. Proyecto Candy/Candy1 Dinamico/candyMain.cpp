#include <iostream>
#include <string.h>
#include <stdio.h>
#include "candyLib.cpp"

using namespace std;


int main(){
	tipoTablero t;
	int N=8;
	int M=8;
	char fichas[] = "@#$%^&/*+=~?¡";
	char cadEtiquetas[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789,.-";
	tipoJuego j;
	inicializarTablero(t,N,M,fichas,cadEtiquetas);
	dibujarTablero(t,N,M,j);
	

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
		tipoFicha *f1=obtenerFicha(t,N,M,c1);
		tipoFicha *f2=obtenerFicha(t,N,M,c2);
		swap(f1,f2);
		dibujarTablero(t,N,M,j);
   }
   ganadorFin(j);
   
	system("pause");
	return 0;
}
