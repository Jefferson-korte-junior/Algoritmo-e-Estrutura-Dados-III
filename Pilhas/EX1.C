#include <stdlib.h>
#include <stdio.h>

#include "Pilha.h" //inclui os Protótipos

int main(){

    int numeros[2] = {1,2};

    Pilha *pilha = criarPilha(); // Cria a pilha
    push2(pilha, numeros);

    printf ("Tamanho da pilha: %d",size(pilha));
    printf ("\nOs elementos da pilha sao: \n");
    print (pilha);
    printf ("\n---------------------------------------------\n");

    int *numerosPop = (int *)malloc(2 *sizeof(int));
    pop2(pilha, numerosPop);

    printf ("Os elementos tirados da pilha foram: \n");
    for (int con = 0; con < 2; con++){
        printf ("%d\n", numerosPop[con]);
    }

    printf ("\ntamanho da pilha apos: %d", size(pilha));

    clear(pilha);
    printf ("\n---------------------------------------------\n");


    
    return 0;
}

//Realizado em dupla: Jefferson korte junior e bruno alcantara

//As funçoes pop e pop2 sao bem parecidas para fazer a função Pop2 retirar dois elementos de uma fez, apenas peguei e coloquei um for (loop) dentro da função pop2 para o con (contador) ir de 0 ate 2, assim retirando dois elementos por vez.