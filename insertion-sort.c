#include <stdio.h>

void insertionSort(int D[], int N) {
    int i, k, ekle;
    for(i=1; i<N; i++) {
        ekle = D[i];
        for(k=i-1; k>=0 && ekle<=D[k]; k--) {
            D[k+1] = D[k];
        }
        D[k+1] = ekle;
    }
}

int main() {
    int dizi[] = {5, 3, 11, 9, 21, 18, 20, 4};
    int uzunluk = sizeof(dizi) / sizeof(dizi[0]);
    insertionSort(dizi, uzunluk);
    
    for(int i=0; i<uzunluk; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
    
    return 0;
}
