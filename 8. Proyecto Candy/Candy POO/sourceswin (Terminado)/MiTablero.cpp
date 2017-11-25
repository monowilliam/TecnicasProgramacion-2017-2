#include "MiTablero.h"
#include <string.h>
#include <iostream>
using namespace std;

MiTablero::MiTablero(int filas, int cols):Tablero(filas, cols){
}

Ficha * MiTablero::obtenerFicha1(int posFila, int posColumna){
	return &matriz[posFila][posColumna];
	cout << "22- Funciona obtenerFicha";
}

