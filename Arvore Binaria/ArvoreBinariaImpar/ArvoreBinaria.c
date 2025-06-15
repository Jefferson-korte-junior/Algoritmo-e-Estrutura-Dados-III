#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h" //inclui os Prot�tipos

struct NO {
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
            // if(valor == atual->info){  > Comentado por causa do Exercicio 3 < 
            //     free(novo);
            //     return 0;//elemento j� existe
            // }

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

///////////////////////////////////////////////////////
// Exercicio 1                                       //
///////////////////////////////////////////////////////
int qtdNosFolha(ArvBin *raiz) {
    if(raiz == NULL || *raiz == NULL)
        return 0;
    if ((*raiz)->dir == NULL && (*raiz)->dir == NULL)
        return 1;
    return qtdNosFolha(&((*raiz)->esq)) + qtdNosFolha(&((*raiz)->dir));
}

///////////////////////////////////////////////////////
// Exercicio 3                                       //
///////////////////////////////////////////////////////
int qtdValor(ArvBin *raiz, int valor) {
    if(raiz == NULL || *raiz == NULL)
        return 0;
    if ((*raiz)->info == valor)
        return 1 + qtdValor(&((*raiz)->esq), valor) + qtdValor(&((*raiz)->dir), valor);
    return qtdValor(&((*raiz)->esq), valor) + qtdValor(&((*raiz)->dir), valor);
}

///////////////////////////////////////////////////////
// Exercicio 5                                       //
///////////////////////////////////////////////////////
int iguais(ArvBin *raiz, ArvBin *raiz2) {
    if ((raiz == NULL || *raiz == NULL) && (raiz2 == NULL || *raiz2 == NULL))
        return 1;
    if (raiz == NULL || *raiz == NULL || raiz2 == NULL || *raiz2 == NULL)
        return 0;
    if ((*raiz)->info != (*raiz2)->info)
        return 0;
    if (!iguais(&((*raiz)->esq), &((*raiz2)->esq)))
        return 0;
    if (!iguais(&((*raiz)->dir), &((*raiz2)->dir)))
        return 0;
    return 1;
}

///////////////////////////////////////////////////////
// Exercicio 7                                       //
///////////////////////////////////////////////////////
int similares(ArvBin *raiz, ArvBin *raiz2) {
    if ((raiz == NULL || *raiz == NULL) && (raiz2 == NULL || *raiz2 == NULL))
        return 1;
    if (raiz == NULL || *raiz == NULL || raiz2 == NULL || *raiz2 == NULL)
        return 0;
    return (similares(&((*raiz)->esq), &((*raiz2)->esq)) && similares(&((*raiz)->dir), &((*raiz2)->dir)));
}

///////////////////////////////////////////////////////
// Exercicio 9                                       //
///////////////////////////////////////////////////////
struct NO2 {
    char info;             
    struct NO2 *esq;
    struct NO2 *dir;
};

/////////
/// A ///
/////////
ArvBin2* cria_ArvBin2() {
    ArvBin2* raiz = (ArvBin2*) malloc(sizeof(ArvBin2));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

ArvBin2* criaArvoreExpressao() {
    ArvBin2* raiz = cria_ArvBin2();

    struct NO2* noMais = (struct NO2*) malloc(sizeof(struct NO2));
    noMais->info = '+';

    struct NO2* no5 = (struct NO2*) malloc(sizeof(struct NO2));
    no5->info = '5';
    no5->esq = NULL;
    no5->dir = NULL;

    struct NO2* noMultiplica = (struct NO2*) malloc(sizeof(struct NO2));
    noMultiplica->info = '*';

    struct NO2* noMenos1 = (struct NO2*) malloc(sizeof(struct NO2));
    noMenos1->info = '-';
    struct NO2* no6 = (struct NO2*) malloc(sizeof(struct NO2));
    no6->info = '6';
    no6->esq = NULL;
    no6->dir = NULL;
    struct NO2* no3 = (struct NO2*) malloc(sizeof(struct NO2));
    no3->info = '3';
    no3->esq = NULL;
    no3->dir = NULL;
    noMenos1->esq = no6;
    noMenos1->dir = no3;

    struct NO2* noMenos2 = (struct NO2*) malloc(sizeof(struct NO2));
    noMenos2->info = '-';
    struct NO2* no4 = (struct NO2*) malloc(sizeof(struct NO2));
    no4->info = '4';
    no4->esq = NULL;
    no4->dir = NULL;
    struct NO2* no1 = (struct NO2*) malloc(sizeof(struct NO2));
    no1->info = '1';
    no1->esq = NULL;
    no1->dir = NULL;
    noMenos2->esq = no4;
    noMenos2->dir = no1;

    noMultiplica->esq = noMenos1;
    noMultiplica->dir = noMenos2;

    noMais->esq = noMultiplica;
    noMais->dir = no5;

    *raiz = noMais;
    return raiz;
}

/////////
/// B ///
/////////
int calcular(ArvBin2 *raiz) {
    if (raiz == NULL || *raiz == NULL)
        return 0;

    // Se for folha (número):
    if ((*raiz)->esq == NULL && (*raiz)->dir == NULL)
        return (*raiz)->info - '0';  // Transforma char número para inteiro

    int esquerda = calcular(&((*raiz)->esq));
    int direita = calcular(&((*raiz)->dir));

    switch ((*raiz)->info) {
        case '+': return esquerda + direita;
        case '-': return esquerda - direita;
        case '*': return esquerda * direita;
        case '/': return esquerda / direita;
        default: return 0;
    }
}

/////////
/// C ///
/////////
void imprimirInfixa(ArvBin2 *raiz) {
    if (raiz == NULL || *raiz == NULL) return;
    if ((*raiz)->esq != NULL || (*raiz)->dir != NULL) printf("(");
    imprimirInfixa(&((*raiz)->esq));
    printf("%c", (*raiz)->info);
    imprimirInfixa(&((*raiz)->dir));
    if ((*raiz)->esq != NULL || (*raiz)->dir != NULL) printf(")");
}

void imprimirPrefixa(ArvBin2 *raiz) {
    if (raiz == NULL || *raiz == NULL) return;
    printf("%c ", (*raiz)->info);
    imprimirPrefixa(&((*raiz)->esq));
    imprimirPrefixa(&((*raiz)->dir));
}

void imprimirPosfixa(ArvBin2 *raiz) {
    if (raiz == NULL || *raiz == NULL) return;
    imprimirPosfixa(&((*raiz)->esq));
    imprimirPosfixa(&((*raiz)->dir));
    printf("%c ", (*raiz)->info);
}


