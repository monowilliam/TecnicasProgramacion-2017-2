#include <iostream>
#include "MiFicha.h"
using namespace std;


//--------CONSTRUCTOR PUNTO 5-----------------
MiFicha::MiFicha(char nuevaSim, char nuevaEtiq):Ficha(nuevaSim,nuevaEtiq){
	cout<<"5- Funciona MiFicha "<<endl;
}

//---------PUNTO 8 ----------
void MiFicha::setSimbolo(char nuevoSimbolo){
	simbolo=nuevoSimbolo;

}
