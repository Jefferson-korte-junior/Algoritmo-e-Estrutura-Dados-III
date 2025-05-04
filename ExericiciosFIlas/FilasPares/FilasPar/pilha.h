#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

#include "prototipos_pilha.h"
#include "fila.h"
#include "aluno.h"

typedef struct Celula {
    struct aluno aluno;
    struct Celula *prox;
} Celula;
struct pilha {
    Celula *topo;
};

typedef struct CelulaFila {
    Fila *fila;
    struct CelulaFila *prox;
} CelulaFila;
struct pilhaDeFila {
    CelulaFila *topo;
};

Pilha* criarPilha() {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    if (pilha == NULL) return NULL; 
    pilha->topo = NULL;
    return pilha;
}

int retirarPilha(Pilha *pilha, struct aluno *aluno) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->topo;
    if (celula == NULL) return 0;
    *aluno = pilha->topo->aluno;
    pilha->topo = celula->prox;
    free(celula);
    return 1;
}

int inserirPilha(Pilha *pilha, struct aluno aluno) {
    if (pilha == NULL) return 0;
    Celula *celula = (Celula *)malloc(sizeof(Celula));
    if (celula == NULL) return 0;
    celula->aluno = aluno;
    celula->prox = pilha->topo;
    pilha->topo = celula;
    return 1;
}

int tamanhoPilha(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->topo;
    int size = 0;
    while (celula != NULL) {
        size++;
        celula = celula->prox;
    }
    return size;
}

int liberarPilha(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->topo;
    while(celula != NULL) {
        Celula *aux = celula;
        celula = celula->prox;
        free(aux);
    }
    pilha->topo = NULL;
    return 1;
}

int imprimirPilha(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->topo;
    while (celula != NULL) {
        printf("Matricula: %d\n", celula->aluno.matricula);
        printf("Nome: %s\n",celula->aluno.nome);
        printf("Notas: %f %f %f\n", celula->aluno.n1, celula->aluno.n2, celula->aluno.n3);
        printf("-------------------------------\n");
        celula = celula->prox;
    }
    return 1;
}

int pilhaVazia(Pilha *pilha) {
    if (pilha == NULL) return 1;
    if (pilha->topo == NULL) return 1;
    return 0;
}

////////////////////////////////////////////////////////
// EXERCICIO 2  ////////////////////////////////////////
////////////////////////////////////////////////////////

/////////////
///// C /////
/////////////

PilhaDeFila* criarPilhaDeFila() {
    PilhaDeFila *pilhaDeFila = (PilhaDeFila *)malloc(sizeof(PilhaDeFila));
    if (pilhaDeFila == NULL) return NULL; 
    pilhaDeFila->topo = NULL;
    return pilhaDeFila;
}

int inserirFilaNaPilha(PilhaDeFila* pilhaDeFila, Fila* fila) {
    if (pilhaDeFila == NULL || fila == NULL) return 0;
    CelulaFila *celulaFila = (CelulaFila *)malloc(sizeof(CelulaFila));
    if (celulaFila == NULL) return 0;
    celulaFila->fila = fila;
    celulaFila->prox = pilhaDeFila->topo;
    pilhaDeFila->topo = celulaFila;
    return 1;
}

void imprimirPilhaDeFila(PilhaDeFila* pilhaDeFila) {
    if (pilhaDeFila == NULL) return;
    CelulaFila *celulaFila = pilhaDeFila->topo;
    while (celulaFila != NULL) {
        printf("\nFila:\n");
        imprime_Fila(celulaFila->fila);
        celulaFila = celulaFila->prox;
    }
}

void liberarPilhaDeFila(PilhaDeFila* pilhaDeFila) {
    if (pilhaDeFila == NULL) return;
    CelulaFila *celulaFila = pilhaDeFila->topo;
    while (celulaFila != NULL) {
        CelulaFila *aux = celulaFila;
        celulaFila = celulaFila->prox;
        free(aux);
    }
    pilhaDeFila->topo = NULL;
}

#endif