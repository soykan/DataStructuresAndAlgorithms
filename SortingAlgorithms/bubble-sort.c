#include <stdio.h>

void bubbleSort(int D[], int N) {
    int gecici, i, k;
    for(i=0; i<(N-1); i++) {
        for(k=0; k<(N-1-i); k++) {
            if (D[k] > D[k+1]) {
                gecici = D[k];
                D[k] = D[k+1];
                D[k+1] = gecici;
            }
        }
    }
}

int main() {
    int dizi[] = {5, 3, 11, 9, 21, 18, 20, 4};
    int uzunluk = sizeof(dizi) / sizeof(dizi[0]);
    bubbleSort(dizi, uzunluk);
    
    for(int i=0; i<uzunluk; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
    return 0;
}