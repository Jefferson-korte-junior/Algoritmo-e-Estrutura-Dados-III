// FEITO EM DUPLA POR: BRUNO E. S. ALCANTARA, RA: 2677156 & JEFFERSON K. JUNIOR, RA: 2651114.

#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "pilha.h"

typedef struct aluno Aluno;

int main() {

    Aluno alunos1[4] = {
        {2,"Andre",9.5,7.8,8.5},
        {4,"Ricardo",7.5,8.7,6.8},
        {1,"Bianca",9.7,6.7,8.4},
        {3,"Ana",5.7,6.1,7.4}
    };

    Aluno alunos2[4] = {
        {1,"Bruno",9.5,7.8,8.5},
        {2,"Jefferson",7.5,8.7,6.8},
        {3,"Igor",9.7,6.7,8.4},
        {4,"Marciano",5.7,6.1,7.4}
    };

    Pilha *pilha1 = criarPilha();
    Pilha *pilha2 = criarPilha();

    for (int i = 0; i < 4; i++) {
        inserirPilha(pilha1, alunos1[i]);
        inserirPilha(pilha2, alunos2[i]);
    }

    FilaDePilha *filaDePilha = criarFilaDePilha();

    inserirPilhaNaFila(filaDePilha, pilha1);
    inserirPilhaNaFila(filaDePilha, pilha2);

    imprimirFilaDePilha(filaDePilha);

    liberarPilha(pilha1);
    liberarPilha(pilha2);
    liberarFilaDePilha(filaDePilha);

    return 0;
}

/*
    São criadas duas pilhas, passada 4 alunos para cada, e em seguida criado uma fila (exclusiva para pilhas),
    a qual a partir da função inserePilhaNaFila que tem como parametro a fila que irá receber e a
    pilha que será adicionada, adicione outras. Para que isso funcione, foi necessário criar um
    novo tipo de fila, a qual invés de receber as filas como anteriormente, a fila receba pilhas, 
    e essas pilhas, alunos.
    Assim, foi feito uma função que passa por dentro da fila de pilhas chamando uma função que imprime
    a pilha nas filas normais, assim verificando se foram os alunos realmente adicionados a pilha que foi 
    adicionado a fila principal.
    Concluindo, fizemos uma função liberarFilaDePilha que segue da mesma forma que a função dita
    anterior, a qual passa por dentro da fila de pilha chamando a função liberarPilha assim,
    liberando a memória, e em seguida finalizando o programa.
*/