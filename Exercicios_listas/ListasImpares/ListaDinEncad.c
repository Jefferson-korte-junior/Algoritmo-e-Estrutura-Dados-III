#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui os Prot�tipos

//Defini��o do tipo lista
struct elemento{
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

int lista_cheia(Lista* li){
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

///////////////////////////////////////////////////
////EXERCICIO 1
///////////////////////////////////////////////////
int consultaLista(Lista* li, int mat){
    Elemento* no = *li;
    while(no != NULL){
        if(no->dados.matricula == mat){
            printf("Matricula: %d\n",no->dados.matricula);
            printf("Nome: %s\n",no->dados.nome);
            printf("Notas: %f %f %f\n",no->dados.n1,
                                       no->dados.n2,
                                       no->dados.n3);
            return 1;
        }else {
            no = no->prox;
        }
    }   
}



///////////////////////////////////////////////////
////EXERCICIO 3
///////////////////////////////////////////////////
int insereQualQuerLugar(Lista *li, struct aluno al, int posicao) {
    if (li == NULL)
        return 0;

    Elemento *no = (Elemento*)malloc(sizeof(Elemento));
    if (no == NULL) //Falha ao alocar memória
        return 0;

    no->dados = al;

    if (posicao == 0) { // Caso a posição seja 0, insere no inicio 
        no->prox = (*li);
        *li = no;
        return 1;
    }

    Elemento *ant = NULL, *atual = *li;
    int con = 0;

    while (atual != NULL && con < posicao) {
        ant = atual;
        atual = atual->prox;
        con++;
    }

    if (con != posicao) { // verifica se a posição é realmente valida
        free(no);
        return 0;
    }

    if (ant != NULL) { // Se por um acaso o ANT == NULL quer dizer que vamos inserir no começo da lista
        ant-> prox = no;
    }

    no->prox = atual;

    return 1;

}



///////////////////////////////////////////////////
////EXERCICIO 5
///////////////////////////////////////////////////
int removeMatIgual(Lista* li, int numero){
    int removidos = 0;
    
    if (li == NULL){
        return 0;
    }

    if ((*li) == NULL) {
        return 0;
    }

    Elemento* ant = NULL, *atual = *li;

    while (atual != NULL) {
        if (atual->dados.matricula == numero){
            if (ant == NULL) {
                *li = atual->prox;
            } else {
                ant->prox = atual->prox;
            }
            Elemento* temp = atual;
            atual = atual->prox;
            free(temp);
            removidos++;
        } else {
            ant = atual;
            atual = atual->prox;
        }
    
    }
    return removidos;
}


#include <string.h>
///////////////////////////////////////////////////
////EXERCICIO 7
///////////////////////////////////////////////////
int removeRepetidos(Lista *li, struct aluno al, char nome[15]) {
    if (li == NULL || *li == NULL) {
        return 0;
    }

    Elemento *ant = NULL, *atual = *li;
    int removidos = 0;

    while (atual != NULL) {
        if (strcmp(atual->dados.nome,  nome) == 0) {
            if (ant == NULL) { 
                *li = atual->prox;
            } else {
                ant->prox = atual->prox;
            }
            Elemento *temp = atual;
            atual = atual->prox;
            free(temp);
            removidos++;
        } else {
            ant = atual;
            atual = atual->prox;
        }
    }

    return removidos;
}




///////////////////////////////////////////////////
////EXERCICIO 9
///////////////////////////////////////////////////

int Troca(Lista *li, Elemento *p) {
    if (li == NULL || *li == NULL) {
        return 0;
    }

    Elemento *ant = NULL, *seguinte = p->prox;

    if (*li != p) {
        ant = *li;
        while (ant->prox != p) {
            ant = ant->prox;
        }
    }

    p->prox = seguinte->prox;
    seguinte->prox = p;

    if (ant != NULL) {
        ant->prox = seguinte; 
    } else {
        *li = seguinte; 
    }

    return 1; 
}




