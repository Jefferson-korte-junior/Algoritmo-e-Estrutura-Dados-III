// FEITO EM DUPLA POR: BRUNO E. S. ALCANTARA, RA: 2677156 & JEFFERSON K. JUNIOR, RA: 2651114.

#include <stdio.h>
#include <stdlib.h>

#include "ListaDinEncadDupla.c"

int main() {

    noDesc fila;

    inicializa_noDesc(&fila);

    for (int i = 0; i < 10; i++) 
        enfileirar(&fila, i);

    int valor;
    while (desenfileirar(&fila, &valor)) 
        printf("-> %d\n", valor);

    return 0;
}

/*
    Crio e inicializo a fila, enfileiro numeros de 0 a 9, e depois desenfileiro
    printando os valores da lista.
*/
