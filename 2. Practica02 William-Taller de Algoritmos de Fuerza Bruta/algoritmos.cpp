/**		Taller de Algoritmos de Fuerza Bruta
			09/Agosto/2017  William Aguirre Zapata**/
			
#include <iostream>
#include <conio.h>
using namespace std;

int exponente(int n,int a) {
	/**
	Descripci�n: calcula la potencia de un numero llamado base elevado a una potencia.
	Entradas: n: numero entero que representa la base
			  a: numero entero que representa el exponente
	Salidas: poten: numero entero que es el resultado de la potencia.	
	**/
	int poten=1;
	int i=0;
	while(i<n){
		poten=poten*a;
		i=i+1;
	}
	return poten;
}

int busquedadSecuencial(int k,int n, int a[]){
	/**
	Descripci�n: El algoritmo simplemente compara sucesivamente los elementos de un arreglo dado con una clave dada hasta 
				encontrarla o llegar al final
	Entradas: k: numero entero que representa el numero a buscar en el arreglo
			  n: numero entero que representa la cardinalidad del arreglo
			  a[]: arreglo de numeros enteros que entra por par�metro.
	Salidas: retorna i: retorna un numero entero que indica la posici�n del dato k en el arreglo.
			 retorna -1: retorna -1 si no encuentra el dato k en el arreglo.	
	**/
	for(int i=0;i<n;i++){
		if(a[i]==k){
			return i;
		}
	}
	return -1;
}

	
void burbuja(int a[], int tam){
	/**
	Descripci�n: Ordenamiento por Burbuja: La operaci�n b�sica de este algoritmo es la comparacion A[j+1] < A[j] y 
				el intercambio swap A[j] and A[j+1]. 
	Entradas: tam: numero entero que representa la cardinalidad o tama�o del arreglo
			  a[]: arreglo de numeros enteros que entra por par�metro.
	Salidas: a[tam]: arreglo ordenado de menor a mayor
	**/
    int temp = 0;
    for(int i=1; i<tam; i++){
        for(int j=0;j<tam-i;j++){
            if( a[j]>a[j+1] ){
                temp=a[j+1];
                a[j+1]=a[j]; 
                a[j]=temp;
            }
        }
    }
}

void seleccion(int a[], int n){
	/**
	Descripci�n: Ordenamiento por Selecci�n: Sobre el arreglo completo de n elementos se busca el elemento m�nimo y se lo 
				intercambia con el primer elemento del arreglo. As� el menor elemento ya ubicado. Entonces, otra vez se busca
				el menor elemento pero ahora desde la posici�n siguiente hasta la final y se intercambia con el elemento a partir
				del cual se arranc� la b�squeda. 
	Entradas: n: numero entero que representa la cardinalidad o tama�o del arreglo
			  a[]: arreglo de numeros enteros que entra por par�metro.
	Salidas: a[n]: arreglo ordenado de menor a mayor
	**/
	int i,j,temp;
	int minimo=0;
	for(i=0 ; i<n-1 ; i++){
	   minimo=i;
	   for(j=i+1 ; j<n ; j++){
	   		if (a[minimo] > a[j]){
	   			minimo=j;
			   } 
	   }
	   temp=a[minimo];
	   a[minimo]=a[i];
	   a[i]=temp;
	}	
}


int emparejamiento(char *T, int n , char *P, int m){
	/**
	Descripci�n: Emparejamiento de Cadenas: El algoritmo comieza alineando el patr�n al inicio del texto.
				Entonces cada caracter de el patr�n se compara al correspondiente segmento del texto.
				Si empareja entonces retorna la posici�n, se mueve al siguiente car�cter hasta el final.
	Entradas: T: Un texto largo de n caracteres
			  n: numero entero que representa el tama�o de T (Texto largo)
			  P: Un patr�n o cadena de m caracteres para ser buscado en el texto largo
			  m: numero entero que representa el tama�o del Patr�n.
	Salidas: retorna i: retorna un numero entero que indica la posici�n del Patr�n en el Texto largo.
			 retorna -1: retorna -1 si no encuentra el Patr�n en el Texto Largo.
	**/
	int i;
    for(i=0;i<=n-m;i++){ 
		int j=0;
        while(j<m && P[j] == T[i+j]) {
			j++; 
		}
        if(j==m) {
			return i;
		}
    }
	return -1;
}
