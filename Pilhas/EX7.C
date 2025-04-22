#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {

    int elementos[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Pilha *pilha = criarPilha();
    for (int i = 0; i < 11; i++) {
        push(pilha, elementos[i]);
    }

    printf("Valores da pilha:\n");
    print(pilha);

    printf("\nQuantidade de pares: %d\n", countPar(pilha));
    printf("\nQuantidade de impares: %d\n", countImpar(pilha));

    destroy(pilha);

    return 0;
}

//Realizado em dupla: Jefferson korte junior e bruno alcantara

//Aqui apenas fiz uma verificação igual fiz nas outras questoes para varrer a pilha inteira: while (celula != NULL) ele continua a varrer. E adiciono uma verificação para ver se o numero é par ou nao e caso for eu somo 1 a variavel totalPares se nao somo 1 a variavel totalImpares.