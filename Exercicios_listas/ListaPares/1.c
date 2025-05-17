// FEITO EM DUPLA POR: BRUNO E. S. ALCANTARA, RA: 2677156 & JEFFERSON K. JUNIOR, RA: 2651114.

#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

int main() {

    struct aluno alunos[4] = {
        {1, "Jefferson", 9.7, 6.7, 8.4},
        {2, "Bruno", 9.5, 7.8, 8.5},
        {3, "Marciano", 5.7, 6.1, 7.4},
        {4, "Igor", 7.5, 8.7, 6.8}
    };

    Lista* lista = cria_lista();
    for (int i = 0; i < 4; i++)
        insere_lista_final(lista, alunos[i]);

    // Alternativa A
    struct aluno *aluno = consultarAlunoMat(lista, 2);
    printf("-> Consulta por Matricula:\n");
    printf("Aluno de Matricula 2: %s\n\n", aluno->nome);

    // Alternativa B
    struct aluno *aluno2 = consultarAlunoPos(lista, 2);
    printf("-> Consulta por Posicao:\n");
    printf("Aluno de Posicao 2: %s\n\n", aluno2->nome);
    
    libera_lista(lista);    

    return 0;
}

/*
    Criei uma lista, inseri 4 alunos dentro, e para a:

    - Alternativa A: Chamei a função "consultarAlunoMat", onde passo a lista e o número
    de mátricula como parâmetro, assim, percorrendo por dentro da lista procurando pela
    mátricula.

    - Alternativa A: Chamei a função "consultarAlunoPos", onde passo a lista e o posição
    na lista como parâmetro, assim, percorrendo por dentro da lista, com ajuda de um contador
    para verificar a posição atual com a solicitada.
*/