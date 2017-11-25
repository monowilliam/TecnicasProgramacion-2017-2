void sortBB(int * array, int N) {
	int temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (N - i - 1); j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
