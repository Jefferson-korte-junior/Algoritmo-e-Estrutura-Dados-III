#include <stdio.h>

int multiplicacao (int n1, int n2){
    if (n2 == 0){
        return 0;
    }else {
        return n1 + multiplicacao(n1, n2 -1);
    }
}

int main() {

    int n1, n2;
    printf ("-----------------------------------------------------------------------------------\n");
    printf ("DIgite o N1: ");
    scanf ("%d", &n1);
    printf ("DIgite o N2: ");
    scanf ("%d", &n2);
    printf ("\n-----------------------------------------------------------------------------------\n");
    printf ("A multiplicacao de %d e %d eh: %d\n", n1, n2, multiplicacao(n1, n2));
    printf ("\n-----------------------------------------------------------------------------------\n");

    return 0;
}

//Dupla Jefferson korte junior e Igor Marchi

//A minha logica nesse programa foi a seguinte: Se N2 for zero, oque nao vai ser logo de cara ele retorna 0, se nao ele retorna n1 + a FUNÇÃO novamente passando n1 novamente e passando n2 - 1, ate que ele chega em 0.
