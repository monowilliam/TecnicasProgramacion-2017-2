int sumatoria (int n) {
	int sum = 0; 
	for (int i=1; i<=n; i++) 
		sum += n; 

	return sum;
}

#include <stdio.h>
void main () {
	printf ("%d", sumatoria (5));
}

