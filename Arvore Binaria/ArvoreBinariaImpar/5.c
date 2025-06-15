#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main() {

    int n[] = {2, 2, 4, 8, 6, 3};

    ArvBin *raiz = cria_ArvBin();
    ArvBin *raiz2 = cria_ArvBin();

    for (int i = 0; i < 6; i++) {
        insere_ArvBin(raiz, n[i]);
        insere_ArvBin(raiz2, n[i]);
    }

    if (iguais(raiz, raiz2)) {
        printf("-> Iguais!\n");
    } else {
        printf("-> Diferentes!\n");
    }

    libera_ArvBin(raiz);

    system("pause");

    return 0;
}

// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

/*      iguais
    Função recursiva que percorre duas arvores verificando se os nós
    das arvores são do mesmo "formato" e se possuem os mesmos valores
    em cada nó correspondente. Para isso, compara os valores dos nós
    atuais e, em seguida, verifica se as subárvores esquerda e
    direita também são iguais. Caso encontre qualquer diferença,
    a função retorna 0, se não retorna 1.
*/