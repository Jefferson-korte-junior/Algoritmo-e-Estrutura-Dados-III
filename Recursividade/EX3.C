#include <stdio.h>
#include <stdlib.h>


int somatorio(int n){
    if(n == 1){
        return 0;
    }else{
        return n + somatorio(n-1);
    }
}

main (){
    int n = 10;

    printf ("---------------------------------\n");
    printf ("Somatorio de %d = %d\n", n, somatorio(n));
    printf ("---------------------------------\n");

    return 0;
}
////Dupla Jefferson korte junior e Igor Marchi

//Neste codigo criei uma função recursiva para calcular o somatorio de 1 ate N, entao apenas fiz o caso base como N == 1, caso verdade retorna 0 pois nao tem mais oque soma, caso contrario retorna N + a função chamando ela mesma com N - 1.