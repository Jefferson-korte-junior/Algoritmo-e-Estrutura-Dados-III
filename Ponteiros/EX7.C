#include <stdio.h>
#include <stdlib.h>

struct Produto{
    char nome[50];
    int codigo;
    float preco;
};

void cadastrarProduto(struct Produto* produtos, int quantidade){
    for (int con = 0; con < quantidade; con++){
        printf ("------------------------------\n");
        printf ("Produto %d\n", con + 1);
        printf ("------------------------------\n");
        printf ("Digite o nome do produto : ");
        scanf ("%s", produtos[con].nome);
        printf ("Digite o codigo do produto : ");
        scanf ("%d", &produtos[con].codigo);
        printf ("Digite o preco do produto : ");    
        scanf ("%f", &produtos[con].preco);
        printf ("\n------------------------------\n");
    }

    system("cls");
}

void listaProduto(struct Produto* produtos, int quantidade){
    printf ("------------------------------\n");
    printf ("Lista de produtos\n");
    printf ("------------------------------\n");
    for (int con = 0; con < quantidade; con++){
        printf ("Produto %d\n", con + 1);
        printf ("Nome: %s\n", produtos[con].nome);
        printf ("Codigo: %d\n", produtos[con].codigo);
        printf ("Preco: %.2f\n", produtos[con].preco);
        printf ("------------------------------\n");
    }
}

void consultarProdutos(struct Produto* produtos, int quantidade){
    int codigo;
    printf ("------------------------------\n");
    printf ("Consultar produto\n");
    printf ("------------------------------\n");
    printf ("Digite o codigo do produto : ");
    scanf ("%d", &codigo);
    
    for (int con = 0; con < quantidade; con++){
        if (produtos[con].codigo == codigo){
            printf ("Produto encontrado!\n");
            printf ("Nome: %s\n", produtos[con].nome);
            printf ("Codigo: %d\n", produtos[con].codigo);
            printf ("Preco: %.2f\n", produtos[con].preco);
            return;
        }
    }
    printf ("Produto nao encontrado!\n");
}


int main(){
    struct Produto* produtos;
    int opcao;
    int quantidade;

    printf ("------------------------------\n");
    printf ("Quantos produtos deseja cadastrar : ");
    scanf ("%d", &quantidade);
    system("cls");

    produtos = (struct Produto*) malloc(quantidade * sizeof(struct Produto));
    if (produtos == NULL) {
        printf("Nao foi possivel alocar memória.\n");
        return 1; 
    }

    while (opcao != 4) {
        printf ("------------------------------\n");
        printf ("Cadastro de produtos\n");
        printf ("------------------------------\n");
        printf ("[1] Cadastrar produto\n");
        printf ("[2] Listar produtos\n");
        printf ("[3] Consultar Produto\n");
        printf ("[3] Sair\n");
        printf ("------------------------------\n");
        printf ("Escolha uma opcao: ");
        scanf ("%d", &opcao);

        if (opcao == 1){
            cadastrarProduto(produtos, quantidade);
        } else if (opcao == 2){
            listaProduto(produtos, quantidade);
        } else if (opcao == 3){
            consultarProdutos(produtos, quantidade);
        } else if (opcao == 4){
            printf ("Saindo...\n");
        }else {
            printf ("Opcao invalida!\n");
        }
    }

        free(produtos);
        printf ("------------------------------\n");

    return 0;
}

//Aqui eu comecei criando primeiro  struct produtos com suas variaveis, logo apos fiz uma alocação dinamica pra o vetor de produtos, fiz um pequeno menu para o usuario digitar a opção que ele quer, assim entrando dentro de um IF e chamando a função dai assim cadastrando o produto, listando o produto ou consultando o produto.

//A logica que usei na função cadastrar produto, fiz um loop para pedir as informaçoes do produto, usando o scanf produtos[con].nome, produtos[con].codigo e produtos[con].preco, assim pegando o valor digitado pelo usuario e armazenando na variavel do produto.

