#include <stdio.h>
#include <stdlib.h>

#include "ListaDinEncad.h"
#include "ListaDinEncad.c"

int main () {

    int numero;

    struct aluno al[] = {
        {1, "Joao", 7.5, 8.0, 9.0},
        {5, "Maria", 6.5, 7.0, 8.0},
        {11, "Jose", 5.5, 6.0, 7.0},
        {4, "Ana", 9.5, 10.0, 9.0},
        {12, "Pedro", 8.5, 9.0, 8.0}
    };

    Lista *li = cria_lista();

    for (int con = 0; con < 5; con++) {
        insere_lista_ordenada(li, al[con]);
    }

    printf ("Lista original:\n");
    imprime_lista(li);
    printf ("--------------------------------\n");

    printf ("Digite uma matricula NAO negativa para retirar da lista: ");
    scanf ("%d", &numero);

    if (numero < 0) {
        printf ("Numero negativo, encerrando o programa...\n");
        return 0;
    }

    printf ("\n--------------------------------\n");

    int removidos = removeMatIgual(li, numero);
    if (removidos > 0) {
        printf ("Removido %d aluno(s) com a matricula %d\n", removidos, numero);
    } else {
        printf ("Nenhum aluno encontrado com a matricula %d\n", numero);
    }

    printf ("\n--------------------------------\n");
    printf ("Lista apos remocao:\n");
    imprime_lista(li);
    printf ("--------------------------------\n");

    libera_lista(li);


    return 0;
}

//Feito em Dupla Jefferson korte junior RA 2651114 & Bruno eduardo RA: 26677156

//A logica usada nesse exericicio foi a seguinte: primeiro fiz um WHILE para varrer a lista inteira, depois ja fiz uma verificação para ver se essa era a matricula que estamos buscando. Dentro dessa verificação tem mais uma para ver se o ant é NULL assim sendo o primeiro elemento da nossa lista, caso nao for o nosso ant-prox vai receber o nosso atual->prox assim pulando o nosso atual que é a matricula que buscamos.

//Ainda dentro da verificação para ver se achamos a matricula desejada criei um ponteiro temporario so para guardar o atual e o nosso atual recebe atual->prox e liberamos o nosso temporario.

//Caso a nossa primeira verificação nao seja a nossa matricula desejada, o nosso ant recebe o atual e nosso atual recebe o atual->prox.