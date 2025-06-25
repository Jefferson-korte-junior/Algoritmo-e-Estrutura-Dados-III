// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main() {

    ArvAVL* raiz = cria_ArvAVL();

    for (int i = 0; i < 30; i += 10)
        insere_ArvAVL(raiz, i);

    printf("-> Arvore:\n");
    emOrdem_ArvAVL(raiz);
    printf("\n");

    libera_ArvAVL(raiz);

    system("pause");

    return 0;
}
