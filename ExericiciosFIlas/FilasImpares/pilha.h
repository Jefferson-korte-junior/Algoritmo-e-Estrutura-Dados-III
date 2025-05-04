#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include "prototipos_pilha.h"

#define A 65
#define B 66

#include <stdio.h>
#include <stdlib.h>

/*
    Cria uma pilha
*/

Pilha* criarPilha() {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    if (pilha == NULL) return NULL; 
    pilha->celulaTopo = NULL;
    return pilha;
}


/*
    Remove o elemento do topo da pilha e armazena o valor retirado.
*/

/*
int pop(Pilha *pilha, int *valor) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->celulaTopo;
    if (celula == NULL) return 0;
    *valor = pilha->celulaTopo->valor;
    pilha->celulaTopo = celula->proxCelula;
    free(celula);
    return 1;
}
*/

/*
    Adiciona um novo elemento ao topo da pilha.
*/

/*
int push(Pilha *pilha, int valor) {
    if (pilha == NULL) return 0;
    Celula *celula = (Celula *)malloc(sizeof(Celula));
    if (celula == NULL) return 0;
    celula->valor = valor;
    celula->proxCelula = pilha->celulaTopo;
    pilha->celulaTopo = celula;
    return 1;
}
*/


/*
    Retorna o número de elementos na pilha.
*/
/*
int size(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->celulaTopo;
    int size = 0;
    while (celula != NULL) {
        size++;
        celula = celula->proxCelula;
    }
    return size;
}
*/

/*
    Libera toda a memória alocada para a pilha
*/


int clear(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->celulaTopo;
    while(celula != NULL) {
        Celula *aux = celula;
        celula = celula->proxCelula;
        free(aux);
    }
    pilha->celulaTopo = NULL;
    return 1;
}

/*
    Imprime todos os elementos da pilha do topo para a base.
*/
/*
int print(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->celulaTopo;
    while (celula != NULL) {
        printf("-> %d\n", celula->valor);
        celula = celula->proxCelula;
    }
    return 1;
}
*/


//Retorna 1 se a pilha estiver vazia ou inválida, 0 caso contrário.


int vazia(Pilha *pilha) {
    if (pilha == NULL) return 1;
    if (pilha->celulaTopo == NULL) return 1;
    return 0; 
}


//Libera toda a memória da pilha e define o topo como NULL.

/*
int destroy(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->celulaTopo;
    while(celula != NULL) {
        Celula *aux = celula;
        celula = celula->proxCelula;
        free(aux);
    }
    pilha->celulaTopo = NULL;
    return 1;
}
*/


//////////////////////////////////////////////////////////////////////
//Exericico 3/////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

int consulta_Pilha(Pilha *pilha, struct aluno *elemento) {
    if (pilha == NULL || pilha->celulaTopo == NULL) return 0; // Pilha vazia ou inexistente
    *elemento = pilha->celulaTopo->valor; // Obtém o struct aluno no topo
    return 1; // Sucesso
}


int pushEx3(Pilha *pilha, struct aluno elemento) {
    if (pilha == NULL) return 0;
    Celula *celula = (Celula *)malloc(sizeof(Celula));
    if (celula == NULL) return 0;
    celula->valor = elemento; // Armazena o struct aluno
    celula->proxCelula = pilha->celulaTopo;
    pilha->celulaTopo = celula;
    return 1;
}

int popEx3(Pilha *pilha, struct aluno *elemento) {
    if (pilha == NULL || pilha->celulaTopo == NULL) return 0;
    Celula *celula = pilha->celulaTopo;
    *elemento = celula->valor; // Retorna o struct aluno
    pilha->celulaTopo = celula->proxCelula;
    free(celula);
    return 1;
}

int printEx3(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->celulaTopo;
    while (celula != NULL) {
        printf("Matricula: %d, Nome: %s, Notas: %.2f, %.2f, %.2f\n",
               celula->valor.matricula,
               celula->valor.nome,
               celula->valor.n1,
               celula->valor.n2,
               celula->valor.n3);
        celula = celula->proxCelula;
    }
    return 1;
}





#endif