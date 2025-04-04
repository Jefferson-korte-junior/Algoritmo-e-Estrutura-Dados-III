#include <stdio.h>

int Fatorial (int n){
    if (n <= 1){
        return 1;
    }else {
         return n * Fatorial(n - 2);
    }
       
}

int main() {

    int n;

    printf ("--------------------------------------------------\n");
    printf ("Digite um numero natural impar: ");
    scanf ("%d", &n);

    if (n % 2 == 0){
        printf ("--------------------------------------------------\n");
        printf ("O numero %d nao e impar\n", n);
        printf ("--------------------------------------------------\n");
        return 0;
    }else {
        printf ("\n--------------------------------------------------\n");
         printf ("todos os numeros naturais impares de 1 ate %d sao %d: ", n, Fatorial(n));
        printf ("\n--------------------------------------------------\n");
    }

    
    
    return 0;
}

//Dupla Jefferson korte junior e Igor Marchi

//Peço au usuario para digitar um numero impar(N), e caso o numero seja par imprimo uma mensagem dizendo que o numero nao e impar, se nao chamo a função Fatorial passando N como parametro. a primiera verificação da função é se N <= 1, caso seja return 1, se nao retorna N * função Fatorial so que dai passando n como N - 2, assim so imprimira os numeros impares de N ate 1. 

