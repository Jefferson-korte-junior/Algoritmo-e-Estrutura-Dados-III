#ifndef FILA_DIN_PROTOTIPOS_H
#define FILA_DIN_PROTOTIPOS_H


//Arquivo FilaDin.h
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

struct aviao {
    int id;
    char tamanho[50];
    char modelo[50];
};


typedef struct fila Fila;
typedef struct FilaPrincipal filaPrincipal;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct aluno *al);
int insere_Fila(Fila* fi, struct aluno al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);
int separar(Fila* fi1, Fila* fi2, int matricula);
FilaPrincipal* criaFilaDeFila();

int inverso (Fila* fila); //exericio 7

#endif


