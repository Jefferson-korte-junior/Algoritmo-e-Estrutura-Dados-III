#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main() {
    ArvAVL* avl = cria_ArvAVL();
    int con;
    int N = 10, dados[10] = {1,2,3,10,4,5,9,7,8,6};

    for(con = 0; con < N; con++) {
        insere_ArvAVL(avl, dados[con]);
    }

    printf("arvore em ordem:\n");
    emOrdem_ArvAVL(avl);
    printf("\n");

    if (verificaAVL(avl))
        printf("A arvore e AVL\n");
    else
        printf("A arvore nao e AVL\n");

    remove_ArvAVL(avl, 6);
    printf("----------------------------------------\n");
    printf("\nApos remover 6:\n");
    emOrdem_ArvAVL(avl);
    printf("\n----------------------------------------\n");
    

    if (verificaAVL(avl))
        printf("A arvore e AVL\n");
    else
        printf("A arvore nao e AVL\n");

    libera_ArvAVL(avl);
    return 0;
}

// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

//criamos uma árvore AVL, inserimos dez valores nela, imprime a árvore em ordem, verifica se ela está balanceada como AVL, remove o valor 6, imprime novamente e faz uma nova verificação AVL. e no final libera a memória usada pela árvore. Onde podemos ver que ela se rebalanceia apos a remoção do no 6.