#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main() {

    int n[] = {2, 2, 4, 8, 6, 3};

    ArvBin *raiz = cria_ArvBin();

    for (int i = 0; i < 6; i++)
        insere_ArvBin(raiz, n[i]);

    printf("-> %d\n", qtdValor(raiz, 2));

    libera_ArvBin(raiz);

    system("pause");

    return 0;
}

// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

/*      qtdValor
    Função recursiva que percorre a arvore contando quantas vezes
    um determinado valor aparece nos nós da árvore. A cada nó, verifica
    se o valor do nó atual é igual ao valor solicitado. Se for, soma 1
    ao total e continua a busca nas subárvores esquerda e direita.
*/
