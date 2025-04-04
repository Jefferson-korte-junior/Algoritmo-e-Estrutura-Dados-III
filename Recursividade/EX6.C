#include <stdio.h>

int mdc(int n1, int n2) {
    if (n2 == 0) {
        return n1;
    }
    return mdc(n2, n1 % n2);
}

int main() {
    int n1, n2;
    
    printf ("------------------------------------------------------------------------------\n");
    printf("Digite um numeros inteiros: ");
    scanf(" %d", &n1);
    printf("Digite um numeros inteiros: ");
    scanf(" %d", &n2);
    printf ("\n------------------------------------------------------------------------------\n");
    printf("O maximo divisor comum: %d", mdc(n1, n2));
    printf ("\n------------------------------------------------------------------------------\n");

    return 0;
}
/* Dupla Jefferson Korte e igor Marchi 

//O usuario deve digitar dois numeros para encontrar o maximo divisor comum entre eles
na função vai dividir n1 / n2 e pegar o resto que será o valor do n1, para chegar no maximo comum
o resto tem que chegar no zero que é quando chegar nesse momento que vai entregar o valor que é desejado encontrar*/