#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"
#include "pilha.h"

int main() {
    
    Fila* fi = cria_Fila();


    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                            {4,"Ricardo",7.5,8.7,6.8},
                            {1,"Bianca",9.7,6.7,8.4},
                            {3,"Ana",5.7,6.1,7.4}};

    for (int con = 0; con < 4; con++){
        insere_Fila(fi, a[con]);
    }
    
    printf ("---------------------------------------------\n");
    printf ("Fila original: \n");
    imprime_Fila(fi);

    printf ("\n---------------------------------------------\n");
    printf ("Fila inversa: \n");

    inverte_Fila(fi);

    libera_Fila(fi);


    return 0;
}
