// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main() {
    int n = 5;
    int **grafo = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        grafo[i] = (int *)calloc(n, sizeof(int));

    grafo[0][1] = 2; grafo[1][0] = 2;
    grafo[0][3] = 6; grafo[3][0] = 6;
    grafo[1][2] = 3; grafo[2][1] = 3;
    grafo[1][3] = 8; grafo[3][1] = 8;
    grafo[1][4] = 5; grafo[4][1] = 5;
    grafo[2][4] = 7; grafo[4][2] = 7;
    grafo[3][4] = 9; grafo[4][3] = 9;

    prim(grafo, n);

    for (int i = 0; i < n; i++)
        free(grafo[i]);
    free(grafo);

    return 0;
}

/*      minKey(int chave[], int visitado[], int n)
   Percorre o vetor de chaves e retorna o índice do vértice
   que tem o menor valor e ainda não foi visitado. Serve pra saber qual vértice
   vai ser incluído na próxima etapa da árvore no algoritmo de Prim.
*/

/*      prim(int **grafo, int n)
   Função para encontrar a árvore geradora mínima.
   Ela usa três vetores: um pra guardar os menores pesos (chave), um pra indicar
   quem é o pai de cada vértice (pai) e outro pra saber quais vértices já foram
   visitados (visitado). No final, ela mostra as arestas que fazem parte da árvore.
*/
