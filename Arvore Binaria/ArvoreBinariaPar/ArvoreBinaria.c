#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h" //inclui os Prot�tipos

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada n�
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento j� existe
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 � o n� anterior a r na ordem e-r-d
    // no1 � o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}


void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}


//////////////////////////////////////////////
//EXERCICIO 2/////////////////////////////////
//////////////////////////////////////////////
void imprimeDetalhada(struct NO* no, int valorPai, char* tipo) {
    if (no == NULL)
        return;

    printf("Nó: %d | Pai: ", no->info);
    if (valorPai == -1)
        printf("NULL (raiz)");
    else
        printf("%d (%s)", valorPai, tipo);

    if (no->esq == NULL && no->dir == NULL)
        printf(" | Tipo: folha");
    printf("\n");

    imprimeDetalhada(no->esq, no->info, "esquerda");
    imprimeDetalhada(no->dir, no->info, "direita");
}

//////////////////////////////////////////////
//EXERCICIO 4/////////////////////////////////
//////////////////////////////////////////////
void imprimeFolhasDecrescente(struct NO* no) {
    if (no == NULL)
        return;

    imprimeFolhasDecrescente(no->dir);
    if (no->esq == NULL && no->dir == NULL)
        printf("%d ", no->info);
    imprimeFolhasDecrescente(no->esq);
}


//////////////////////////////////////////////
//EXERCICIO 6/////////////////////////////////
//////////////////////////////////////////////
void removePares_ArvBin(ArvBin *raiz) {
    if (raiz == NULL || *raiz == NULL)
        return;

    removePares_ArvBin(&((*raiz)->esq));
    removePares_ArvBin(&((*raiz)->dir));

    if ((*raiz)->info % 2 == 0) {
        remove_ArvBin(raiz, (*raiz)->info);
        // Após remover, pode ter mudado o ponteiro, então chama novamente para garantir
        removePares_ArvBin(raiz);
    }
}

//////////////////////////////////////////////
//EXERCICIO 8/////////////////////////////////
//////////////////////////////////////////////
void imprimeDetalhadaChar(struct NO* no, int valorPai, char* tipo) {
    if (no == NULL)
        return;

    printf("Nó: %c | Pai: ", no->info);
    if (valorPai == -1)
        printf("NULL (raiz)");
    else
        printf("%c (%s)", valorPai, tipo);

    if (no->esq == NULL && no->dir == NULL)
        printf(" | Tipo: folha");
    printf("\n");

    imprimeDetalhadaChar(no->esq, no->info, "esquerda");
    imprimeDetalhadaChar(no->dir, no->info, "direita");
}

