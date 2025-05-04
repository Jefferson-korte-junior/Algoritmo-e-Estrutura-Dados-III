#ifndef FILADIN_PROTOTIPOS_H
#define FILADIN_PROTOTIPOS_H

// #include "pilha.h"
#include "aluno.h"

typedef struct fila Fila;
typedef struct filaDeFila FilaDeFila;
typedef struct filaDePilha FilaDePilha;
typedef struct filaCircular FilaCircular;
typedef struct pilha Pilha;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct aluno *al);
int insere_Fila(Fila* fi, struct aluno al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);

// Exercicio 1:
int separarFila(Fila* fila1, Fila* fila2, int matricula);

// Exercicio 2 a):
FilaDeFila* criarFilaDeFila();
int inserirFilaNaFila(FilaDeFila* filaPrincipal, Fila* fila);
void imprimirFilaDeFila(FilaDeFila* fila);
void liberarFilaDeFila(FilaDeFila* fila);

// Exercicio 2 b):
FilaDePilha* criarFilaDePilha();
int inserirPilhaNaFila(FilaDePilha* filaDePilha, Pilha* pilha);
void imprimirFilaDePilha(FilaDePilha* filaDePilha);
void liberarFilaDePilha(FilaDePilha* filaDePilha);

// Exercicio 4:
FilaCircular* criarFilaCircular();
void liberarFilaCircular(FilaCircular* filaCircular);
int inserirFilaCircular(FilaCircular* filaCircular, float valor);
void imprimirFilaCircular(FilaCircular* filaCircular);
int furarFilaCircular(FilaCircular* filaCircular, float valor);

// Exercicio 6:
int ordenarFila(Fila* fila);
int ordenarPreencherFila(Fila* fila1, Fila* fila2, Fila* fila3);

#endif
