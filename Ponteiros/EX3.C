#include <stdio.h>

int main() {
    
int x, *p, **q;
p = &x;
q = &p;
x = 10;

printf("\n%d\n", **q);

 return(0);
}

//Unica coisa que mudei nesse codigo foi a forma que o printf estava sendo usado, da menera que estava : printf("\n%d\n", &q) estava sendo imprimido na tela o endereço de q, e não o valor que ele estava apontando.

//Para arrumar basta colocar **q ao invez de &q, que ele vai imprimir o valor que o ponteiro esta apontando 

