// FEITO EM DUPLA POR: BRUNO E. S. ALCANTARA, RA: 2677156 & JEFFERSON K. JUNIOR, RA: 2651114.

#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

int main() {

    struct aluno alunos1[4] = {
        {2,"Andre",9.5,7.8,8.5},
        {4,"Ricardo",7.5,8.7,6.8},
        {1,"Bianca",9.7,6.7,8.4},
        {3,"Ana",5.7,6.1,7.4}
    };

    struct aluno alunos2[4] = {
        {1,"Bruno",9.5,7.8,8.5},
        {2,"Jefferson",7.5,8.7,6.8},
        {3,"Igor",9.7,6.7,8.4},
        {4,"Marciano",5.7,6.1,7.4}
    };

    Fila *fila1 = cria_Fila();
    Fila *fila2 = cria_Fila();

    for (int i = 0; i < 4; i++) {
        insere_Fila(fila1, alunos1[i]);
        insere_Fila(fila2, alunos2[i]);
    }

    FilaDeFila *filaPrincipal = criarFilaDeFila();
    inserirFilaNaFila(filaPrincipal, fila1);
    inserirFilaNaFila(filaPrincipal, fila2);

    imprimirFilaDeFila(filaPrincipal);

    liberarFilaDeFila(filaPrincipal);
    libera_Fila(fila1);
    libera_Fila(fila2);

    return 0;
}

/*
    São criadas duas filas, passada 4 alunos para cada, e em seguida criado uma fila principal,
    que a partir da função insereFilaNaFila que tem como parametro a fila que irá receber e a
    que será adicionada adicione outras filas. Para que isso funcione, foi necessário criar um
    novo tipo de fila, a qual invés de receber alunos, a fila receba filas, e essas filas, alunos.
    Assim, foi feito uma função que passa por dentro da fila principal chamando a função
    já existente imprime_fila nas filas normais, assim verificando se foram os alunos realmente
    adicionados a fila que foi adicionado a fila principal.
    Concluindo, fizemos uma função liberarFilaDeFila que segue da mesma forma que a função dita
    anterior, a qual passa por dentro da fila principal chamando a outra função existente 
    libera_pilha assim, liberando a memória, e em seguida finalizando o programa.
*/
