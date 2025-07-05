#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main() {
    GrafoLista* gr = cria_GrafoLista(4);

    insereArestaLista(gr, 0, 1, 2);
    insereArestaLista(gr, 0, 2, 1);
    insereArestaLista(gr, 1, 3, 3);
    insereArestaLista(gr, 2, 3, 4);

    printf("Grafo:\n");
    for (int con = 0; con < gr->nos; con++) {
        printf("%d: ", con);
        Lista* aux = gr->vet[con];
        while (aux) {
            printf("%d(%.2f) ", aux->destino, aux->peso);
            aux = aux->prox;
        }
        printf("\n");
    }

    printf("\nRemovendo aresta\n");
    removeArestaLista(gr, 0, 1);

    printf("Grafo apos a remoção:\n");
    for (int con = 0; con < gr->nos; con++) {
        printf("%d: ", con);
        Lista* aux = gr->vet[con];
        while (aux) {
            printf("%d(%.2f) ", aux->destino, aux->peso);
            aux = aux->prox;
        }
        printf("\n");
    }

    libera_GrafoLista(gr);

    return 0;
}