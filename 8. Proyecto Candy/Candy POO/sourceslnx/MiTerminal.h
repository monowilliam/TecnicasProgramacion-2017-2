#ifndef __MITERMINAL_H__
#define __MITERMINAL_H__

#include "Terminal.h"

class MiTerminal:public Terminal {
	public:
		void leerMovimiento (char &etiqueta1, char &etiqueta2);
};
#endif
