#ifndef LISTA_DIN_ENCAD_DUPLA_H
#define LISTA_DIN_ENCAD_DUPLA_H

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;
typedef struct nodesc* noDesc;

Lista* cria_lista();
void libera_lista(Lista* li);
int consulta_lista_pos(Lista* li, int pos, struct aluno *al);
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);

// -> Exercicio 1:
int removerPorMatricula(Lista* lista, int matricula);

// -> Exercicio 3:
int conta_lista_nota(Lista* lista, int n1);

// -> Exercicio 5:
int enfileirar(noDesc *n, int elem);
int desenfileirar(noDesc *n, int *elem);

#endif