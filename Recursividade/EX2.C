#include <stdlib.h>
#include <stdio.h>

int soma (int vetor[], int tamanhoVetor, int n){
    if (n ==tamanhoVetor){
        return 0;
    }else {
        return vetor[n] + soma(vetor, tamanhoVetor, n+1);
    }
}

main () {
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanhoVetor = sizeof(vetor) / sizeof(vetor[0]);
    int n = 0 ;
    
    printf ("--------------------------------------\n");
    printf ("Soma dos elementos do vetor: %d \n", soma(vetor, tamanhoVetor, n));
    printf ("--------------------------------------\n");

    return 0;
}

//Dupla Jefferson korte junior e Igor Marchi
//Nesse codigo primeiro eu peguei o tamanho do vetor utilizando o sizeof, depois sim criei uma função recursiva para somar os numeros do vetor

//A logica é baseada no indice N, que começa com 0. Se N for igual ao tamanho do vetor,a função retorna 0 e quer dizer que acabou os elementos do vetor, se nao siginifica que nao acabou todos os elementos do vetor e dai é somado o vetor[n] com a função recursiva chamando ela mesma e incrementando o valor de N + 1.