#ifndef LISTA_C
#define LISTA_C

#include <stdio.h>
#include <stdlib.h>
#include "lista.h" 

struct elemento {
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elemento* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere in�cio
        *li = no;
    }else{
        Elemento *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento* no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){//lista vazia: insere in�cio
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elemento *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere in�cio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elemento *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)//n�o encontrado
        return 0;

    if(no == *li)//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li))//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elemento* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elemento* no = *li;
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

/////////////////////////////////////////////////////////
//// EXERCICIO 1 ////////////////////////////////////////
/////////////////////////////////////////////////////////


///////
// A //
///////
struct aluno* consultarAlunoMat(Lista* lista, int matricula) {
    if (lista == NULL) 
        return NULL;
    Elemento *no = *lista;
    while (no != NULL) {
        if (no->dados.matricula == matricula)
            return &no->dados;
        no = no->prox;
    }
    return NULL;
}

///////
// B //
///////
struct aluno* consultarAlunoPos(Lista* lista, int pos) {
    if (lista == NULL) 
        return NULL;
    Elemento *no = *lista;
    int posAux = 0;
    while (no != NULL) {
        if (posAux == pos)
            return &no->dados;
        no = no->prox;
        posAux++;
    }
    return NULL;
}

/////////////////////////////////////////////////////////
//// EXERCICIO 2 ////////////////////////////////////////
/////////////////////////////////////////////////////////

int removerNo(Lista* lista, int remover) {
    Elemento *no = *lista;
    if (no == NULL) 
        return 0;
    if (no->dados.matricula == remover) {
        *lista = no->prox;
        free(no);
        return 1;
    }   
    return removerNo(&(no->prox), remover);
}

int equals(Lista* lista1, Lista* lista2) {
    Elemento *no1 = *lista1;
    Elemento *no2 = *lista2;
    if (no1 == NULL || no2 == NULL)
        return 0;
    if (tamanho_lista(lista1) != tamanho_lista(lista2))  
        return 0;
    if (no1->dados.matricula == no2->dados.matricula)
        return 1;
    return equals(&(no1->prox), &(no2->prox));
}

/////////////////////////////////////////////////////////
//// EXERCICIO 4 ////////////////////////////////////////
/////////////////////////////////////////////////////////

typedef struct ElementoFloat {
    float valor;
    struct ElementoFloat* prox;
} ElementoFloat;

ListaFloat* criarListaFloat() {
    ListaFloat* listaFloat = (ListaFloat*) malloc(sizeof(ListaFloat));
    if (listaFloat != NULL)
        *listaFloat = NULL;
    return listaFloat;
}

int inserirFinalListaFloat(ListaFloat* lista, float valor) {
    if (lista == NULL)
        return 0;
    ElementoFloat *novoNo = (ElementoFloat*) malloc(sizeof(ElementoFloat));
    if (novoNo == NULL)
        return 0;
    novoNo->valor = valor;
    novoNo->prox = NULL;
    if ((*lista) == NULL) {
        *lista = novoNo;
    } else {
        ElementoFloat *no = *lista;
        while (no->prox != NULL) 
            no = no->prox;
        no->prox = novoNo;
    }
    return 1;
}

ListaFloat* vetorParaLista(float* vetor, int tamanho) {
    if (vetor == NULL || tamanho <= 0)
        return NULL;

    ListaFloat* lista = criarListaFloat();
    for (int i = 0; i < tamanho; i++) {
        inserirFinalListaFloat(lista, vetor[i]);
    }
    return lista;
}

void imprimirListaFloat(ListaFloat* lista) {
    if(lista == NULL)
        return;
    ElementoFloat* no = *lista;
    while(no != NULL){
        printf("-> %.2f\n", no->valor);
        no = no->prox;
    }
}

void liberarListaFloat(ListaFloat* lista) {
    if((*lista) != NULL){
        ElementoFloat* no;
        while((*lista) != NULL){
            no = *lista;
            *lista = (*lista)->prox;
            free(no);
        }
        free(lista);
    }
}

/////////////////////////////////////////////////////////
//// EXERCICIO 6 ////////////////////////////////////////
/////////////////////////////////////////////////////////

Lista* concatenar(Lista* lista1, Lista* lista2) {
    if (lista1 == NULL || lista2 == NULL)
        return 0;
    Lista* lista3 = cria_lista();
    for (int listas = 0; listas < 2; listas++) {
        Elemento *no;
        if (listas == 0) no = *lista1; else no = *lista2;
        while(no != NULL) {
            insere_lista_final(lista3, no->dados);
            no = no->prox;
        }
    }
    return lista3;
}

/////////////////////////////////////////////////////////
//// EXERCICIO 8 ////////////////////////////////////////
/////////////////////////////////////////////////////////

int ordenar (Lista* lista) {
    if (lista == NULL || *lista == NULL)
        return 0;
    int sair;
    Elemento *aux = (Elemento*) malloc(sizeof(Elemento));
    do {
        Elemento *no = *lista;
        sair = 1;
        while (no != NULL) {
            if (no->prox != NULL && no->dados.matricula > no->prox->dados.matricula) {
                aux->dados = no->dados;
                no->dados = no->prox->dados;
                no->prox->dados = aux->dados;
                sair = 0;
            }
            no = no->prox;
        }
    } while (sair == 0);
    return 1;
}

int fusaoOrdenada(Lista* lista1, Lista* lista2) {
    if (lista1 == NULL || lista2 == NULL)
        return 0;
    if (*lista1 == NULL) { 
        *lista1 = *lista2;
    } else {
        Elemento *no = *lista1;
        while (no->prox != NULL) 
            no = no->prox;
        no->prox = *lista2;
    }
    ordenar(lista1);
    return 1;
}

#endif