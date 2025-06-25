// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main() {
    int elementos[] = {10, 20, 30, 40, 50, 60, 70};

    ArvAVL *raiz = cria_ArvAVL();
    ArvAVL *raiz2;

    for (int i = 0; i < 7; i++)
        insere_ArvAVL(raiz, elementos[i]);

    raiz2 = transforma(raiz);

    printf("-> Arvore Transformada:\n");
    emOrdem_ArvAVL(raiz2);
    printf("\n");

    libera_ArvAVL(raiz);
    libera_ArvAVL(raiz2);

    system("pause");

    return 0;
}
