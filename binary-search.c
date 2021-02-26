 #include <stdio.h>

int binarySearch(int D[], int N, int aranan) {
    int ortadaki, sol=0, sag=N-1;
    while(sol<=sag) {
        ortadaki = (sol+sag)/2;
        if (aranan == D[ortadaki]) {
            return ortadaki;
        } else if (aranan > D[ortadaki]) {
            sol = ortadaki + 1;
        } else {
            sag = ortadaki - 1;
        }
    }
    return -1;
}


int main() {
    int dizi[] = {3, 4, 5, 9, 11, 18, 20, 21};
    int uzunluk = sizeof(dizi) / sizeof(dizi[0]);
    int aranan = 21;
    int arananElemanIndex = binarySearch(dizi, uzunluk, aranan);
    printf("Aranan elemanın indeksi: %d\n", arananElemanIndex);
    return 0;
 }