#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <time.h>
#include <stdlib.h>

#include "Juego.h"
#include "Ficha.h"
#include "GeneradorEtiquetas.h"
#include "GeneradorSimbolos.h"
#include "Tablero.h"
#include "Terminal.h"

#include "MiGeneradorEtiquetas.h"
#include "MiFicha.h"
#include "MiJuego.h"
#include "MiTablero.h"

/*	1-
	5-
	8
	15-
	22-
*/

using namespace std;

int main(){
	srand((unsigned) time(0));
	
	//-----------------------------------------------
	MiFicha('a','b');
	//-----------------------------------------------
			
	string nomJugador;
	char m, n;
	int dimensionesN, dimensionesM;
	cout << "Nombre del Jugador: "<<endl;
	cin >> nomJugador;
	cout << "Dimensiones del Tablero: "<<endl;
	cin >> dimensionesN >>dimensionesM;
	
	//----------------------------------------------
	MiJuego juego1 (nomJugador,20);
	//----------------------------------------------
	
	MiTablero tablero1 (dimensionesN,dimensionesM);
	GeneradorSimbolos gSimbolo ("@#$%^&/*+=~?¡");
	
	//-------------------------------------------------------
	MiGeneradorEtiquetas gEtiqueta ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789,.-");
	//---------------------------------------------------------
	
	Terminal terminal1;
	tablero1.inicializarse(gSimbolo,gEtiqueta);
	terminal1.limpiarPantalla();
	while (juego1.verificarFinal() != 1){
		int a,b;
		juego1.mostrarInformacion();
		tablero1.dibujarse();
		terminal1.leerMovimiento(m,n);
		Ficha *f1 = tablero1.obtenerFicha(m);
		Ficha *f2 = tablero1.obtenerFicha(n);
		f1->intercambiarSimbolos(f2);
		
		if (tablero1.buscarTripletaFilas(a,b) != NULL){
			juego1.aumentarPuntaje(10);
			tablero1.reemplazarTripletaFilas(a,b,gSimbolo);
		}
		
		if (tablero1.buscarTripletaColumnas(a,b) != NULL){
			juego1.aumentarPuntaje(10);
			tablero1.reemplazarTripletaColumnas(a,b,gSimbolo);
		}
		juego1.reducirMovimientos();
	}	
	system("pause");
	return 0;	
}
