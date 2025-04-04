#include <stdio.h>
#include <stdlib.h>

void ordemInversa(char* cptr, char s[], int tamanho){
    cptr = (char*) malloc(tamanho * sizeof(char));
    if (cptr == NULL) {
        printf("Nao foi possivel alocar a alocar memória.\n");
        return;
    }

    for ( int con = 0; con < 10; con++){
        cptr[con] = s[10-con-1];
    }

    printf ("------------------------------\n");
    printf ("A string invertida eh: ");
    for (int con = 0; con < tamanho; con++){
        printf ("%c", cptr[con]);
    }
    printf ("\n------------------------------\n");


}

int main (){

    char s[10] = "abcde";
    char* cptr;
    int tamanho = sizeof(s)/sizeof(s[0]);

    printf ("------------------------------\n");
    printf ("A string original eh: ");
    for (int con = 0; con < tamanho; con++){
        printf ("%c", s[con]);
    }
    printf ("\n------------------------------\n");

    ordemInversa(cptr, s, tamanho);

    free(cptr);

    return 0;
}