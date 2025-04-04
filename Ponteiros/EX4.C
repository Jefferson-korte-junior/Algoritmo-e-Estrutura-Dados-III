#include <stdio.h>
#include <stdlib.h> 

int main () {
    int N, *vetor;
    printf ("-----------------------------\n");
    printf ("Digite o valor de N: ");
    scanf ("%d", &N); 
    printf ("\n-----------------------------\n");

    vetor =  (int*)malloc(N*sizeof(int));
    if (vetor == NULL) {
        printf ("Nao foi possivel alocar na memoria\n");
        return 1;
    }
    printf ("-----------------------------\n");

    for (int i = 0; i < N; i++) {
        vetor[i] = i; 
    }


    printf("Valores do vetor:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);

    printf ("\n-----------------------------\n");


    return 0;
}