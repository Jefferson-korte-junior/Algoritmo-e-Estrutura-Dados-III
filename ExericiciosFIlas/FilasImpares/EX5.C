#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

int main() {

    int opcao; 

    struct aviao av[4] = {
        {1, "grande", "AVR"},
        {2, "Pequeno", "INTERAVEATOR"},
        {3, "Gigante", "BRAEUR"}
    };

    FilaAviao* filaAvioes = cria_FilaAviao();

    for (int con = 0; con < 3; con++) {
        insere_FilaAviao(filaAvioes, av[con]);
    }

    do {
        printf ("------------------------------------------------------------------\n");
        printf ("M E N U \n");
        printf ("[1] - N de avioes na fila de decolagem: \n");
        printf ("[2] - Autorizar decolagem do primro aviao da fila: \n");
        printf ("[3] - Adicionar aviao a fila de espera: \n");
        printf ("[4] - Listar todos os avioes na fila de espera: \n");
        printf ("[5] - Listar as caracteristicas do primeiro aviao da fila: \n");
        printf ("[6] -  S A I R.. \n");
        printf ("-------------------------\n");
        printf ("R : ");
        scanf ("%d", &opcao);
        printf ("------------------------------------------------------------------\n");

        if (opcao == 1) {
            printf ("------------------------------------------------------------------\n");
            printf("numero de avioes aguardando na fila de decolagem: %d \n", contar_Avioes(filaAvioes));
            printf ("------------------------------------------------------------------\n");
        } else if (opcao == 2) {
            printf ("------------------------------------------------------------------\n");
            printf("Autorizando decolagem do primeiro aviao da fila: \n");
            remove_FilaAviao(filaAvioes);
            printf ("------------------------------------------------------------------\n"); 
        } else if (opcao == 3) {
            printf ("------------------------------------------------------------------\n");
            printf ("Vamos adicionar um aviao a fila de espera: \n");
            struct aviao novoAviao;

            printf ("Digite o ID do novo aviao: ");
            scanf ("%d", &novoAviao.id);
            getchar(); //Limpa o buffer de entrada

            printf ("DIgite o tamanho do novo aviao: ");
            scanf ("%s", novoAviao.tamanho);

            printf ("Digite o modelo do novo aviao: ");
            scanf ("%s", novoAviao.modelo);

            insere_FilaAviao(filaAvioes, novoAviao);
            printf ("Concluido com sucesso! \n");
            printf ("------------------------------------------------------------------ \n");
        } else if (opcao == 4) {
            printf ("------------------------------------------------------------------\n");
            printf ("Todos os avioes na fila de espera: \n");
            imprime_FilaAviao(filaAvioes);
            printf ("------------------------------------------------------------------\n");
        } else if (opcao == 5) {
            printf ("------------------------------------------------------------------\n");
            printf ("Caracteristcas do primeiro aviao da fila: \n");
            printf ("ID: %d\n",filaAvioes->inicio->dados.id);
            printf ("Tamanho: %s\n",filaAvioes->inicio->dados.tamanho);
            printf ("Modelo: %s\n",filaAvioes->inicio->dados.modelo);
            printf ("------------------------------------------------------------------\n");
        }

    } while (opcao != 6);

    libera_FilaAviao(filaAvioes);

    return 0;
}

//Feito em dupla: Jefferson korte RA 2651114 E Bruno E. S alcantara RA: 2677156

//Tive que criar todas as funçoes que o exercicio pedia, para fazer essas funçoes me baseiei nas funçoes de fila aluno que ja tinham promtas. Logo apos fiz um menu para o "usuario" poder escolher oque ele quer. E coloquei um IF para cada opcao do menu. e tambem adicionei um do while para so sair do menu quando o usuario digitar a opcao especifica.