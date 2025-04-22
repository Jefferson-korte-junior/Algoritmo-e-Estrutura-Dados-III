#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {

    int elementos[] = {A, B, A, B, B, B};
    int elementos2[] = {B, A, B, A, A, A};

    Pilha *pilhaX = criarPilha();
    Pilha *pilhaY = criarPilha();
    for (int i = 0; i < 6; i++) {
        push(pilhaX, elementos[i]);
        push(pilhaY, elementos2[i]);
    }

    if (xCy(pilhaX, pilhaY)) {
        printf("\n-> Cadeia de caracteres equivalente da forma x C y!\n");
    } else {
        printf("\n-> Cadeia de caracteres nao equivalente da forma x C y!\n");
    }

    destroy(pilhaX);
    destroy(pilhaY);

    return 0;
}