#include <stdio.h>
#include <stdlib.h>

int** alocarMatriz(int linhas, int colunas){
    int **matriz = (int**)malloc(linhas * sizeof(int*));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para as linhas\n");
        return NULL; 
    }

    for (int con = 0; con < linhas; con++){
        matriz[con] = (int*)malloc(colunas * sizeof(int));

        if (matriz[con] == NULL) {
            printf("Erro ao alocar memória para as colunas\n");

            for (int con = 0; con < colunas; con++) {
                free(matriz[con]);
            }

            return NULL;
        }

    }

    return matriz;
}


void liberarMatriz(int** matriz, int linhas) {
    for (int con = 0; con < linhas; con++) {
        free(matriz[con]);
    }

    free(matriz);
}

int main (){
    int linhas, colunas;
    int **matriz;

    printf ("--------------------------------------\n");
    printf ("Digite o numero de linhas da matriz: ");
    scanf  ("%d", &linhas);
    printf ("Digite o numero de colunas da matriz: ");
    scanf  ("%d", &colunas);
    printf ("\n--------------------------------------\n");


    matriz = alocarMatriz(linhas, colunas);
    if (matriz == NULL) {
        printf("Erro ao alocar memória para a matriz.\n");
        return 1;
    }

    printf("Preencha a matriz (%d x %d):\n", linhas, colunas);
    for (int con = 0; con < linhas; con++) {
        for (int c = 0; c < colunas; c++) {
            printf("Digite o valor para a posicao [%d][%d]: ", con, c);
            scanf("%d", &matriz[con][c]);
        }
    }

    printf ("---------------------------------------\n");

    printf("\nMatriz preenchida:\n");
    printf("--------------------\n");
    for (int con = 0; con < linhas; con++) {
        for (int c = 0; c < colunas; c++) {
            printf("%d ", matriz[con][c]);
        }
        printf("\n");
    }

    printf ("---------------------------------------\n");


    liberarMatriz(matriz, linhas);


    return 0;
}

//Comecei pedindo o numero de linhas e colunas da matriz, depois ja chamo a função que fara a alocação da matriz, quando retornada   pede para o usuario preencher a matriz, e depois a printa na tela.

//A logica usada na função para alocar a matriz: primeiro fiz um ponteiro duplo apontando para as linhas e apos um ponteiro simples apontando para as colunas, e coloquei um IF para verificação de erro caso o aconteça.