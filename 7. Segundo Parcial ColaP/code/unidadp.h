#ifndef __UNIDADP_H
#define __UNIDADP_H

class UnidadProcesamiento {
	private:
		void sleep (unsigned int mseconds);

	public:
		void procesar (Proceso &p);
};
#endif

