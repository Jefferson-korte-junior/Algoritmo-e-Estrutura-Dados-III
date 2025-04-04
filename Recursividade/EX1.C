#include <stdio.h>

void numInvert(char* num){
    if (num[0] != '\0'){
        numInvert(&num[1]);
        printf("%c", num[0]);
    }
}

int main(){
    char num[30];
    printf("Digite um numero: ");
    scanf(" %[^\n]", num);
    printf("Numero invertido: ");
    numInvert(&num[0]);
    return 0;
}

//Dupla Jefferson korte junior e Igor Marchi

//A logica usada nsse codigo foi, usuário deve digitar um número que sera armazenado em uma string
//onde a função vai printar ela ao contrário, de forma que vai printando começando pelo vetor final até o inicial