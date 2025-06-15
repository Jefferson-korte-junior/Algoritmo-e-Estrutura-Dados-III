#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main() {

    int n[] = {2, 2, 4, 8, 6, 3};
    int n2[] = {12, 12, 14, 18, 16, 13};

    ArvBin *raiz = cria_ArvBin();
    ArvBin *raiz2 = cria_ArvBin();

    for (int i = 0; i < 6; i++) 
        insere_ArvBin(raiz, n[i]);

    for (int i = 0; i < 6; i++) 
        insere_ArvBin(raiz2, n2[i]);

    if (similares(raiz, raiz2)) {
        printf("-> Similares!\n");
    } else {
        printf("-> Nao Similares!\n");
    }

    libera_ArvBin(raiz);

    system("pause");

    return 0;
}

// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

/*      similares
    Função recursiva que percorre duas arvores verificando se as duas
    são do mesmo "formato", não verificando os valores de cada nó.
    Aí compara se ambas são vazias ou se ambas possuem subárvores esquerdas 
    similares e subárvores direitas similares. Caso alguma diferença estrutural
    seja encontrada, a função retorna 0, se não 1.
*/
