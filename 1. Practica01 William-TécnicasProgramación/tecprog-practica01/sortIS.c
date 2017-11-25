/* sorts the input */
void sortIS(int * array, int N) {
    int temp, i, j;

    for (i = 1;i < N;i++) {
        temp = array[i];
        j = i - 1;
        while (temp < array[j] && j >= 0) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }
}

