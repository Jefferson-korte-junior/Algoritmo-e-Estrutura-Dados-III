#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main() {

    ArvBin2 *raiz = criaArvoreExpressao();

    calcular(raiz);

    printf("\n");
    imprimirInfixa(raiz);
    printf("\n");
    imprimirPosfixa(raiz);
    printf("\n");
    imprimirPrefixa(raiz);
    printf("\n");

    printf("-> Resultado: %d\n\n", calcular(raiz));

    system("pause");

    return 0;
}

// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

/*      criaArvoreExpressao
    Cria a arvore: ((6-3)*(4-1))+5. Cada operador (+, *, -) e número (6, 3, 4, 1, 5)
    é um nó da árvore.
*/

/*      consulta_ArvBin
    Percorre pela arvore verificando se o valor é maior ou menor para ir mais
    rápido, assim, quando encontrado o valor retornado 1, se não encontrar, retorna 0.
*/

/*      calcular
    Função recursiva que percorre a arvore para calcular o resultado final
    da expressão. Se o nó atual for um número (folha), converte o caractere
    numérico em inteiro e retorna. Se for um operador, calcula os resultados
    das subárvores esquerda e direita e aplica o operador correspondente (+, -, *, /).
*/

/*      imprimirInfixa
    Imprime a expressão da arvore com formato infixo,
    com parênteses para determinar a ordem das contas.
    Percorre primeiro a esquerda, imprime o operador atual,
    e depois a direita.
*/

/*      imprimirPrefixa
    Imprime a expressão da arvore com formato prefixo.
    Primeiro imprime o operador atual, depois o nó esquerdo
    e em seguida o direito.
*/

/*      imprimirInfixa
    Imprime a expressão da arvore com formato posfixo.
    Primeiro percorre o nó esquerdo, depois o direito e por
    ultimo o operador atual.
*/