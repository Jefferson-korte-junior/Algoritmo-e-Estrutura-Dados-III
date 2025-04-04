#include <stdio.h>

void numerosPares (int n){
    if (n >= 0){
        if (n % 2 == 0){
            printf("%d ", n);
        }
        numerosPares(n - 1);
    }
}

int main() {
    int n;

    printf ("------------------------------------------\n");
    printf ("Digite um numero inteiro: ");
    scanf("%d", &n);
    printf ("------------------------------------------\n");

    printf ("Numeros pares de %d a 0 em ordem decrecente: ", n);
    numerosPares(n);
    printf ("\n------------------------------------------\n");

    return 0;
}
//Dupla Jefferson korte junior e Igor Marchi

//A logica que usei foi se o  N >= 0, oque sera verdade ate certo ponto. dai a função entra em mais uma verificação, caso o o numero seja par imprimo ele na tela e depois chamo a função novamente passando N como N - 1, caso ele nao seja par apenas chamo a função novamente passando N como N - 1, assim so imprimira os numeros pares de N ate 0.