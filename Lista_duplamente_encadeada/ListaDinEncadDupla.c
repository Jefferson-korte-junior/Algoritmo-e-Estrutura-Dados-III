#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h" //inclui os Prot�tipos

//Defini��o do tipo lista
struct elemento{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere in�cio
        no->ant = NULL;
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    no->ant = NULL;
    if(*li != NULL)//lista n�o vazia: apontar para o anterior!
        (*li)->ant = no;
    *li = no;
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    *li = no->prox;
    if(no->prox != NULL)
        no->prox->ant = NULL;

    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    while(no->prox != NULL)
        no = no->prox;

    if(no->ant == NULL)//remover o primeiro e �nico
        *li = no->prox;
    else
        no->ant->prox = NULL;

    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
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
    Elem* no = *li;
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

///////////////////////////////////////////////////////////////////////
///////////EXERCICIO 2/////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL; //No thiago noa tem isso aqui
    no->ant = NULL; //Thiago nao tem 

    if((*li) == NULL){//lista vazia: insere in�cio
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere in�cio
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = *li;
            *li = no;
        }else{
            no->prox = ant->prox;
            no->ant = ant;
            ant->prox = no;
            if(atual != NULL)
                atual->ant = no;
        }
        return 1;
    }
}

///////////////////////////////////////////////////////////////////////
///////////EXERCICIO 4/////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int insere_lista_inicio_circular(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if(*li == NULL){
        no->prox = no;
        no->ant = no;
        *li = no;
    }else{
        Elem* ultimo = (*li)->ant;
        no->prox = *li;
        no->ant = ultimo;
        ultimo->prox = no;
        (*li)->ant = no;
        *li = no;
    }
    return 1;
}

int insere_lista_final_circular(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if(*li == NULL){
        no->prox = no;
        no->ant = no;
        *li = no;
    }else{
        Elem* ultimo = (*li)->ant;
        no->prox = *li;
        no->ant = ultimo;
        ultimo->prox = no;
        (*li)->ant = no;
    }
    return 1;
}

int remove_lista_inicio_circular(Lista* li){
    if(li == NULL || *li == NULL)
        return 0;
    Elem* no = *li;
    if(no->prox == no){ // só um elemento
        free(no);
        *li = NULL;
    }else{
        Elem* ultimo = no->ant;
        *li = no->prox;
        ultimo->prox = *li;
        (*li)->ant = ultimo;
        free(no);
    }
    return 1;
}

int remove_lista_final_circular(Lista* li){
    if(li == NULL || *li == NULL)
        return 0;
    Elem* ultimo = (*li)->ant;
    if(ultimo->prox == ultimo){ // só um elemento
        free(ultimo);
        *li = NULL;
    }else{
        Elem* penultimo = ultimo->ant;
        penultimo->prox = *li;
        (*li)->ant = penultimo;
        free(ultimo);
    }
    return 1;
}

void imprime_lista_circular(Lista* li){
    if(li == NULL || *li == NULL)
        return;
    Elem* no = *li;
    do {
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: %f %f %f\n", no->dados.n1, no->dados.n2, no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    } while(no != *li);
}