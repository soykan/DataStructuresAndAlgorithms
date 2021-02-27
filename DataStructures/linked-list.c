#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct baglantiliListe {
    char mesaj[100];
    struct baglantiliListe *arka;
} linkedList;

linkedList *ilk = NULL;
linkedList *son = NULL;

void ekle(linkedList *eklenecek) {
    if (ilk != NULL) {
        son->arka = eklenecek;
        son = eklenecek;
        eklenecek->arka = NULL;
    } else {
        ilk = eklenecek;
        son = eklenecek;
        eklenecek->arka = NULL;
    }
}

int listele() {
    linkedList *p;
    p = ilk;
    if (p == NULL) {
        return -1;
    }
    while (p != NULL) {
        printf("mesaj: %s\n", p->mesaj);
        p = p->arka;
    }
    return 0;
}

linkedList *ara(char *aranan) {
    linkedList *p;
    p = ilk;
    while (p) {
        if (strcmp(p->mesaj, aranan) == 0) {
            return p;
        }
        p = p->arka;
    }
    return NULL;
}

linkedList *sil(char *silinecek) {
    linkedList *p, *birOnceki;
    p = ilk;
    birOnceki = NULL;

    while (p != NULL) {
        if (strcmp(silinecek, p->mesaj) == 0) {
            break;
        }
        birOnceki = p;
        p = p->arka;
    }

    if (p != NULL) {
        if (birOnceki == NULL) {
            if (ilk == son) {
                ilk = NULL;
                son = NULL;
            } else {
                ilk = ilk->arka;
            }
        } else {
            birOnceki->arka = p->arka;
            if (birOnceki->arka == NULL) {
                son = birOnceki;
            }
            free(p);
            return p;
        }
    } else {
        return NULL;
    }
}

int main() {
    linkedList *p = malloc(sizeof(linkedList));
    strcpy(p->mesaj, "Merhaba");
    ekle(p);

    linkedList *q = malloc(sizeof(linkedList));
    strcpy(q->mesaj, "Nasılsın");
    ekle(q);

    printf("Listeleme sonucu:\n");
    listele();
    printf("\n");

    linkedList *r;
    r = ara("Nasılsın");
    if (r != NULL) {
        printf("Bulundu: %s\n", r->mesaj);
    } else {
        printf("Bulunamadı.\n");
    }
    printf("\n");

    sil("Nasılsın");
    printf("Silme işlemi sonrası listeleme sonucu:\n");
    listele();
    return 0;
}