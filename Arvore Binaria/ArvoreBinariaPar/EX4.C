#include <stdio.h>
#include "ArvoreBinaria.h"

int main() {
    ArvBin* raiz = cria_ArvBin();

    // Inserindo alguns valores na árvore
    insere_ArvBin(raiz, 50);
    insere_ArvBin(raiz, 30);
    insere_ArvBin(raiz, 20);
    insere_ArvBin(raiz, 40);
    insere_ArvBin(raiz, 70);
    insere_ArvBin(raiz, 60);
    insere_ArvBin(raiz, 80);

    printf("Impressao detalhada da arvore:\n");
    imprimeDetalhada(*raiz, -1, "raiz");

    printf("\nFolhas em ordem decrescente:\n");
    imprimeFolhasDecrescente(*raiz);
    printf("\n");
    libera_ArvBin(raiz);

    return 0;
}

//Feito em dupla Jefferson korte RA: 2651114 e Bruno E. S. Alcantara RA: 2677156

//A função imprimeFolhasDecrescente serve para mostrar só as folhas da árvore, começando pelas maiores. Isso funciona porque, numa árvore binária de busca, tudo que está à direita é sempre maior e tudo à esquerda é menor. Então, indo primeiro pra direita, depois pra esquerda, a função já imprime as folhas do maior pro menor,