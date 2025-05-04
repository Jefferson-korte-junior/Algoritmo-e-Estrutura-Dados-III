// FEITO EM DUPLA POR: BRUNO E. S. ALCANTARA, RA: 2677156 & JEFFERSON K. JUNIOR, RA: 2651114.

#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"
#include "fila.h"

int main() {
    
    struct aluno alunos1[4] = {
        {2,"Andre",9.5,7.8,8.5},
        {4,"Ricardo",7.5,8.7,6.8},
        {1,"Bianca",9.7,6.7,8.4},
        {3,"Ana",5.7,6.1,7.4}
    };

    struct aluno alunos2[4] = {
        {8,"Bruno",9.5,7.8,8.5},
        {5,"Igor",7.5,8.7,6.8},
        {6,"Jefferson",9.7,6.7,8.4},
        {7,"Marciano",5.7,6.1,7.4}
    };

    Fila *fila1 = cria_Fila();
    Fila *fila2 = cria_Fila();
    Fila *fila3 = cria_Fila();

    for (int i = 0; i < 4; i++) {
        insere_Fila(fila1, alunos1[i]);
        insere_Fila(fila2, alunos2[i]);
    }

    ordenarFila(fila1);
    ordenarFila(fila2);

    ordenarPreencherFila(fila1, fila2, fila3);

    imprime_Fila(fila3);

    libera_Fila(fila1);
    libera_Fila(fila2);

    return 0;
}

/*
    Crio dois vetores de alunos, ambos com numero de matricula desordenados, crio 3 filas, insiro o primeiro vetor na primeira fila e o segundo vetor na segunda fila, deixando apenas o terceiro livre.
    Ai chamo a função ordenar fila nos nas duas filas preenchidas, que ordena de acordo com o numero de matricula a partir de uma comparação em loop dentro da fila.
    Depois chamo a função ordenarPreencherFila que apenas preenche a terceira fila com elementos da primeira e segunda e depois chama a função ordenar, assim ordenando todos os elementos das duas filas.
    Depois imprimo mostrando-os em ordem e em sequida finalizando libero memória das duas filas
*/