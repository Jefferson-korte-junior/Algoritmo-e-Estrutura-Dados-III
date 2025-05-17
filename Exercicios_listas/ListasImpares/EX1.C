#include <stdio.h>
#include <stdlib.h>

#include "ListaDinEncad.h"
#include "ListaDinEncad.c"

int main () {

    struct aluno al[] = {
        {1, "Joao", 7.5, 8.0, 9.0},
        {2, "Maria", 6.5, 7.0, 8.0},
        {3, "Jose", 5.5, 6.0, 7.0},
        {4, "Ana", 9.5, 10.0, 9.0},
        {5, "Pedro", 8.5, 9.0, 8.0}
    };

    Lista *li = cria_lista();

    for (int con = 0; con < 5; con++) {
        insere_lista_ordenada(li, al[con]);
    }

    imprime_lista(li);

    printf ("--------------------------------\n");
    printf ("PROCURANDO ALUNO...\n");
    printf ("--------------------------------\n");

    consultaLista(li, 3);




    return 0;
}