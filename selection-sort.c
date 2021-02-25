#include <stdio.h>

void selectionSort(int D[], int N) {
    int i, j, index, enKucuk;
    for(i=0; i<(N-1); i++) {
        enKucuk = D[N-1];
        index = N - 1;
        for(j=i; j<(N-1); j++) {
            if(D[j] < enKucuk) {
                enKucuk = D[j];
                index = j;
            }
        }
        D[index] = D[i];
        D[i] = enKucuk;

    }
}

int main() {
    int dizi[] = {5, 3, 11, 9, 21, 18, 20, 4};
    int uzunluk = sizeof(dizi) / sizeof(dizi[0]);
    selectionSort(dizi, uzunluk);
    for(int i=0; i<uzunluk; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
    return 0;
}