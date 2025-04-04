#include <stdlib.h>
#include <stdio.h>

int somatorio(int n, int k){
    if (n == 0){
        return 1;
    }else {
        return k * somatorio(n-1, k);
    }
}

int main(){
    int n, k;

    printf ("----------------------------\n");
    printf ("Digite o valor de K: ");
    scanf ("%d", &k);
    printf ("Digite o valor de N: ");
    scanf ("%d", &n);
    printf ("----------------------------\n");
    printf ("-------------------------------------------\n");
    printf ("Resuyltado do Somatorio de K elevado a N: %d\n", somatorio(n, k));
    printf ("-------------------------------------------\n");
    
    return 0;
}

//Dupla Jefferson korte junior e Igor Marchi

//Neste codigo criei uma função recursiva para calcular K elevado a N, a logica do caso base eu utilizei se N == 0, retorna 1 pois qual quer numero elevado a 0 é 1, caso nao for retorna K * a função, so que dai passando N como N - 1, e K como K, assim ele vai multiplicando K por ele mesmo N vezes.
