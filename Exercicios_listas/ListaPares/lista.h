#ifndef LISTA_H
#define LISTA_H

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct elemento* Lista;
typedef struct ElementoFloat* ListaFloat;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia();
void imprime_lista(Lista* li);

// -> Exercicio 1:
struct aluno* consultarAlunoMat(Lista* lista, int matricula);
struct aluno* consultarAlunoPos(Lista* lista, int pos);

// -> Exercicio 2:
int removerNo(Lista* lista, int remover);
int equals(Lista* lista1, Lista* lista2);

// -> Exercicio 4:
ListaFloat* criarListaFloat();
int inserirFinalListaFloat(ListaFloat* lista, float valor);
ListaFloat* vetorParaLista(float* vetor, int tamanho);
void imprimirListaFloat(ListaFloat* lista);
void liberarListaFloat(ListaFloat* lista);

// -> Exercicio 6:
Lista* concatenar(Lista* lista1, Lista* lista2);

// -> Exercicio 8:
int ordenar (Lista* lista);
int fusaoOrdenada(Lista* lista1, Lista* lista2);

#endif