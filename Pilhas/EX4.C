#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main() {
    Pilha *pilha = criarPilha(); 
    int numeros [] = {1, 2, 3, 4, 5};

    for (int con = 0; con < 5; con++){
        push(pilha, numeros[con]);
    }
    
    printf ("Tamanho da pilha: %d \n", size(pilha));
    printf ("\n-------------------------------------------\n");
    printf ("Elementos da pilha: \n");
    print (pilha);
    printf ("\n-------------------------------------------\n");

    printf ("Maior valor encontrado na pilha: %d\n", maiorValor(pilha));
    printf ("Menor valor encontrado na pilha: %d\n", menorValor(pilha));
    printf ("A media dos valores da pilha: %f\n", media(pilha));
    printf ("\n-------------------------------------------\n");

    return 0;
}

//Realizado em dupla: Jefferson korte junior e bruno alcantara

//Aqui criei tres funçoes, sei que podia ter feito em uma mais quis deixar mais organizado.

//A funçao maiorValor funciona assim: eu retiro o ultimoElemento da pilha, e verifico se esse elemento é maior que a variavel maior que começa com 0. Se for Troca e dai ao final retorna maior.

//A função menorValor Funciona do mesmo jeito, eu retiro o ultimoElemento da pilha, e verifico se o ultimoElemento é menor que a variavel menor que começa com o valor do primeiro elemento da pilha. Se for Troca e dai ao final retorna menor.

//E em questao da media eu vou pegando os ultimosElementos e vou adicionando a variavel soma, e tambem adiciono um contador para ir somando e apos pego e crio uma variavel media que é a soma dividida pelo contador, e retorno a media.