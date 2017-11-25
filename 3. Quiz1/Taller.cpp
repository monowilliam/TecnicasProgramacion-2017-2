#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void puntosCercanos(int a[], int b[], int n );



int main(){
	
	int a[]={2,5,7,4};
	int b[]={6,9,9,5};
	int n = 4;
	puntosCercanos( a, b, n);
	system("pause");
}

void puntosCercanos( int a[], int b[], int n ){
	int minDistancia = 9999;
	int p,q;
	int p1 = -1;
	int p2 = -1;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			p = a[i];
			q = b[j];
			if ( abs(p-q) < minDistancia ) {
				minDistancia = abs(p-q);
				p1 = p;
				p2 = q;
			}
		}
	}
	cout << p1 << p2;
}
