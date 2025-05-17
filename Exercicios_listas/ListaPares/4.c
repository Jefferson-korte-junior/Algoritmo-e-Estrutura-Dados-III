// FEITO EM DUPLA POR: BRUNO E. S. ALCANTARA, RA: 2677156 & JEFFERSON K. JUNIOR, RA: 2651114.

#include <stdio.h>
#include <stdlib.h>

#include "lista.c"

int main() {

    float numeros[] = {1.5, 2.5, 3.5, 4.5, 5.5};

    ListaFloat *lista = vetorParaLista(numeros, 5);

    imprimirListaFloat(lista);

    liberarListaFloat(lista);

    return 0;
}

/*
    Crio um vetor float com 5 números, crio uma lista através da função criada vetorParaLista passando
    como parametro o vetor e seu tamanho, e em seguida imprimo a lista.
*/