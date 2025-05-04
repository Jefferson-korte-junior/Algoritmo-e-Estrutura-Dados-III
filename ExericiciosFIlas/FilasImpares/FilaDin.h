#ifndef FILA_DIN_H
#define FILA_DIN_H

#include <stdio.h>
#include <stdlib.h>
#include "FilaDinPrototipos.h"
#include "pilha.h"

//Defini��o do tipo Fila

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;
//Defini��o do N� Descritor da Fila
struct fila{
    struct elemento *inicio;
    struct elemento *final;
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
        Elem* no;
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
    Elem *no = (Elem*) malloc(sizeof(Elem));
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
    Elem *no = fi->inicio;
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
    return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
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

//----------------------------------------------------------------
//----------------------------------------------------------------
//EXERCICIO 1:
//----------------------------------------------------------------
int separar (Fila* fi1, Fila* fi2, int matricula) {
    if (Fila_vazia(fi1)) {
        return 0;
    }

    Elem* no = fi1->inicio;

    while (no != NULL && no->dados.matricula != matricula){
        no = no->prox;
        if (no->dados.matricula == matricula){
            fi2->final = fi1->final;
            fi2->inicio = no->prox;
            fi2->qtd = tamanho_Fila(fi2);
            break;
        }

    }

    fi1->final = no;
    fi1->final->prox = NULL;


    return 1;
}

//----------------------------------------------------------------
//----------------------------------------------------------------
//EXERCICIO 2:
//----------------------------------------------------------------

struct elementoFila {
    Fila* dados;
    struct elementoFila *prox;
};

typedef struct elementoFila ElemFila;

struct FilaPrincipal {
    elementoFila* inicio;
    elementoFila* final;
    int qtd;
};



FilaPrincipal* criaFilaDeFila(){
    FilaPrincipal* fi = (FilaPrincipal*) malloc(sizeof(FilaPrincipal));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

int insereFilaNaFila (FilaPrincipal* filaPrincipal, Fila* fila){
    if(filaPrincipal == NULL)
        return 0;
    if (fila == NULL){
        return 0;
    }
    ElemFila *no = (ElemFila*) malloc(sizeof(ElemFila));
    if(no == NULL)
        return 0;
    no->dados = fila;
    no->prox = NULL;
    if(filaPrincipal->final == NULL){//fila vazia
        filaPrincipal->inicio = no;
    } else {
        filaPrincipal->final->prox = no;
    }

    filaPrincipal->final = no;
    filaPrincipal->qtd++;
    return 1;
}



//----------------------------------------------------------------
//----------------------------------------------------------------
//EXERCICIO 3:
//----------------------------------------------------------------

void inverte_Fila(Fila* fila) {
    if (fila == NULL || Fila_vazia(fila)) {
        return; // Fila vazia ou inexistente
    }

    Pilha* pilha = criarPilha(); // Cria uma pilha vazia
    if (pilha == NULL) {
        printf("Erro ao criar a pilha.\n");
        return;
    }

    // Passo 1: Desenfileira os elementos da fila e empilha na pilha
    while (!Fila_vazia(fila)) {
        struct aluno aux;
        consulta_Fila(fila, &aux); // Consulta o elemento no início da fila
        remove_Fila(fila);        // Remove o elemento da fila
        pushEx3(pilha, aux); // Empilha o elemento na pilha
    }

    // Passo 2: Desempilha os elementos da pilha e enfileira de volta na fila
    while (!vazia(pilha)) {
        struct aluno aux;
        consulta_Pilha(pilha, &aux); // Consulta o elemento no topo da pilha
        popEx3(pilha, &aux);     // Remove o elemento da pilha
        insere_Fila(fila, aux);      // Enfileira o elemento de volta na fila
    }

    imprime_Fila(fila);

    clear(pilha); // Libera a memória da pilha
}



//----------------------------------------------------------------
//----------------------------------------------------------------
//EXERCICIO 5:
//----------------------------------------------------------------
// Definição do tipo elemento para aviões
struct elementoAviao {
    struct aviao dados; // Dados do avião
    struct elementoAviao *prox; // Ponteiro para o próximo elemento
};

typedef struct elementoAviao ElemAviao;

// Definição do nó descritor da fila para aviões
struct filaAviao {
    struct elementoAviao *inicio;
    struct elementoAviao *final;
    int qtd;
};

typedef struct filaAviao FilaAviao;

// Função para criar uma fila de aviões
FilaAviao* cria_FilaAviao() {
    FilaAviao* fi = (FilaAviao*) malloc(sizeof(FilaAviao));
    if (fi != NULL) {
        fi->inicio = NULL;
        fi->final = NULL;
        fi->qtd = 0;
    }
    return fi;
}

// Função para liberar a fila de aviões
void libera_FilaAviao(FilaAviao* fi) {
    if (fi != NULL) {
        ElemAviao* no;
        while (fi->inicio != NULL) {
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

// Função para inserir um avião na fila
int insere_FilaAviao(FilaAviao* fi, struct aviao av) {
    if (fi == NULL)
        return 0;
    ElemAviao* no = (ElemAviao*) malloc(sizeof(ElemAviao));
    if (no == NULL)
        return 0;
    no->dados = av;
    no->prox = NULL;
    if (fi->final == NULL) // Fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

// Função para remover um avião da fila
int remove_FilaAviao(FilaAviao* fi) {
    if (fi == NULL || fi->inicio == NULL) // Fila vazia
        return 0;
    ElemAviao* no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if (fi->inicio == NULL) // Fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

// Função para imprimir a fila de aviões
void imprime_FilaAviao(FilaAviao* fi) {
    if (fi == NULL)
        return;
    ElemAviao* no = fi->inicio;
    while (no != NULL) {
        printf("ID: %d\n", no->dados.id);
        printf("Tamanho: %s\n", no->dados.tamanho);
        printf("Modelo: %s\n", no->dados.modelo);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

// Função para contar o número de aviões na fila
int contar_Avioes(FilaAviao* fi) {
    if (fi == NULL)
        return 0;
    return fi->qtd;
}




//----------------------------------------------------------------
//----------------------------------------------------------------
//EXERCICIO 7:
//----------------------------------------------------------------

int inverso (Fila* fila){
    if (Fila_vazia(fila) || tamanho_Fila(fila) == 1) {
        return 1; 
    }

    Elem *noAtual = fila->inicio;
    Elem *noAnterior = NULL;
    Elem *noProximo = NULL;

    while (noAtual != NULL){ 
        noProximo = noAtual->prox; 
        noAtual->prox = noAnterior; 
        noAnterior = noAtual; 
        noAtual = noProximo;  
    }
    
    fila->final = fila->inicio;
    fila->inicio = noAnterior;

}




#endif


