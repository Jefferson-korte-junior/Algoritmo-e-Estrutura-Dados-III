#ifndef PROTOTIPOS_PILHA_H
#define PROTOTIPOS_PILHA_H

#include "FilaDinPrototipos.h" 

typedef struct Celula {
    struct aluno valor; 
    struct Celula* proxCelula;
} Celula;


typedef struct {
    Celula* celulaTopo;
} Pilha;

Pilha* criarPilha();
int pop(Pilha* pilha, struct aluno* elemento);
int push(Pilha* pilha, struct aluno elemento);
int consulta_Pilha(Pilha* pilha, struct aluno* elemento);
int size(Pilha* pilha);
int clear(Pilha* pilha);
int print(Pilha* pilha);

#endif