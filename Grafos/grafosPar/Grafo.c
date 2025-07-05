#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h" //inclui os Prot�tipos

//Defini��o do tipo Grafo
struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado){
    Grafo *gr;
    gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0;
        gr->grau = (int*) calloc(nro_vertices,sizeof(int));

        gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));
        for(i=0; i<nro_vertices; i++)
            gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));

        if(gr->eh_ponderado){
            gr->pesos = (float**) malloc(nro_vertices * sizeof(float*));
            for(i=0; i<nro_vertices; i++)
                gr->pesos[i] = (float*) malloc(grau_max * sizeof(float));
        }

    }
    return gr;
}

void libera_Grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i=0; i<gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        if(gr->eh_ponderado){
            for(i=0; i<gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;

    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;
}

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    int i = 0;
    while(i<gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;
    if(i == gr->grau[orig])//elemento nao encontrado
        return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    if(gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    if(eh_digrafo == 0)
        removeAresta(gr,dest,orig,1);
    return 1;
}

void imprime_Grafo(Grafo *gr){
    if(gr == NULL)
        return;

    int i, j;
    for(i=0; i < gr->nro_vertices; i++){
        printf("%d: ", i);
        for(j=0; j < gr->grau[i]; j++){
            if(gr->eh_ponderado)
                printf("%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
            else
                printf("%d, ", gr->arestas[i][j]);
        }
        printf("\n");
    }
}

////////////////////////////////////
//EXERCICIO 4
////////////////////////////////////

typedef struct {
    Lista **vet;
    int nos;
} GrafoLista;


#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

GrafoLista* cria_GrafoLista(int nro_vertices) {
    GrafoLista *gr = (Grafo*) malloc(sizeof(Grafo));
    if (gr != NULL) {
        gr->nos = nro_vertices;
        gr->vet = (Lista**) malloc(nro_vertices * sizeof(Lista*));
        for (int i = 0; i < nro_vertices; i++)
            gr->vet[i] = NULL;
    }
    return gr;
}


int insereArestaLista(GrafoLista* gr, int orig, int dest, int digrafo, float peso) {
    if (gr == NULL || orig < 0 || orig >= gr->nos || dest < 0 || dest >= gr->nos)
        return 0;

    Lista *novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL) return 0;

    novo->destino = dest;
    novo->peso = peso;
    novo->prox = gr->vet[orig];
    gr->vet[orig] = novo;

    if (!digrafo)
        return insereArestaLista(gr, dest, orig, 1, peso);

    return 1;
}

int removeArestaLista(GrafoLista* gr, int orig, int dest, int digrafo) {
    if (gr == NULL || orig < 0 || orig >= gr->nos || dest < 0 || dest >= gr->nos)
        return 0;

    Lista *ant = NULL;
    Lista *atual = gr->vet[orig];

    while (atual != NULL && atual->destino != dest) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return 0; // não encontrou

    if (ant == NULL)
        gr->vet[orig] = atual->prox;
    else
        ant->prox = atual->prox;

    free(atual);

    if (!digrafo)
        return removeArestaLista(gr, dest, orig, 1);

    return 1;
}

void  libera_GrafoLista(GrafoLista* gr) {
    if (gr != NULL) {
        for (int i = 0; i < gr->nos; i++) {
            Lista *aux = gr->vet[i];
            while (aux != NULL) {
                Lista *temp = aux;
                aux = aux->prox;
                free(temp);
            }
        }
        free(gr->vet);
        free(gr);
    }
}



////////////////////////////////////
//EXERCICIO 6
////////////////////////////////////

//A)
int encontraNo(Grafo* gr, int no) {
    if (gr == NULL) 
        return 0;
    if (no < 0 || no >= gr->nro_vertices) return 0;
        return 1;
}

//B)
ArestaMinima encontraArestaMenorPeso(Grafo* gr) {
    ArestaMinima resultado = {-1, -1, 0.0};
    if (gr == NULL || !gr->eh_ponderado) 
        return resultado;

    int l, c;
    float menor = __FLT_MAX__;
    for (l = 0; l < gr->nro_vertices; l++) {
        for (c = 0; c < gr->grau[l]; c++) {
            if (gr->pesos[l][c] < menor) {
                menor = gr->pesos[l][c];
                resultado.origem = l;
                resultado.destino = gr->arestas[l][c];
                resultado.peso = menor;
            }
        }
    }
    return resultado;
}







