#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main() {

    Pilha *pilha1 = criarPilha();
    Pilha *pilha2 = criarPilha();

    int numeros1[] = {1, 2, 3, 4, 5};
    int numeros2[] = {1, 2, 3, 4, 5};

    for (int con = 0; con < 5; con++){
        push(pilha1, numeros1[con]);
        push(pilha2, numeros2[con]);
    }

    printf ("\n-------------------------------------------\n"); 
    printf ("Elementos da pilha 1: \n");
    print(pilha1);
    printf ("Elementos da pilha 2: \n");
    print(pilha2);
    printf ("\n-------------------------------------------\n"); 

    pilhasIguais(pilha1, pilha2);
   
    return 0;
}

//Realizado em dupla: Jefferson korte junior e bruno alcantara

//Na questao 5 para verificar se as pilhas sao iguas eu peguei e fui coferindo cada ultimoElemento, caso houver algum que nao seja igual ja retorna que as pilha sao diferentes.

//Eu peguei e tirei o ultimoElemento da pilha1 e retirei o ultimo elemento da pilha2 assim comprando os dois e vendo se sao ou nao iguais.
