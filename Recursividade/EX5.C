#include <stdio.h>

int inverte (int vetor[], int inicio, int fim){
    if (inicio < fim){
        int temporario = vetor[inicio];
        vetor[inicio] = vetor[fim];
        vetor[fim] = temporario;
        inverte(vetor, inicio + 1, fim - 1);
    }

}


int main(){
    int vetor [100];
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    for (int i = 0; i < 100; i++){
        vetor[i] = i + 1;
    }

    printf ("-----------------------------------------------------------------------------------\n");
    printf ("Vetor orignal: \n");
    for (int i = 0; i < 100; i++){
        printf ("%d ", vetor[i]);
    }
    printf ("\n-----------------------------------------------------------------------------------\n");


    inverte (vetor, 0, tamanho - 1);
    printf ("-----------------------------------------------------------------------------------\n");
    printf ("Vetor invertido: \n");
    for (int i = 0; i < 100; i++){
        printf ("%d ", vetor[i]);
    }
    printf ("\n-----------------------------------------------------------------------------------\n");


    return 0;
}

//Dupla Jefferson korte junior e Igor Marchi

//A minha logica usada para inverte o vetor foi a seguinte: enquanto o caso base for verdade uma variavel temporaria vai pega o valor INICIAL, e a posição INICIAL vai receber a posição FINAL, e a posição FINAL vai recebe a variavel temporaria que esta com o valor inical do vetor.

//E dai após isso chama a função novamente so que dai passando INICIO + 1 e FINAL - 1, assim vai fazendo isso até que o caso base seja falso.
