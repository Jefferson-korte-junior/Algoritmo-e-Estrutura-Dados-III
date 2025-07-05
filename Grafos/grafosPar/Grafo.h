#ifndef GRAFO_H
#define GRAFO_H

// MATRIZ DE ADJACÊNCIA
typedef struct grafo Grafo;

typedef struct {
    int origem;
    int destino;
    float peso;
} ArestaMinima;

Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado);
void libera_Grafo(Grafo* gr);
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso);
int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo);
void imprime_Grafo(Grafo *gr);
int encontraNo(Grafo* gr, int no);
ArestaMinima encontraArestaMenorPeso(Grafo* gr);

// LISTA DE ADJACÊNCIA (EXERCÍCIO 4)
typedef struct lista {
    int destino;
    float peso;
    struct lista* prox;
} Lista;

typedef struct {
    Lista **vet;
    int nos;
} GrafoLista;

GrafoLista* cria_GrafoLista(int nro_vertices);
int insereArestaLista(GrafoLista* gr, int orig, int dest, float peso);
int removeArestaLista(GrafoLista* gr, int orig, int dest);
void libera_GrafoLista(GrafoLista* gr);

#endif