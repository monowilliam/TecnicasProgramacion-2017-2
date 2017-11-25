#include "MiJuego.h"
#include <string.h>
#include <iostream>
using namespace std;

MiJuego::MiJuego(string nombreJugador, int maxMovimientos):Juego(nombreJugador, maxMovimientos){
}

int MiJuego::reducirMovimientos(){
	maxMovimientos=maxMovimientos-1;
	cout<<"15- Funciona reducir movimiento"<<endl;
}
