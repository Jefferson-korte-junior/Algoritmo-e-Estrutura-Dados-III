#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main() {

    int n[] = {5, 2, 4, 8, 6, 3};

    ArvBin *raiz = cria_ArvBin();

    for (int i = 0; i < 6; i++)
        insere_ArvBin(raiz, n[i]);

    printf("-> %d\n", qtdNosFolha(raiz));

    libera_ArvBin(raiz);

    system("pause");

    return 0;
}

// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

/*      qtdNosFolha
    Função recursiva que percorre a arvore verificando os nós.
    Caso o nó atual seja uma folha retorna 1. Caso contrário, a função
    retorna propria função somando a quantidade de folhas da subárvore
    da esquerda e da subárvore da direita. E quando a raiz for nula, ele
    retorna 0.
*/