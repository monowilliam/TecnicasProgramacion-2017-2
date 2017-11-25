#include <iostream>
#include <exception>
#include <stdio.h>
#include <stdlib.h>

using namespace std ;


class ExcepcionDividirPorCero : public exception {
	public :
		ExcepcionDividirPorCero():exception(){}
		const char *what() const throw(){
			return "Intentas dividir por cero ";
	}
};
//-------MEMORIA-----------
/*
int main () {
	double *ptr[50];
	try {
		for (int i= 0 ; i < 50; i ++) {
		ptr[i] = new double [50000000];
		cout << " Reservando memoria para elemento " << i <<
		endl ;
		}
	} catch ( bad_alloc &ex ) {
		cout << ex.what () << endl ;
	}
	cout <<" Termino programa normalmente " << endl ;
	return(0);
	system("pause");
}
*/
int dividir(int dividendo, int divisor){
	int resultado;
	if(divisor==0){
		throw ExcepcionDividirPorCero();
	}
	resultado= dividendo/divisor;
	cout << dividendo << "/" << divisor << "=" << resultado ;
}

int main(){
	float dividendo, divisor, resultado;
	cout << " PROGRAMA DIVISOR " << endl;
	cout << " Introduce Dividendo : " ;
	cin >> dividendo ;
	cout << " Introduce Divisor : " ;
	cin >> divisor;
	dividir(dividendo,divisor);
	
	/*
	try {
		resultado= dividendo/divisor;
		cout << dividendo << "/" << divisor << "=" << resultado ;
	} catch ( ExcepcionDividirPorCero &exce ) {
	cerr << " Error :" << exce.what () << endl ;
	}
	*/

	system("pause");
	return(0);
}
