#ifndef __COLAP_H__
#define __COLAP_H__

#include <list>
#include "proceso.h"

class ColaPrioridad {
	private:
		list <Proceso> buffer;
	public:
		ColaPrioridad ();
		void adicionar (Proceso p);
		void retirar ();
		Proceso obtenerPrimero ();
		void mostrar ();
		bool estaVacia ();
};
#endif
