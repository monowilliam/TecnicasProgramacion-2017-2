#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "random_sample.h"

int ciclosAnidados1 (int A[], int n) {
	int sum = 0; 
	for (int i=1; i<=n; i++)  // First for loop 
		for (int j=1; j<=i; j++)  //  is a double loop 
			sum++; 
		
	for (int k=0; k<n; k++)  // Second for loop 
		A[k] = k;

	return sum;
}

// Main Program
void main () {
	int N = 100;
	int *A = (int *) random_sample (N);
	
	printf ("%d", ciclosAnidados1 (A, 100));
}

