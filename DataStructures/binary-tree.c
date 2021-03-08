#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
    int bilgi;
    char mesaj[100];
    struct tree *sag, *sol; 
} binaryTree;

binaryTree *kok = NULL;

void ekle(binaryTree *agacKok, binaryTree *yeni) {
    if (agacKok == NULL) {
        kok = yeni;
    } else {
        if (yeni->bilgi <= agacKok->bilgi) {
            if (agacKok->sol == NULL) {
                agacKok->sol = yeni;
            } else {
                ekle(agacKok->sol, yeni);
            }
        } else {
            if (agacKok->sag == NULL) {
                agacKok->sag = yeni;
            } else {
                ekle(agacKok->sag, yeni);
            }
        }
    }
}

void listele(binaryTree *agacKok) {
    if (agacKok != NULL) {
        listele(agacKok->sol);
        printf("%d: %s\n", agacKok->bilgi, agacKok->mesaj);
        listele(agacKok->sag);
    }
}
 
binaryTree *ara(binaryTree *agacKok, int aranan) {
    while (agacKok != NULL && agacKok->bilgi != aranan) {
        if (aranan < agacKok->bilgi) {
            agacKok = agacKok->sol;
        } else {
            agacKok = agacKok->sag;
        }
    }
    return agacKok;
}

binaryTree *sil(binaryTree *agacKok, int silinecek) {
    binaryTree *qa, *q, *qc, *sa, *s;
    if (agacKok == NULL) {
        return NULL;
    }
    q = agacKok;
    qa = NULL; 
    while (q != NULL && q->bilgi != silinecek) {
        qa = q;
        if (silinecek <= q->bilgi) {
            q = q->sol;
        } else {
            q = q->sag;
        }
    }
    if (q == NULL) {
        return NULL;
    }

    if (q->sol != NULL && q->sag != NULL) {
        s = q->sol;
        sa = q;
        while (s->sag != NULL) {
            sa = s;
            s = s->sag;
        }
        q->bilgi = s->bilgi;
        strcpy(q->mesaj, s->mesaj);
        q = s;
        qa = sa;
    }

    if (q->sol != NULL) {
        qc = q->sol;
    } else {
        qc = q->sag;
    }

    if (q == agacKok) {
        kok = qc;
    } else {
        if (q == qa->sol) {
            qa->sol = qc;
        } else {
            qa->sag = qc;
        }
    }
    free(q);
    return q;
}

int main() {
    binaryTree *bt = malloc(sizeof(binaryTree));

    binaryTree *bt1 = malloc(sizeof(binaryTree));
    bt1->bilgi = 1;
    strcpy(bt1->mesaj, "Merhaba");


    binaryTree *bt2 = malloc(sizeof(binaryTree));
    bt2->bilgi = 2;
    strcpy(bt2->mesaj, "Nasılsın");

    binaryTree *bt3 = malloc(sizeof(binaryTree));
    bt3->bilgi = 3;
    strcpy(bt3->mesaj, "Görüşürüz");

    ekle(kok, bt1);
    ekle(kok, bt2);
    ekle(kok, bt3);

    printf("Ekleme sonrası listeleme:\n");
    listele(kok);

    binaryTree *bulunan = malloc(sizeof(binaryTree));

    bulunan = ara(kok, 2);
    printf("Bulunan -> %d: %s\n", bulunan->bilgi, bulunan->mesaj);
    sil(kok, 3);

    printf("Silme işlemi sonrası listeleme:\n");
    listele(kok);
    return 0;
}