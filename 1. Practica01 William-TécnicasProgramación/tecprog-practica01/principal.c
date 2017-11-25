#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sortMS.h"
#include "random_sample.h"

#include <sys/time.h>

float diferenciaTiemposMilisegundos(struct timeval t0, struct timeval t1) {
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int main() {
	int i;
	int N = 1000;
    int *array  = (int *) random_sample (N);

	struct timeval tiempoInicio;
	struct timeval tiempoFinal;
	float tiempoEjecucion;

	/*
    printf("Arreglo de entrada es: \n");
    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
	*/

    //insertion_sort(array);
	
	gettimeofday (&tiempoInicio, 0);
	sortMS (array, N);
	gettimeofday (&tiempoFinal, 0);

	tiempoEjecucion = diferenciaTiemposMilisegundos (tiempoInicio, tiempoFinal);

	printf ("\nTiempo de Ejecucion: %f\n", tiempoEjecucion);
	
	/*
    printf("\nArreglo ordenado es: \n");
    for (int i = 0;i < N; i++) {
        printf(" %d", array[i]);
    }
	*/

	return 0;
}

