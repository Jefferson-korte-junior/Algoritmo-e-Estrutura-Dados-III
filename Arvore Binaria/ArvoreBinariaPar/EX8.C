#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main() {
    ArvBin* raiz = cria_ArvBin();

    insere_ArvBin(raiz, 'M');
    insere_ArvBin(raiz, 'F');
    insere_ArvBin(raiz, 'S');
    insere_ArvBin(raiz, 'D');
    insere_ArvBin(raiz, 'J');
    insere_ArvBin(raiz, 'P');
    insere_ArvBin(raiz, 'U');
    insere_ArvBin(raiz, 'A');
    insere_ArvBin(raiz, 'E');
    insere_ArvBin(raiz, 'H');
    insere_ArvBin(raiz, 'Q');
    insere_ArvBin(raiz, 'T');
    insere_ArvBin(raiz, 'W');
    insere_ArvBin(raiz, 'K');

    printf("Impressao detalhada da arvore:\n");
    imprimeDetalhadaChar(*raiz, -1, "raiz");

    libera_ArvBin(raiz);
    return 0;
}

//Feito em dupla Jefferson korte RA: 2651114 e Bruno E. S. Alcantara RA: 2677156

//A logica usada foi a mesma do exercicio 2, apenas adicionei para ser do tipo caractere o print e nao int como estava a função imprimeDetalhada..