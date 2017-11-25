#ifndef __MIFICHA__H__
#define __MIFICHA__H__
#include "Ficha.h"
#include <iostream>
using namespace std;

class MiFicha:public Ficha{
	public:
		MiFicha(char nuevaSim, char nuevaEtiq);
		void setSimbolo(char nuevoSimbolo);
};

#endif
