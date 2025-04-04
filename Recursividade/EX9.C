#include <stdio.h>

void imprimindo (int n, int i) {
    if (n >= 0) {
        if (i % 2 == 0) {
            printf ("%d ", i);
            imprimindo(n - 1, i + 1);
        }else {
            imprimindo(n - 1, i + 1);
        }
    }
}

int main() {
    int n = 10;
    int i = 0;

    imprimindo(n, i);
    
    return 0;
}
//Dupla Jefferson korte junior e Igor Marchi

//A logica nesse exericico é enquanto o N for maior ou igual a zero ele continua entrando no SE, que tem outro SE pra ve se o numero é par ou nao usando o resto da divisao. Indiferente o numero sendo ou nao par eu chamo a função novamente passando N - 1, e I que verifica se o numero é par ou nao como I + 1.
