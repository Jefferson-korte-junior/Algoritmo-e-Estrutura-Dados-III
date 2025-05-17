#include <stdio.h>
#include <stdlib.h>

#include "ListaDinEncad.h"
#include "ListaDinEncad.c"

int main () {

    char nome[15];

    struct aluno al[] = {
        {1, "Joao", 7.5, 8.9, 9.0},
        {2, "Maria", 6.5, 7.0, 8.0},
        {3, "Joao", 5.5, 6.0, 7.0},
        {4, "Ana", 9.5, 10.0, 9.0},
        {5, "Joao", 8.5, 9.0, 8.0}
    };

    Lista *li = cria_lista();
    for (int con = 0; con < 5; con++) {
        insere_lista_ordenada(li, al[con]);
    }

    imprime_lista(li);
    printf ("--------------------------------\n\n\n");

    printf ("Qual nome repetido voce quer buscar e elimina? : \n" );
    scanf ("%s", &nome);
    printf ("--------------------------------\n");

    int removidos = removeRepetidos(li, al[0], nome);
    if (removidos > 0) {
        printf ("Removido %d aluno(s) com o nome %s\n\n\n", removidos, nome);
    } else {
        printf ("Nenhum aluno encontrado com o nome %s\n", nome);
    }

    printf ("\n--------------------------------\n");
    printf ("Lista apos remocao:\n");
    imprime_lista(li);
    printf ("--------------------------------\n");

    return 0;
}

//Feito em Dupla Jefferson korte junior RA 2651114 & Bruno eduardo RA: 26677156

//Primeiro criamos um ponteiro ant e um atual para ajudar a manipular a lista. Depois um WHILE para varrer a lista. e ja fiz uma verificação para ver se o nome atual da lista era igual ao nome que o usuario deu para nos procurarmos. Dentro dessa verificação tem mais uma para ver se o ant é NULL assim sendo o primeiro elemento da nossa lista, caso nao for o nosso ant-prox vai receber o nosso atual->prox assim pulando o nosso atual que é o nome que buscamos.

//Apois isso apens criamos mais um ponteiro temporario para guardar o atual depois o atual recebe atual->prox e liberamos o temporario.

//Assi no final removendo todos os alunos com o nome que o usuario passou para nois.