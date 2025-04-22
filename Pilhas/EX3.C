#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


int main() {
    
    Pilha *pilha = criarPilha(); // Cria a pilha
    Pilha *copia = criarPilha(); // Cria a pilha copia
    int numeros[] = {1, 2, 3, 4, 5};

    for (int con = 0; con < 5; con++){
        push(pilha, numeros[con]);
    }


    printf ("Tamanho da pilha: %d \n", size(pilha));
    printf ("\n-------------------------------------------\n");
    printf ("Elementos da pilha: \n");
    print (pilha);
    printf ("\n-------------------------------------------\n");

    copiaPilha(pilha, copia);

    printf ("Elementos da pilha copia: \n");
    print (copia);
    printf ("\n-------------------------------------------\n");

    return 0;
}

//Realizado em dupla: Jefferson korte junior e bruno alcantara

//Aqui eu criei uma funçao chama copiaPilha e a primeira coisa que faço é retirar o ultimo elemento da pilha usando o pop, assim ja poego e chamo a função push e passo uma Pilha *copia e passo o segundo parametro o ultimoelemento da pilha original queacabei de retirar, assim adicionando a pilha *copia ate que a pilha original seja igual a NULL.
