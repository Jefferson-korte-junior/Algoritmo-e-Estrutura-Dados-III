#include <stdio.h>
#include <stdlib.h>

int contNumeroN(char *num, char n, int i) {
    if (num[i] == '\0')
        return 0;
    
    int count = 0;
    if (num[i] == n) {
        count = 1;
    }
    return count + contNumeroN(num, n, i + 1);
}

int main(){
    char num[30], n;
    printf("Digite um numero: ");
    scanf(" %[^\n]", num);
    printf("Digite um numero que deseja saber quantas vezes apareceu dentro do numero anterior: ");
    scanf(" %c", &n);
    printf("Quantidades de vezes que apareceu o numero %c: %d", n, contNumeroN(&num[0], n, 0));
    return 0;
}
/* Dupla Jefferson Korte e igor Marchi
 
Vai digitar o valor em uma string e depois o nuemro que deseja conferir, dentro da função
ele vai percorrer até ler todos o numeros e vai verficar se o nmumero que deseja conferir tem no vetor(dos nuemros que digitou)
caso tenha então vai somar 1 ao contardor e depois de percorrer a string inteira vai returnar a quantidade de vezes que apareceu*/
