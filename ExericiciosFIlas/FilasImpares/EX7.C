#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

int main(){

    struct aluno al,a[4] = {{2,"Andre",9.5,7.8,8.5},
                            {4,"Ricardo",7.5,8.7,6.8},
                            {1,"Bianca",9.7,6.7,8.4},
                            {3,"Ana",5.7,6.1,7.4}};


    Fila* fila = cria_Fila();


    for (int con = 0; con < 4; con++){
        insere_Fila(fila, a[con]);
    }

    printf ("---------------------------------------------\n");
    printf ("Fila Original: \n");
    printf ("---------------------------------------------\n");
    imprime_Fila(fila);


    printf ("\n---------------------------------------------\n");
    printf ("Fila Invesa: \n");
    printf ("---------------------------------------------\n");
    inverso(fila);
    imprime_Fila(fila);

    libera_Fila(fila);
    
    return 0;
}

//Feito em dupla: Jefferson korte RA 2651114 E Bruno E. S alcantara RA: 2677156

//A logica usada foi criar tres ponteiros auxiliares para ajudar a mudar os elementos da fila.
//Primeiro o nosso ponteiro atual vai receber o inicio da fila, apos isso fazemos um loop para ele varrer essa nossa fila.

//Depois o nosso ponteiro noProximo que é um auxiliar vai receber o proximo elemento do noAtual, assim gurdando o elemento da frente da fila.

//Depois que guardamos o nosso noAtual-prox, podemos mudar ele pra receber o nosso noAnterior.

//Apos isso nosso noAnterior vai recebe o nosso noAtual.

//E o nosso noAtual vai receber o noProximo que esta guardando o noatual->prox.
//Assim ficando nesse loop ate o nosso noAtual ser igual a NULL. Significando que ja varreu toda a fila.
//E apos o loop apenas mudamos o inicio e o final da fila, para o final receber o inicio
