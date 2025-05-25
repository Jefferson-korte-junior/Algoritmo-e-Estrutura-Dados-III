// FEITO EM DUPLA POR: BRUNO E. S. ALCANTARA, RA: 2677156 & JEFFERSON K. JUNIOR, RA: 2651114.

#include <stdio.h>
#include <stdlib.h>

#include "ListaDinEncadDupla.c"

int main() {

    struct aluno alunos[] = {
        {1, "Bruno Alcantara", 10.0, 10.0, 10.0},
        {2, "Jefferson Korte", 9.0, 10.0, 10.0},
        {3, "Igor Carvalho", 10.0, 10.0, 10.0}
    };

    Lista* lista = cria_lista();
    for (int i = 0; i < 3; i++)
        insere_lista_final(lista, alunos[i]);

    printf("-> Existem %d aluno(s) com a nota 10.0!\n", conta_lista_nota(lista, 10.0));

    libera_lista(lista);
}

/*
    Crio um vetor de alunos, crio uma lista, adiciono os alunos a lista, chamo
    a função conta_lista_nota diretamente no printf onde ela percorre por toda
    a lista buscando por notas iguais a passada, no caso, 10.0, assim imprimindo
    a determinada quantia da mesma nota. logo depois liberando a memória da lista.
*/