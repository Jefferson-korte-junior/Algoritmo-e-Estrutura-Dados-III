//2) Escreva um comentário em cada comando de atribuição explicando o que 
//ele faz e o valor da variável à esquerda do '=' após sua execução.


#include <stdio.h> //Adicionei se nao o codigo nao rodava por conta do printf

int main() {
int y, *p, x; 

y = 0; //y recebe 0
p = &y; //P recebe o endereço de y
x = *p; //X recebe o valor de y, que é 0
(*p)++; //O valor de Y é incrementado em 1, então y = 1
x = 4; //X recebe 4

(*p)++; //Icrementa o valor no endereço apontado, entao Y = 2
x--; //Aqui X é decrementado entao passa a ter valor 3
(*p) += x; //Aqui o valor de Y que P esta apontando é incrementado a X que vale 3, entao Y = 5

printf ("y = %d\n", y); //Aqui imprime o valor de y que é 5

return(0);
}