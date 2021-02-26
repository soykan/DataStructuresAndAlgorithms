#include <stdio.h>

int linearSearch(int dizi[], int N, int aranan) {
    for(int i=0; i<N; i++) {
        if (dizi[i] == aranan) {
            return i;
        }
    }
    return -1;
}

int main() {
    int dizi[] = {5, 3, 11, 9, 21, 18, 20, 4};
    int uzunluk = sizeof(dizi) / sizeof(dizi[0]);
    int aranan = 21;
    int arananElemanIndex = linearSearch(dizi, uzunluk, aranan);
    printf("Aranan elemanın indeksi: %d\n", arananElemanIndex);
    return 0;
}