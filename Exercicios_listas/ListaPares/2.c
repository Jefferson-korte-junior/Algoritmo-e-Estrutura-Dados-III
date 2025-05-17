// FEITO EM DUPLA POR: BRUNO E. S. ALCANTARA, RA: 2677156 & JEFFERSON K. JUNIOR, RA: 2651114.

#include <stdio.h>
#include <stdlib.h>

#include "lista.c"

int main() {

    struct aluno alunos1[4] = {
        {1, "Jefferson", 9.7, 6.7, 8.4},
        {2, "Bruno", 9.5, 7.8, 8.5},
        {3, "Marciano", 5.7, 6.1, 7.4},
        {4, "Igor", 7.5, 8.7, 6.8}
    };

    struct aluno alunos2[3] = {
        {1, "Jefferson", 9.7, 6.7, 8.4},
        {3, "Marciano", 5.7, 6.1, 7.4},
        {4, "Igor", 7.5, 8.7, 6.8}
    };

    Lista *lista1 = cria_lista();
    Lista *lista2 = cria_lista();

    for (int i = 0; i < 4; i++) 
        insere_lista_final(lista1, alunos1[i]); 
    for (int i = 0; i < 3; i++) 
        insere_lista_final(lista2, alunos2[i]);

    for (int i = 0; i < 2; i++) {
        if (equals(lista1, lista2)) {
            printf("-> Listas Iguais!\n\n");
        } else {
            printf("-> Listas Diferentes!\n\n");
        }
        removerNo(lista1, 2);
    }

    libera_lista(lista1);
    libera_lista(lista2);   
}

/*
    Crio dois vetores de alunos, um com 4, e outro com 3 (sendo iguais ao do primeiro), crio duas listas,
    passando esses alunos para elas, em seguida verifico através da função recursiva equals se elas são 
    iguais, inicialmente não, mas depois de eu remover um nó especifico da lista com 4 alunos e verificar
    novamente se são iguais, agora sim, e depois disso liberando a memória alocada das duas listas.
*/