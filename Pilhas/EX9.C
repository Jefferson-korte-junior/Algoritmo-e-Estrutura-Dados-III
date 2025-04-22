#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Função para exibir o menu
void menu() {
    printf("1 - Inicializa pilha.\n");
    printf("2 - Verifica se a pilha esta vazia.\n");
    printf("3 - Verifica se a pilha esta cheia.\n");
    printf("4 - Empilha o elemento na pilha.\n");
    printf("5 - Desempilha elemento da pilha.\n");
    printf("6 - Le o topo da pilha.\n");
    printf("7 - Converte um numero decimal em binario.\n");
    printf("8 - Sair.\n");
    printf("--------------------------------------------------\n");
}

int main() {
    Pilha *pilha = NULL;
    int opcao, valor;

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                pilha = criarPilha();
                if (pilha != NULL)
                    printf("Pilha inicializada com sucesso!\n");
                else
                    printf("Erro ao criar pilha.\n");
                break;

            case 2:
                if (vazia(pilha))
                    printf("A pilha esta vazia.\n");
                else
                    printf("A pilha nao esta vazia.\n");
                break;

            case 3:
                printf("A pilha nao possui limite maximo, entao nao pode ser verificada como cheia.\n");
                break;

            case 4:
                printf("Digite um elemento para empilhar: ");
                scanf("%d", &valor);
                if (push(pilha, valor))
                    printf("Elemento %d empilhado com sucesso!\n", valor);
                else
                    printf("Erro ao empilhar elemento.\n");
                break;

            case 5:
                if (pop(pilha, &valor))
                    printf("Elemento %d desempilhado com sucesso!\n", valor);
                else
                    printf("Erro ao desempilhar elemento ou pilha vazia.\n");
                break;

            case 6:
                if (pilha != NULL && pilha->celulaTopo != NULL)
                    printf("Topo da pilha: %d\n", pilha->celulaTopo->valor);
                else
                    printf("Erro ao acessar topo ou pilha vazia.\n");
                break;

            case 7: {
                printf("Digite um numero decimal para converter em binario: ");
                scanf("%d", &valor);
                Pilha *binario = criarPilha();
                
                while (valor > 0) {
                    push(binario, valor % 2);
                    valor /= 2;
                }

                printf("Numero binario equivalente: ");
                while (!vazia(binario)) {
                    pop(binario, &valor);
                    printf("%d", valor);
                }
                printf("\n");

                destroy(binario);
                break;
            }

            case 8: 
                printf("Saindo do programa...\n");
                break;
            

            default:
                printf("Opcao invalida! Escolha entre 1 e 8.\n");
        }

        printf("\n");

    } while (opcao != 8);

    destroy(pilha);
    return 0;
}

//Realizado em dupla: Jefferson korte junior e bruno alcantara

//Aqui apenas criei um menu e um do While para ele apenas sair quando o usario digitar o botao correto, e o resto das funcionalidades ja estavam criadas no meu arquivo pilha.h, entao basicamente apenas chamei as funçoes que ja estavam implementadas.

//Apenas tive que criar a funcionalidade sobre o botao 7, que é para converter para numero decimal para binario.