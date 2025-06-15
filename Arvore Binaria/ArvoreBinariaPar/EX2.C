#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"


int main() {
    ArvBin* raiz = cria_ArvBin();

    insere_ArvBin(raiz, 50);
    insere_ArvBin(raiz, 30);
    insere_ArvBin(raiz, 20);
    insere_ArvBin(raiz, 40);
    insere_ArvBin(raiz, 70);
    insere_ArvBin(raiz, 60);
    insere_ArvBin(raiz, 80);

    printf("Imprimindo Arvore completa:\n");
    imprimeDetalhada(*raiz, -1, "raiz");

    libera_ArvBin(raiz);
    return 0;
}

//A função imprimeDetalhada começa verificando se o nó é nulo, se for ela simplesmente retorna. Depois para cada nó, mostra quem é o pai, se é raiz, se é filho da esquerda ou da direita e se é folha. Assim, fica fácil entender como a árvore está organizada.


