#include <stdio.h>

void numeroNaturais (int n){
    if (n >= 0){
        printf ("%d ", n);
        numeroNaturais(n -1);
    }
}

int main() {

    int n = 20;

    printf ("-----------------------------------------------------\n");
    printf ("Os numeros naturais de 0 a %d em ordem decrecente sao: ", n);
    numeroNaturais(n);
    printf ("\n-----------------------------------------------------\n");

    return 0;
}
//Dupla Jefferson korte junior e Igor Marchi

//A logica que usei foi se o  N >= 0, oque sera verdade. Vai imprimir o N e depois chamo a fução novamente so que dai passando N como N -1, assim imprimi de N ate 0.
