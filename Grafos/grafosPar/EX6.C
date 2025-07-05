#include <stdlib.h>
#include <stdio.h>
#include "Grafo.h"

int main() {
    Grafo* gr = cria_Grafo(4, 3, 1);

    insereAresta(gr, 0, 1, 0, 2);
    insereAresta(gr, 0, 2, 0, 1);
    insereAresta(gr, 1, 3, 0, 3);
    insereAresta(gr, 2, 3, 0, 4);

    printf("Grafo:\n");
    imprime_Grafo(gr);

    int no = 2;
    if (encontraNo(gr, no)) {
        printf("O no %d existe no grafo.\n", no);
    } else {
        printf("O no %d nao existe no grafo.\n", no);
    }

    ArestaMinima am = encontraArestaMenorPeso(gr);
    if (am.origem != -1) {
        printf("A menor aresta  de %d para %d com peso %.2f\n", am.origem, am.destino, am.peso);
    } else {
        printf("Não há arestas ponderadas no grafo.\n");
    }

    libera_Grafo(gr);

    system("pause");
    return 0;
}

//A função encontraNo tem como objetivo verificar se um nó  existe no grafo. Para isso, ela primeiro analisa se o ponteiro que representa o grafo é nulo, se sim return 0.. Em seguida, ela verifica se o número do nó dado está dentro dos limites  do grafo. Se o número do nó estiver fora desses limites, a função também retorna 0. Caso todas as verificações sejam satisfeitas, a função retorna 1, indicando que o nó de fato existe no grafo.

//Já a função encontraArestaMenorPeso é responsável por encontrar aquela que possui o menor peso. Primeiramente, ela verifica se o grafo é válido e se ele tem pesos atrbuidos as arestas. Se qualquer uma dessas condições não for atendida, ela retorna ja. Caso o grafo seja válido, a função percorre todas as arestas armazenadas nas estruturas, comparando seus pesos.Ao final da execução, a função retorna a aresta de menor peso encontrada no grafo.