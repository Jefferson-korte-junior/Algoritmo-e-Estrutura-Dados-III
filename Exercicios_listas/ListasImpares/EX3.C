#include <stdio.h>
#include <stdlib.h>

#include "ListaDinEncad.h"
#include "ListaDinEncad.c"


int main() {

    Lista *li = cria_lista();

    struct aluno al[] = {
        {1, "Joao", 7.5, 8.0, 9.0},
        {2, "Maria", 6.5, 7.0, 8.0},
        {3, "Jose", 5.5, 6.0, 7.0},
        {4, "Ana", 9.5, 10.0, 9.0},
        {5, "Pedro", 8.5, 9.0, 8.0}
    };

    for (int i = 0; i < 5; i++) {
        insere_lista_final(li, al[i]);
    }

    printf("Lista original:\n");
    printf ("--------------------------------\n");
    imprime_lista(li);

    struct aluno novo = {6, "Jefferson", 7.0, 8.0, 9.0};
    int posicao = 2;

    if (insereQualQuerLugar(li, novo, posicao)) {
        printf("\nAluno inserido com sucesso na posicao %d!\n", posicao);
    } else {
        printf("\nErro ao inserir o aluno na posicao %d.\n", posicao);
    }

    printf("\nLista apos insercao:\n");
    printf ("--------------------------------\n");
    imprime_lista(li);

    libera_lista(li);
    return 0;
}

//Feito em Dupla Jefferson korte junior RA 2651114 & Bruno eduardo RA: 26677156

//A logica usada nesse exericico foi alocar um nó na memoria, apos isso fiz com que o no->dados recebesse o aluno que queremos adicioanar, faço uma verificação para ver se a posição que o "Usuaruio" passou seja zero, pois se for ja podemos colocar esse aluno no inicio.

//Faço dois ponteiros um ant (anterior) e o atual que recebe o começo da lista, depois faço um loop para varrer a lista ate que ache o final dela ou a posição que queremos adicionar. Depois mais uma verificação para ver se a posição é mesma a certa e verifico tambem se o ant nao é NULL para conectar o novo nó a lista
