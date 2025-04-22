#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    int n = 0;
    int numeros[] = {1, 2, 3, 4, 5};

    printf ("Quantos elementos deseja tirar da pilha?");
    scanf("%d", &n);
    printf ("OK");
    printf ("\n-------------------------------------------\n");

    Pilha *Pilha = criarPilha(); 
    for (int con = 0; con < 5; con++){
        push(Pilha, numeros[con]);
    }
    
    printf ("Tamanho da pilha: %d \n", size(Pilha));
    printf ("\n-------------------------------------------\n");
    printf ("Elementos da pilha: \n");
    print (Pilha);
    printf ("\n-------------------------------------------\n");

    int *numerosRetirar = (int *)malloc(n * sizeof(int));
    popN(Pilha, numerosRetirar, n);

    printf ("Os elementos retirados da pilha foram: \n");
    for (int con = 0; con < n; con++){
        printf ("%d\n", numerosRetirar[con]);
    }

    printf ("Tamanho da pilha depois: %d \n", size(Pilha));
    printf ("\n-------------------------------------------\n");

    clear(Pilha);

  

    return 0;
}

//Realizado em dupla: Jefferson korte junior e bruno alcantara

//A logica usada aqui foi a mesma para a pop2, so que agora a unica mudança foi no for (loop) da função que em vez do contador ir de 0 ate 2, fiz que vai de 0 ate N. que sera oque o usuario digitar no teclado.
