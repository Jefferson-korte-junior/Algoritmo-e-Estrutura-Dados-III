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
    insere_ArvBin(raiz, 35);
    insere_ArvBin(raiz, 25);

    printf("Arvore original:\n");
    imprimeDetalhada(*raiz, -1, "raiz");

    printf("\nRemovendo todos os valores pares...\n");
    removePares_ArvBin(raiz);

    printf("\nArvore apos remover os pares:\n");
    imprimeDetalhada(*raiz, -1, "raiz");

    libera_ArvBin(raiz);

    return 0;
}

//Feito em dupla Jefferson korte RA: 2651114 e Bruno E. S. Alcantara RA: 2677156

//A função removePares_ArvBin começa verificando se a árvore está vazia, se o ponteiro da árvore ou o nó atual for NULL, ela simplesmente retorna e não faz nada. Em seguida, ela percorre primeiro os filhos, chamando ela mesma para o filho esquerdo e para o direito, garantindo que vai até o fundo da árvore antes de tentar remover o nó atual. Depois verifica se o valor do nó é par e, se for chama a função de remoção para eliminar esse nó. Por fim, após remover um nó par, como o ponteiro pode mudar, a função se chama novamente para o mesmo nó, garantindo que, se o novo nó também for par, ele seja removido.