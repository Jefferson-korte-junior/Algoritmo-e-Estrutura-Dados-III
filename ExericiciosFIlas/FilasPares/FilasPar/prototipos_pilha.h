#ifndef PROTOTIPOS_PILHA_H
#define PROTOTIPOS_PILHA_H

#include "aluno.h"

typedef struct pilha Pilha;
typedef struct pilhaDeFila PilhaDeFila;
typedef struct fila Fila;

Pilha* criarPilha();
int retirarPilha(Pilha *pilha, struct aluno *Aluno);
int inserirPilha(Pilha *pilha, struct aluno aluno);
int tamanhoPilha(Pilha *pilha);
int liberarPilha(Pilha *pilha);
int imprimirPilha(Pilha *pilha);
int pilhaVazia(Pilha *pilha);

// Exercicio 2 c):
PilhaDeFila* criarPilhaDeFila();
int inserirFilaNaPilha(PilhaDeFila* pilhaDeFila, Fila* fila);
void imprimirPilhaDeFila(PilhaDeFila* pilhaDeFila);
void liberarPilhaDeFila(PilhaDeFila* pilhaDeFila); 

#endif