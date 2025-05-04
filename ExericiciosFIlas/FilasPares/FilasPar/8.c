// Feito em dupla por "Bruno Eduardo Santos Alcantara" RA: 2677156 & "Jefferson Korte Junior" RA: 2651114.

#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

int main() {
    int sair = 0;
    int menu = 0;
    float valor = 0.0;
    FilaCircular *filaCircular;
    while (sair == 0) {
        printf("------------------------------------------\n");
        printf("                 Fila Menu\n");
        printf("------------------------------------------\n");
        printf("[1] - Criar fila.\n");
        printf("[2] - Verificar se a fila esta vazia.\n");
        printf("[3] - Verificar se a fila esta cheia.\n");
        printf("[4] - Enfileira o elemento na fila.\n");
        printf("[5] - Desenfileira o elemento na fila.\n");
        printf("[6] - Le o numero no inicio da fila.\n");
        printf("[7] - Testar qual fila possui mais elementos.\n");
        printf("[8] - Furar a fila.\n");
        printf("[9] - Sair.\n");
        scanf("%d", &menu);
        system("cls");
        switch(menu) {
            case 1:
                filaCircular = criarFilaCircular();
                if (filaCircular != NULL) printf("\n-> Fila criada com sucesso!\n\n");
                break;
            case 2:
                if (filaCircular == NULL || filaCircular->inicio == NULL) {
                    printf("\n-> A fila esta vazia ou nao foi criada!\n\n");
                } else {
                    printf("\n-> A fila nao esta vazia!\n\n");
                }
                break;
            case 3:
                printf("\n-> A fila nao possui limite, ao nao ser quando acabe a memoria!\n\n");
                break;
            case 4:
                system("cls");
                printf("\n> Digite o elemento(float):\n");
                scanf("%f", &valor);
                system("cls");
                if (inserirFilaCircular(filaCircular, valor)) {
                    printf("\n-> %.2f adicionado a fila!\n\n", valor);
                } else {
                    printf("\n-> Nao foi possivel adicionar %.2f na fila!\n\n", valor);
                }
                break;
            case 5:
                if (filaCircular != NULL) valor = filaCircular->final->valor;
                if (removerFilaCircular(filaCircular)) {
                    printf("\n-> %.2f desenfileirado!\n", valor);
                } else {
                    printf("\n-> Nao foi possivel desenfileirar!\n\n");
                }
                break;
            case 6:
                if (consultarFilaCircular(filaCircular, &valor)) {
                    printf("\n-> Inicio da fila: %.2f\n\n", valor);
                } else {
                    printf("\n-> Nao foi possivel consultar a fila!\n");
                }
                break;
            case 7:
               printf("\n-> A primeira e unica!\n");
               break;
            case 8:
                if (filaCircular == NULL || filaCircular->inicio == NULL) {
                    printf("\n-> A fila ainda nao foi criada!\n");
                    break;
                }
                system("cls");
                printf("\n> Digite o elemento(float):\n");
                scanf("%f", &valor);
                system("cls");
                if (furarFilaCircular(filaCircular, valor)) {
                    printf("\n-> %.2f adicionado ao inicio da fila!\n\n", valor);
                } else {
                    printf("\n-> Nao foi possivel adicionar %.2f ao inicio da fila!\n\n", valor);
                }
                break;
            case 9:
                printf("\n-> Saindo...\n\n");
                sair = 1;
                break;
            default:
                printf("\n-> Opcao invalida!\n\n");
        }
        if (sair != 1) system("pause && cls");
    }

    liberarFilaCircular(filaCircular);
    return 0;
}

/*
    Fiz um menu simples, a que o numero que o usuário digitar, chamar a cada determinada
    função, a qual exige algumas verificações antes de chamar as funções devido a poder 
    resultar em erro.
*/
