#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ikiYonluBaglantiliListe {
    char mesaj[100];
    struct ikiYonluBaglantiliListe *arka;
    struct ikiYonluBaglantiliListe *on;
} doublyLinkedList;

doublyLinkedList *ilk = NULL;
doublyLinkedList *son = NULL;

void ekle(doublyLinkedList *eklenecek) {
    if (ilk != NULL) {
        son->arka = eklenecek;
        eklenecek->on = son;
        son = eklenecek;
        son->arka = NULL;
    } else {
        ilk = eklenecek;
        son = eklenecek;
        ilk->arka = NULL;
        ilk->on = NULL;
    }
}

int listele() {
    doublyLinkedList *p;
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

doublyLinkedList *ara(char *aranan) {
    doublyLinkedList *p;
    p = ilk;
    while(p != NULL) {
        if (strcmp(p->mesaj, aranan) == 0) {
            return p;
        }
        p = p->arka;
    }
    return 0;
}

doublyLinkedList *sil(char *silinecek) {
    doublyLinkedList *p;
    p = ara(silinecek);
    if (p == NULL) {
        return NULL;
    }

    if (ilk == p) {
        if (ilk->arka != NULL) {
            ilk = p->arka;
            ilk->on = NULL;
        } else {
            ilk = NULL;
            son = NULL;
        }
    } else {
        p->on->arka = p->arka;
        if (p == son) {
            son = son->on;
        } else {
            p->arka->on = p->on;
        }
    }
    free(p);
    return p;
}

int main() {
    doublyLinkedList *p = malloc(sizeof(doublyLinkedList));
    strcpy(p->mesaj, "Merhaba");
    ekle(p);

    doublyLinkedList *q = malloc(sizeof(doublyLinkedList));
    strcpy(q->mesaj, "Nasılsın");
    ekle(q);

    printf("Listeleme sonucu:\n");
    listele();
    printf("\n");

    doublyLinkedList *r;
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
}