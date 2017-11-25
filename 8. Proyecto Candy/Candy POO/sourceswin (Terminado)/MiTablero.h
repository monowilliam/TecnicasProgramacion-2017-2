#ifndef __MITABLERO__H__
#define __MITABLERO__H__

#include "Tablero.h"
#include <iostream>
using namespace std;

class MiTablero:public Tablero {
	public:
		MiTablero(int filas, int cols);
		Ficha * obtenerFicha1 (int posFila, int posColumna);
};

#endif
