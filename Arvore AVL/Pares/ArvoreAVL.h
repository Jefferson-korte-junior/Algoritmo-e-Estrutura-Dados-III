#ifndef ARVORE_AVL
#define ARVORE_AVL

typedef struct NO* ArvAVL;

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int insere_ArvAVL(ArvAVL *raiz, int data);
int remove_ArvAVL(ArvAVL *raiz, int valor);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
int consulta_ArvAVL(ArvAVL *raiz, int valor);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);
void RotacaoLR(ArvAVL *raiz);
void RotacaoRL(ArvAVL *raiz);

// Exercicio 4
void RotacaoRR(ArvAVL *raiz);

// Exercicio 8
void insereEmOrdem(struct NO* raizABB, ArvAVL *raizAVL);
ArvAVL* transforma(ArvAVL *raiz_original);

#endif
