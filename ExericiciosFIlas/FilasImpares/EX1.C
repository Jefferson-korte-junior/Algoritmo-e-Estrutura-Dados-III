#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

int main() {

    struct aluno al,a[4] = {{2,"Andre",9.5,7.8,8.5},
                            {4,"Ricardo",7.5,8.7,6.8},
                            {1,"Bianca",9.7,6.7,8.4},
                            {3,"Ana",5.7,6.1,7.4}};
    

    Fila* fi1 = cria_Fila();
    Fila* fi2 = cria_Fila();

    for (int con =0; con < 4; con++){
        insere_Fila(fi1, a[con]);
    }

    separar (fi1, fi2, a[1].matricula);
    printf ("----------------------------------\n");
    printf ("Fila 01: \n");
    imprime_Fila (fi1);
    printf ("\n----------------------------------\n");
    printf ("Fila 02: ");
    imprime_Fila (fi2);
    printf ("\n----------------------------------\n");

    return 0;

    libera_Fila(fi1);
    libera_Fila(fi2);
}

//Feito em dupla: Jefferson korte RA 2651114 E Bruno E. S alcantara RA: 2677156

//Criamo um no e miramos ele para a celula que a fila01 esta olhando, Fizemos um WHILE para ele varrer essa fila ate achar a matricula desejada, enquanto ele nao acha nó vai receber o nó->Prox. 

//Quando ele achar a matricula desejada ele pega e aponta fi2->final para fi01-final, assim conseguindo ir ate o final da fila. E depois apontamos o fi02->inicio para o no-prox assim o inicio da fila02 sera um depois de achar a matricula desejada, assim dividindo as filas em 2 a partir da onde achamos a matricula.

//E depois apontamos o fi01->final para o no que é aonde esta a matricula e aponrtamos o fi01->final->prox para NULL, assim não tendo mais nada apos o final.
