/*

// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

//////////////////////////////////////
// 3                                //
//////////////////////////////////////
///////
// A //
///////
Função void libera_Grafo(Grafo* gr)
Essa função aloca dinamicamente e inicializa uma estrutura de grafo com número fixo de vértices e grau máximo por vértice.

Aloca a struct principal do grafo:
    gr = (Grafo*) malloc(sizeof(struct grafo));

Define os atributos básicos:
    gr->nro_vertices = nro_vertices;
    gr->grau_max = grau_max;
    gr->eh_ponderado = (eh_ponderado != 0)?1:0;

Aloca o vetor de graus (inicializado com zeros):
    gr->grau = (int*) calloc(nro_vertices, sizeof(int));


Aloca a matriz de arestas (lista de adjacência):
    gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));
    for(i = 0; i < nro_vertices; i++)
        gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));

Se for ponderado, aloca também a matriz de pesos:
    if(gr->eh_ponderado){
        gr->pesos = (float**) malloc(nro_vertices * sizeof(float*));
        for(i = 0; i < nro_vertices; i++)
            gr->pesos[i] = (float*) malloc(grau_max * sizeof(float));
    }

///////
// B //
///////
Função void libera_Grafo(Grafo* gr)
Libera toda a memória alocada para o grafo, evitando vazamentos de memória.

Libera cada linha da matriz de arestas:
    for(i = 0; i < gr->nro_vertices; i++)
        free(gr->arestas[i]);
    free(gr->arestas);

Se o grafo for ponderado, libera a matriz de pesos:
    if(gr->eh_ponderado){
        for(i = 0; i < gr->nro_vertices; i++)
            free(gr->pesos[i]);
        free(gr->pesos);
    }

Libera o vetor de graus e a struct principal:
    free(gr->grau);
    free(gr);

///////
// C //
///////
Função int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso)
Insere uma aresta de orig para dest no grafo.

Validações iniciais de ponteiros e índices:
    if(gr == NULL || orig < 0 || dest < 0 || orig >= gr->nro_vertices || dest >= gr->nro_vertices)
        return 0;

Adiciona dest na lista de adjacência de orig:
    gr->arestas[orig][gr->grau[orig]] = dest;

Se o grafo for ponderado, armazena o peso:
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;

Incrementa o grau do vértice de origem:
    gr->grau[orig]++;

Se o grafo for não-direcionado, insere a aresta inversa:
    if(eh_digrafo == 0)
        insereAresta(gr, dest, orig, 1, peso);

///////
// D //
///////
Função int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo)
Remove uma aresta de orig para dest.

Validações iniciais:
    if(gr == NULL || orig < 0 || dest < 0 || orig >= gr->nro_vertices || dest >= gr->nro_vertices)
        return 0;
    
Procura a posição da aresta em arestas[orig]:
    int i = 0;
    while(i < gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;
    if(i == gr->grau[orig])
        return 0; // não encontrou

Remove a aresta movendo a última da lista para o lugar da que foi removida:
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];

Se for ponderado, atualiza os pesos:
    if(gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];

Se for não-direcionado, remove a aresta inversa:
    if(eh_digrafo == 0)
        removeAresta(gr, dest, orig, 1);
*/