#ifndef PROTOTIPOS_PILHA_H
#define PROTOTIPOS_PILHA_H

/*
    Struct da celula:
*/
typedef struct Celula {
    int valor;
    struct Celula *proxCelula;
} Celula;

/*
    Struct da pilha:
*/
typedef struct {
    Celula *celulaTopo;
} Pilha;

Pilha* criarPilha();
int pop(Pilha *pilha, int *valor);
int push(Pilha *pilha, int valor);
int size(Pilha *pilha);
int clear(Pilha *pilha);
int print(Pilha *pilha);
int vazia(Pilha *pilha);

#endif