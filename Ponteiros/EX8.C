#include <stdio.h>
#include <stdlib.h>

void lerElemntos (int n, int* vetor){
    printf ("------------------------------\n");
    for (int con = 0; con < n; con++){
        printf ("Digite o valor [%d] : ", con + 1);
        scanf ("%d", &vetor[con]);
    }
    printf("------------------------------\n");
}

int main (){
    int n;
    int *vetor;

    printf ("------------------------------\n");
    printf (" Digite o valor de N :");
    scanf ("%d", &n);
    printf ("------------------------------\n");

    vetor = (int*) malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Nao foi possivel alocar memória.\n");
        return 1;
    }

    lerElemntos(n, vetor);

    printf("Os elementos do vetor sao:\n");
    for (int con = 0; con < n; con++) {
        printf("vetor[%d]: %d\n", con, vetor[con]);
    }
    printf("------------------------------\n");

    free(vetor);
    
    return 0;
}

//Apenas pedi pro usuario digitar um valor de N, logo apos aloquei o vetor e chamei a funcao lerElemntos que pede para o usuario digitar os valores do vetor e depois imprimi os valores na tela.