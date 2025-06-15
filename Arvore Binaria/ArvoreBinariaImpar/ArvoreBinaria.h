
typedef struct NO* ArvBin;
typedef struct NO2* ArvBin2;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, int valor);
int remove_ArvBin(ArvBin *raiz, int valor);
struct NO* remove_atual(struct NO* atual);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
// int totalNO_ArvBin(ArvBin *raiz);
// int consulta_ArvBin(ArvBin *raiz, int valor);
void preOrdem_ArvBin(ArvBin *raiz);
// void emOrdem_ArvBin(ArvBin *raiz);
// void posOrdem_ArvBin(ArvBin *raiz);

// Exercicio 1
int qtdNosFolha(ArvBin *raiz);

// Exercicio 3
int qtdValor(ArvBin *raiz, int valor);

// Exercicio 5
int iguais(ArvBin *raiz, ArvBin *raiz2);

// Exercicio 7
int similares(ArvBin *raiz, ArvBin *raiz2);

// Exercicio 9
ArvBin2* cria_ArvBin2();
ArvBin2* criaArvoreExpressao();
int calcular(ArvBin2 *raiz);
void imprimirInfixa(ArvBin2 *raiz);
void imprimirPrefixa(ArvBin2 *raiz);
void imprimirPosfixa(ArvBin2 *raiz);