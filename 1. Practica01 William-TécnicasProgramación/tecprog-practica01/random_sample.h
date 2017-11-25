int* random_sample(int size) {
	int i, j, k;
	int *elements = malloc(size*sizeof(int));

	/* Assign random integers */
	for (i = size - 1; i > 0; --i) 
		elements[i] = rand() % 256;

	/* Shuffle */
#ifdef Shuffle
	for (i = size - 1; i > 0; --i) {
		j = rand() % size;

		k = elements[i];
		elements[i] = elements[j];
		elements[j] = k;
	}
#endif
	return elements;
}

