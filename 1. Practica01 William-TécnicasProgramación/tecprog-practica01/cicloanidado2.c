#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "random_sample.h"

int ciclosAnidados2 (int A[], int n) {
	int sum1, i, j, sum2;
	sum1 = 0; 
	for (i=1; i<=n; i++)  // First double loop 
		for (j=1; j<=n; j++)  //  do n times 
			sum1++; 

	sum2 = 0; 
	for (i=1; i<=n; i++)  // Second double loop 
		for (j=1; j<=i; j++)  //  do i times 
			sum2++; 

	return sum2;
}

// Main Program
void main () {
	int N = 100;
	int *A = (int *) random_sample (N);
	
	printf ("%d", ciclosAnidados2 (A, 100));
}

