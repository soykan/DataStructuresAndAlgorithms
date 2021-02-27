#include <stdio.h>

void quickSort(int dizi[], int sol, int sag) {
    int j, k;
    int ortadaki, gecici;

    k = sol;
    j = sag;
    ortadaki = dizi[(sol+sag)/2];

    do {
        while(dizi[k]<ortadaki && k<sag) {
            k++;
        }
        while(ortadaki<dizi[j] && j>sol) {
            j--;
        }
        if(k<=j) {
            gecici = dizi[k];
            dizi[k] = dizi[j];
            dizi[j] = gecici;
            k++;
            j--;
        }
    } while(k<=j);

    if (sol<j) {
        quickSort(dizi, sol, j);
    }
    if (k<sag) {
        quickSort(dizi, k, sag);
    }
}

int main() {
    int dizi[] = {5, 3, 11, 9, 21, 18, 20, 4};
    int uzunluk = sizeof(dizi) / sizeof(dizi[0]);
    quickSort(dizi, 0, uzunluk - 1);
    
    for(int i=0; i<uzunluk; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
    return 0;
}