#include <stdio.h>
#include <stdlib.h>

#include "ListaDinEncadDupla.h" 
#include "ListaDinEncadDupla.c"

int main () {

    struct aluno al[] = {
        {1, "Andre", 9.5, 1.0, 5.3},
        {2, "Joao", 9.0, 8.4, 7.7},
        {3, "Maria", 8.5, 7.8, 6.9},
        {4, "Ana", 7.0, 6.1, 5.4}
    };

    Lista *li = cria_lista();

    for (int con = 0; con < 4; con++){
        insere_lista_ordenada(li, al[con]);
    }

    printf("-------------------------------------\n");
    imprime_lista(li);
    
    struct aluno alunoNovo = {3, "Jefferson", 9.0, 2.5, 1.7};
    insere_lista_ordenada(li, alunoNovo);
    printf("\n-------------------------------------\n");
    imprime_lista(li);


    return 0;
}

//Feito em Dupla Jefferson korte junior RA 2651114 & Bruno eduardo RA: 26677156