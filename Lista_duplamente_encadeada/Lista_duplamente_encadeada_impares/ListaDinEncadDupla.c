#include <stdio.h>
#include <stdlib.h>

#include "ListaDinEncadDupla.h" //inclui os Prot�tipos

// Defini��o do tipo lista
struct elemento
{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista *cria_lista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista *li)
{
    if (li != NULL)
    {
        Elem *no;
        while ((*li) != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int consulta_lista_pos(Lista *li, int pos, struct aluno *al)
{
    if (li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while (no != NULL && i < pos)
    {
        no = no->prox;
        i++;
    }
    if (no == NULL)
        return 0;
    else
    {
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_mat(Lista *li, int mat, struct aluno *al)
{
    if (li == NULL)
        return 0;
    Elem *no = *li;
    while (no != NULL && no->dados.matricula != mat)
    {
        no = no->prox;
    }
    if (no == NULL)
        return 0;
    else
    {
        *al = no->dados;
        return 1;
    }
}

int insere_lista_final(Lista *li, struct aluno al)
{
    if (li == NULL)
        return 0;
    Elem *no;
    no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if ((*li) == NULL)
    { // lista vazia: insere in�cio
        no->ant = NULL;
        *li = no;
    }
    else
    {
        Elem *aux;
        aux = *li;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int insere_lista_inicio(Lista *li, struct aluno al)
{
    if (li == NULL)
        return 0;
    Elem *no;
    no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    no->ant = NULL;
    if (*li != NULL) // lista n�o vazia: apontar para o anterior!
        (*li)->ant = no;
    *li = no;
    return 1;
}

int remove_lista_inicio(Lista *li)
{
    if (li == NULL)
        return 0;
    if ((*li) == NULL) // lista vazia
        return 0;

    Elem *no = *li;
    *li = no->prox;
    if (no->prox != NULL)
        no->prox->ant = NULL;

    free(no);
    return 1;
}

int remove_lista_final(Lista *li)
{
    if (li == NULL)
        return 0;
    if ((*li) == NULL) // lista vazia
        return 0;

    Elem *no = *li;
    while (no->prox != NULL)
        no = no->prox;

    if (no->ant == NULL) // remover o primeiro e �nico
        *li = no->prox;
    else
        no->ant->prox = NULL;

    free(no);
    return 1;
}

int tamanho_lista(Lista *li)
{
    if (li == NULL)
        return 0;
    int cont = 0;
    Elem *no = *li;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia()
{
    return 0;
}

int lista_vazia(Lista *li)
{
    if (li == NULL)
        return 1;
    if (*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista *li)
{
    if (li == NULL)
        return;
    Elem *no = *li;
    while (no != NULL)
    {
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: %f %f %f\n", no->dados.n1,
               no->dados.n2,
               no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

///////////////////////////////////////////////////
// Exercicio 1 ////////////////////////////////////
///////////////////////////////////////////////////

int removerPorMatricula(Lista *lista, int matricula)
{
    if (lista == NULL || (*lista) == NULL)
        return 0;
    Elem *no = *lista;
    while (no != NULL && no->dados.matricula != matricula)
    {
        no = no->prox;
    }
    if (no == NULL)
        return 0;
    if (no->ant == NULL)
    {
        *lista = no->prox;
        if (no->prox != NULL)
            no->prox->ant = NULL;
    }
    else
    {
        no->ant->prox = no->prox;
        if (no->prox != NULL)
            no->prox->ant = no->ant;
    }
    free(no);
    return 1;
}

///////////////////////////////////////////////////
// Exercicio 3 ////////////////////////////////////
///////////////////////////////////////////////////
int conta_lista_nota(Lista *lista, int n1)
{
    if (lista == NULL || (*lista) == NULL)
        return 0;
    Elem *no = *lista;
    int counter = 0;
    while (no != NULL)
    {
        if (no->dados.n1 == n1)
            counter++;
        no = no->prox;
    }
    return counter;
}

///////////////////////////////////////////////////
// Exercicio 3 ////////////////////////////////////
///////////////////////////////////////////////////

struct fila {
    int info;
    struct fila *prox;
    struct fila *ant;
};

struct nodesc {
    struct fila *ini;
    struct fila *fim;
};

int inicializa_noDesc(noDesc *no) {
    *no = (noDesc)malloc(sizeof(struct nodesc));
    // coloca a fila no estado de vazia
    if (!(*no)) {
        return 0;
    } else {
        (*no)->ini = NULL;
        (*no)->fim = NULL;
        return 1;
    }
}

int enfileirar(noDesc *n, int elem) {
    if (n == NULL || *n == NULL)
        return 0;

    struct fila *novo = (struct fila*)malloc(sizeof(struct fila));
    if (novo == NULL)
        return 0;

    novo->info = elem;
    novo->prox = NULL;
    novo->ant = (*n)->fim;

    if ((*n)->fim != NULL) {
        (*n)->fim->prox = novo;
    } else {
        (*n)->ini = novo;
    }

    (*n)->fim = novo;
    return 1;
}

int desenfileirar(noDesc *n, int *elem) {
    if (n == NULL || *n == NULL || (*n)->ini == NULL)
        return 0;

    struct fila *remover = (*n)->ini;
    *elem = remover->info;

    (*n)->ini = remover->prox;
    if ((*n)->ini != NULL) {
        (*n)->ini->ant = NULL;
    } else {
        (*n)->fim = NULL;
    }

    free(remover);
    return 1;
}
