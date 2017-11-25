#ifndef __MIJUEGO_H__
#define __MIJUEGO_H__

#include "Juego.h"

class MiJuego:public Juego {
	public:
		MiJuego (string nombreJugador, int maxMovimientos);
		int reducirMovimientos ();
};
#endif
