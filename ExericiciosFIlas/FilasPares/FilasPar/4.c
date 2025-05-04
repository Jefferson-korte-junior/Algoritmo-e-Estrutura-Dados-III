// FEITO EM DUPLA POR: BRUNO E. S. ALCANTARA, RA: 2677156 & JEFFERSON K. JUNIOR, RA: 2651114.

#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"
#include "fila.h"

int main() {

    float valores[] = {1, 2, 3, 4};
    float valor = 5;

    FilaCircular *filaCircular = criarFilaCircular();
    for (int i = 0; i < 4; i++) {
        inserirFilaCircular(filaCircular, valores[i]);
    }

    imprimirFilaCircular(filaCircular);

    furarFilaCircular(filaCircular, valor);

    imprimirFilaCircular(filaCircular);

    liberarFilaCircular(filaCircular);

    return 0;
}

/*
    Crio uma fila circular, adiciono 4 valores a ela com uma nova função de inserção, a qual possui
    uma mudança que após a inserção é atualizado a conexão entre o inicio e o final da fila(por isso circular)
    no caso, o fila->final->prox aponta para o fila-inicio, assim juntando-se os dois pontos extremos.
    Para printar, também há uma nova função a qual se aproveita da qtd da fila usando um for, assim
    passando por todos os elementos evitando loop.
    Na função furar, simplesmente aloco memoria para um novo elemento, passo seu valor, aponto seu proximo
    para o inicio da fila, atualizo o inicio da fila apontando para esse novo elemento, e atualizo também
    o fila->final->prox para o inicio.
    E ao final libero a memoria com uma nova função de liberar também, bem parecida com a de printar, a qual
    utiliza um for, se aproveitando da qtd da fila também para evitar loop.
*/