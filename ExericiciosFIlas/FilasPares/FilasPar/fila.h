#ifndef FILADIN_H
#define FILADIN_H

#include <stdio.h>
#include <stdlib.h>

#include "prototipos_fila.h" 
#include "pilha.h"

typedef struct elemento {
    struct aluno dados;
    struct elemento *prox;
} Elemento;
struct fila{
    Elemento *inicio;
    Elemento *final;
    int qtd;
};

// Exercício 2 a):
typedef struct elementoFila {
    struct fila *dados;
    struct elementoFila *prox;
} ElementoFila;
struct filaDeFila {
    ElementoFila *inicio;
    ElementoFila *final;
    int qtd;
};

// Exercício 2 b):
typedef struct elementoPilha {
    Pilha *dados;
    struct elementoPilha *prox;
} ElementoPilha;
struct filaDePilha {
    ElementoPilha *inicio;
    ElementoPilha *final;
    int qtd;
};

// Exercicio 4:
typedef struct elementoCircular {
    float valor;
    struct elementoCircular *prox;
} ElementoCircular;
struct filaCircular {
    ElementoCircular *inicio;
    ElementoCircular *final;
    int qtd;
};

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elemento* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elemento *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi){
    fi = fi;
    return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    Elemento* no = fi->inicio;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

////////////////////////////////////////////////////////
// EXERCICIO 1 /////////////////////////////////////////
////////////////////////////////////////////////////////

int separarFila(Fila* f1, Fila* f2, int matricula) {
    if (f1 == NULL || f2 == NULL || Fila_vazia(f1) || !Fila_vazia(f2)) return 0;
    if (f1->final->dados.matricula == matricula) return 0;
    Elemento *elem = f1->inicio;
    int count = 0;
    while (elem != NULL && elem->dados.matricula != matricula) {
        elem = elem->prox;
        count++;
    } 
    if (elem != NULL && elem->prox != NULL) {
        f2->inicio = elem->prox;
        f2->final = f1->final;
        f2->qtd = f1->qtd - count;
        f1->final = elem;
        f1->final->prox = NULL;
        f1->qtd = count;
    } else {
        return 0;
    }
    return 1;
}

////////////////////////////////////////////////////////
// EXERCICIO 2  ////////////////////////////////////////
////////////////////////////////////////////////////////

/////////////
///// A /////
/////////////

FilaDeFila* criarFilaDeFila() {
    FilaDeFila* fila = (FilaDeFila*) malloc(sizeof(FilaDeFila));
    if(fila != NULL){
        fila->final = NULL;
        fila->inicio = NULL;
        fila->qtd = 0;
    }
    return fila;
}

int inserirFilaNaFila(FilaDeFila* filaDeFila, Fila* fila) {
    if (filaDeFila == NULL || fila == NULL) return 0;
    ElementoFila *elemFila = (ElementoFila*) malloc(sizeof(ElementoFila));
    if (elemFila == NULL) return 0;
    elemFila->dados = fila;
    elemFila->prox = NULL;
    if (filaDeFila->final == NULL) {
        filaDeFila->inicio = elemFila;
    } else {
        filaDeFila->final->prox = elemFila;
    }
    filaDeFila->final = elemFila;
    filaDeFila->qtd++;
    return 1;
}

void imprimirFilaDeFila(FilaDeFila* filaDeFila) {
    if (filaDeFila == NULL) return;
    ElementoFila *elemFila = filaDeFila->inicio;
    while (elemFila != NULL) {
        printf("\nFila:\n");
        imprime_Fila(elemFila->dados);
        elemFila = elemFila->prox;
    }
}

void liberarFilaDeFila(FilaDeFila* filaDeFila) {
    if (filaDeFila == NULL) return;
    ElementoFila *elemFila = filaDeFila->inicio;
    while (elemFila != NULL) {
        ElementoFila *temp = elemFila;
        libera_Fila(elemFila->dados);
        elemFila = elemFila->prox;
        free(temp);
    }
    filaDeFila->inicio = NULL;
    filaDeFila->final = NULL;
    free(filaDeFila);
}

/////////////
///// B /////
/////////////

FilaDePilha* criarFilaDePilha() {
    FilaDePilha* fila = (FilaDePilha*) malloc(sizeof(FilaDePilha));
    if (fila != NULL){
        fila->final = NULL;
        fila->inicio = NULL;
        fila->qtd = 0;
    }
    return fila;
}

int inserirPilhaNaFila(FilaDePilha* filaDePilha, Pilha* pilha) {
    if (filaDePilha == NULL || pilha == NULL) return 0;
    ElementoPilha *elemPilha = (ElementoPilha*) malloc(sizeof(ElementoPilha));
    if (elemPilha == NULL) return 0;
    elemPilha->dados = pilha;
    elemPilha->prox = NULL;
    if (filaDePilha->final == NULL) {
        filaDePilha->inicio = elemPilha;
    } else {
        filaDePilha->final->prox = elemPilha;
    }
    filaDePilha->final = elemPilha;
    filaDePilha->qtd++;
    return 1;
}

void imprimirFilaDePilha(FilaDePilha* filaDePilha) {
    if (filaDePilha == NULL) return;
    ElementoPilha *elemPilha = filaDePilha->inicio;
    while (elemPilha != NULL) {
        printf("\nPilha:\n");
        imprimirPilha(elemPilha->dados);
        elemPilha = elemPilha->prox;
    }
}

void liberarFilaDePilha(FilaDePilha* filaDePilha) {
    if (filaDePilha == NULL) return;
    ElementoPilha *elemPilha = filaDePilha->inicio;
    while (elemPilha != NULL) {
        ElementoPilha *temp = elemPilha;
        liberarPilha(elemPilha->dados);
        elemPilha = elemPilha->prox;
        free(temp);
    }
    filaDePilha->inicio = NULL;
    filaDePilha->final = NULL;
    free(filaDePilha);
}

////////////////////////////////////////////////////////
// EXERCICIO 4  ////////////////////////////////////////
////////////////////////////////////////////////////////

FilaCircular* criarFilaCircular() {
    FilaCircular* filaCircular = (FilaCircular*) malloc(sizeof(FilaCircular));
    if (filaCircular != NULL) {
        filaCircular->final = NULL;
        filaCircular->inicio = NULL;
        filaCircular->qtd = 0;
    }
    return filaCircular;
}

void liberarFilaCircular(FilaCircular* filaCircular) {
    if (filaCircular != NULL) {
        ElementoCircular* elementoCircular = filaCircular->inicio;
        for (int i = 0; i < filaCircular->qtd; i++) {
            ElementoCircular *aux = elementoCircular;
            elementoCircular = elementoCircular->prox;
            free(aux);
        }
        free(filaCircular);
    }
}

int inserirFilaCircular(FilaCircular* filaCircular, float valor) {
    if(filaCircular == NULL) return 0;
    ElementoCircular *no = (ElementoCircular*) malloc(sizeof(ElementoCircular));
    if(no == NULL) return 0;
    no->valor = valor;
    no->prox = NULL;
    if (filaCircular->final == NULL) {
        filaCircular->inicio = no;
    } else {
        filaCircular->final->prox = no;
    }
    filaCircular->final = no;
    filaCircular->final->prox = filaCircular->inicio;
    filaCircular->qtd++;
    return 1;
}

void imprimirFilaCircular(FilaCircular* filaCircular) {
    if (filaCircular == NULL) return;
    ElementoCircular* elementoCircular = filaCircular->inicio;
    printf("\nFila Circular:\n");
    for (int i = 0; i < filaCircular->qtd; i++, elementoCircular = elementoCircular->prox) {
        printf("-> %.2f\n", elementoCircular->valor);
    }
}

int furarFilaCircular(FilaCircular* filaCircular, float valor) {
    if (filaCircular == NULL ) return 0;
    if (filaCircular->inicio == NULL) return inserirFilaCircular(filaCircular, valor);
    ElementoCircular *elementoCircular = (ElementoCircular*) malloc(sizeof(ElementoCircular));
    if (elementoCircular == NULL) return 0; 
    elementoCircular->valor = valor;
    elementoCircular->prox = filaCircular->inicio;
    filaCircular->inicio = elementoCircular;
    filaCircular->final->prox = filaCircular->inicio;
    filaCircular->qtd++;
    return 1;
}

////////////////////////////////////////////////////////
// EXERCICIO 6  ////////////////////////////////////////
////////////////////////////////////////////////////////

int ordenarFila(Fila *fila) {
    if (fila == NULL || fila->inicio == NULL || fila->qtd < 2) return 0;
    int sair;
    do {
        sair = 0;
        Elemento *elemento = fila->inicio;
        while (elemento->prox != NULL) {
            if (elemento->dados.matricula > elemento->prox->dados.matricula) {
                struct aluno aux = elemento->dados;
                elemento->dados = elemento->prox->dados;
                elemento->prox->dados = aux;
                sair = 1;
            }
            elemento = elemento->prox;
        }
    } while (sair != 0);
    return 1;
}

int ordenarPreencherFila(Fila* fila1, Fila* fila2, Fila* fila3) {
    if (fila1 == NULL || fila2 == NULL || fila3 == NULL) return 0;
    Elemento *elemento1 = fila1->inicio;
    Elemento *elemento2 = fila2->inicio;
    while (elemento1 != NULL || elemento2 != NULL) {
        if (elemento1 != NULL) {
            insere_Fila(fila3, elemento1->dados);
            elemento1 = elemento1->prox;
        }
        if (elemento2 != NULL) {
            insere_Fila(fila3, elemento2->dados);
            elemento2 = elemento2->prox;
        }
    }
    if(!ordenarFila(fila3)) return 0;
    return 1;
}

////////////////////////////////////////////////////////
// EXERCICIO 8  ////////////////////////////////////////
////////////////////////////////////////////////////////

int removerFilaCircular(FilaCircular* filaCircular){
    if (filaCircular == NULL || filaCircular->inicio == NULL) return 0;
    ElementoCircular *elementoCircular = filaCircular->inicio;
    filaCircular->inicio = filaCircular->inicio->prox;
    if (filaCircular->inicio == NULL) filaCircular->final = NULL;
    free(elementoCircular);
    filaCircular->qtd--;
    return 1;
}

int consultarFilaCircular(FilaCircular* filaCircular, float* valor){
    if(filaCircular == NULL) return 0;
    if(filaCircular->inicio == NULL) return 0;
    *valor = filaCircular->inicio->valor;
    return 1;
}

#endif