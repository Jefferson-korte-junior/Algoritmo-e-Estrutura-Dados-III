#include <stdio.h>
#include <stdlib.h>

void inverte_vetor(int *v1, int *v2, int n){
    int maior = 0;
    int con = 0;

    for (con = 0; con < n; con++){
        if (v1[con] > maior){
            maior = v1[con]; 
        }
        v2[con] = v1[n-con-1]; 
    }

    printf ("O maior valor dentro do vetor eh: %d\n", maior);
    printf ("\n-----------------------------\n");
    printf ("Vetor 2 inverso do vetor 1:\n");
    for (con = 0; con < n; con++){
        printf ("vetor2[%d]: %d\n", con, v2[con]);
    }
    printf ("\n-----------------------------\n");

}

int main () {
    int N, *vetor1, *vetor2;

    printf ("-----------------------------\n");
    printf ("Digite o valor de N: ");
    scanf ("%d", &N);
    printf ("\n-----------------------------\n");

    vetor1 = (int*)malloc(N*sizeof(int)); //Alocando a memoria pro vetor 1

    if (vetor1 == NULL) {
        printf ("Nao foi possivel alocar na memoria\n");
        return 1;
    }

    printf ("Preencha o vetor 1:\n");
    for (int con = 0; con < N; con++){
        printf ("vetor1[%d]: ", con);
        scanf ("%d", &vetor1[con]);
    }
    printf ("\n-----------------------------\n");
    printf ("Valores do vetor 1:\n");
    for (int con = 0; con < N; con++){
        printf ("vetor1[%d]: %d\n", con, vetor1[con]);
    }
    printf ("\n-----------------------------\n");

    vetor2 = (int*)malloc(N*sizeof(int)); //alocando memoria pro vetor 2
    if (vetor2 == NULL) {
        printf ("Nao foi possivel alocar na memoria\n");
        return 1;
    }

    inverte_vetor(vetor1, vetor2, N);

    return 0;
}

//A logica usada para inverte o vetor 1 foi bem simples, apenas fiz um for para varrer o vetor1, e apos isso fiz que vetor2[con] recebesse o vetor1[n-con-1] , assim o vetor 2 ia pegando os ultimos valores do vetor 1 e colando nas suas primeiras posiçoes.