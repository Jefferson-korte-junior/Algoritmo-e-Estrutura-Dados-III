#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {

    Pilha *input = criarPilha();
    char c;

    printf("> Digite algo:\n");
    while ((c = getchar()) != '\n' && c != EOF) {
        push(input, c);
    }

    printf("\nInverso:\n");
    printc(input);

    destroy(input);

    return 0;
}

//Realizado em dupla: Jefferson korte junior e bruno alcantara

//Apenas pego e vou imprimindo o valor que esta no topo da pilha, assim automaticamnete ja invertendo a ordem na hora de printar a pilha.