#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include "prototipos_pilha.h"

#define A 65
#define B 66

/*
    Cria a pilha:
*/
Pilha* criarPilha() {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    if (pilha == NULL) return NULL; 
    pilha->celulaTopo = NULL;
    return pilha;
}

/*
    Retira o elemento da pilha:
*/
int pop(Pilha *pilha, int *valor) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->celulaTopo;
    if (celula == NULL) return 0;
    *valor = pilha->celulaTopo->valor;
    pilha->celulaTopo = celula->proxCelula;
    free(celula);
    return 1;
}

/*
    Coloca o elemento da pilha:
*/
int push(Pilha *pilha, int valor) {
    if (pilha == NULL) return 0;
    Celula *celula = (Celula *)malloc(sizeof(Celula));
    if (celula == NULL) return 0;
    celula->valor = valor;
    celula->proxCelula = pilha->celulaTopo;
    pilha->celulaTopo = celula;
    return 1;
}

/*
    Obtem o tamanho da pilha:
*/
int size(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->celulaTopo;
    int size = 0;
    while (celula != NULL) {
        size++;
        celula = celula->proxCelula;
    }
    return size;
}

/*
    Libera a memória de toda a pilha:
*/
int clear(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->celulaTopo;
    while(celula != NULL) {
        Celula *aux = celula;
        celula = celula->proxCelula;
        free(aux);
    }
    pilha->celulaTopo = NULL;
    return 1;
}

/*
    Imprime os valores da pilha:
*/
int print(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->celulaTopo;
    while (celula != NULL) {
        printf("-> %d\n", celula->valor);
        celula = celula->proxCelula;
    }
    return 1;
}

/*
    Verifica se a pilha esta vazia:
*/
int vazia(Pilha *pilha) {
    if (pilha == NULL) return 1;
    if (pilha->celulaTopo == NULL) return 1;
    return 0;
}

/*
    Libera a memória de toda a pilha:
*/
int destroy(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->celulaTopo;
    while(celula != NULL) {
        Celula *aux = celula;
        celula = celula->proxCelula;
        free(aux);
    }
    pilha->celulaTopo = NULL;
    return 1;
}


//-----------------------------------------------------
//EXERCICIO 1
//-----------------------------------------------------

int pop2(Pilha *pilha, int *valores) {
    if (pilha == NULL) return 0;
    if (size(pilha) < 2) return 0;
    if (valores == NULL) return 0;
    Celula *Celula;
    for (int con = 0; con < 2; con++){
        Celula = pilha->celulaTopo;
        valores[con] =  pilha->celulaTopo->valor;
        pilha->celulaTopo = Celula->proxCelula;
        free(Celula);
    }

    return 1;
    
}

int push2(Pilha *pilha, int *valores) {
    if (pilha == NULL) return 0;
    for (int con = 0; con < 2; con++){
        Celula *celula = (Celula *)malloc(sizeof(Celula));
        if (celula == NULL) return 0;
        celula->valor = valores[con];
        celula->proxCelula = pilha->celulaTopo;
        pilha->celulaTopo = celula;
    }
    return 1;
}


//-----------------------------------------------------
//EXERCICIO 2
//-----------------------------------------------------

int popN (Pilha *pilha, int *valores, int n) {
    if (pilha == NULL) return 0;
    if (size(pilha) < n) return 0;
    if (valores == NULL) return 0;
    Celula *Celula;
    for (int con = 0; con < n; con++){
        Celula = pilha->celulaTopo;
        valores[con] =  pilha->celulaTopo->valor;
        pilha->celulaTopo = Celula->proxCelula;
    }
}


//-----------------------------------------------------
//EXERCICIO 3
//-----------------------------------------------------


void copiaPilha(Pilha *pilha, Pilha *copia){
    if (pilha == NULL) return;

    while (size(pilha) > 0){
        int ultimoElemento; //Crio uma variavel para armazzenarar o ultimo elemento da pilha
        if (pop(pilha, &ultimoElemento)) { //retiro o ultimo elemento da pilha
            push (copia, ultimoElemento); //Coloco o ultimo elemento da pulha original na pilha copia
        }; 
       
    }

}

//-----------------------------------------------------
//EXERCICIO 4
//-----------------------------------------------------
int maiorValor (Pilha *pilha) {
    int maior = 0;
    if (pilha == NULL) return 0;
    
    while (size(pilha) > 0){
        int ultimoElemento;
        pop(pilha, &ultimoElemento);
        if (ultimoElemento > maior) {
            maior = ultimoElemento;
        }
    }
    
    return maior;
}

int menorValor (Pilha *pilha) {
    int menor = pilha->celulaTopo->valor;
    if (pilha == NULL) return 0;
    
    while (size(pilha) > 0){
        int ultimoElemento;
        pop(pilha, &ultimoElemento);
        if (ultimoElemento < menor) {
            menor = ultimoElemento;
        }
    }
    
    return menor;
}

float media (Pilha *pilha) {
    float soma = 0;
    float media = 0;
    int cont = 0;
    if (pilha == NULL) return 0;
    
    while (size(pilha) > 0){
        int ultimoElemento;
        pop(pilha, &ultimoElemento);
        soma += ultimoElemento;
        cont++;
    }
    
    media = soma / cont;
    return media;
}

//-----------------------------------------------------
//EXERCICIO 5
//-----------------------------------------------------

void pilhasIguais (Pilha *pilha1, Pilha *pilha2) {
    if (pilha1 == NULL || pilha2 == NULL) return;
    if (size(pilha1) != size(pilha2)) return;
    
    while (size(pilha1) > 0 && size(pilha2) > 0){
        int ultimoElemento1, ultimoElemento2;
        pop(pilha1, &ultimoElemento1);
        pop(pilha2, &ultimoElemento2);
        if (ultimoElemento1 != ultimoElemento2) {
            printf("As pilhas sao diferentes\n");
            return;
        }
    }
    printf("As pilhas sao iguais\n");
}

//-----------------------------------------------------
//EXERCICIO 6
//-----------------------------------------------------

int printc(Pilha *pilha) {
    if (pilha == NULL) return 0;
    Celula *celula = pilha->celulaTopo;
    while (celula != NULL) {
        printf("%c", celula->valor);
        celula = celula->proxCelula;
    }
    printf("\n");
    return 1;
}

//-----------------------------------------------------
//EXERCICIO 7
//-----------------------------------------------------

int countPar(Pilha *pilha) {
    if (vazia(pilha)) return 0;
    int totalPares = 0;
    Celula *celula = pilha->celulaTopo;
    while (celula != NULL) {
        if (celula->valor % 2 == 0) totalPares++;
        celula = celula->proxCelula;
    }
    return totalPares;
}

int countImpar(Pilha *pilha) {
    if (vazia(pilha)) return 0;
    int totalImpares = 0;
    Celula *celula = pilha->celulaTopo;
    while (celula != NULL) {
        if (celula->valor % 2 != 0) totalImpares++;
        celula = celula->proxCelula;
    }
    return totalImpares;
}

//-----------------------------------------------------
//EXERCICIO 7
//-----------------------------------------------------

Pilha* inverterAB(Pilha *pilha) {
    if (vazia(pilha)) return NULL;
    Pilha *pilhaInvertida = criarPilha();
    Pilha *pilhaAB = criarPilha();
    Celula *celula = pilha->celulaTopo;
    while (celula != NULL) {
        if (celula->valor == A) {
            push(pilhaInvertida, B);
        } else {
            push(pilhaInvertida, A);
        }
        celula = celula->proxCelula;
    }
    celula = pilhaInvertida->celulaTopo;
    while (celula != NULL) {
        push(pilhaAB, celula->valor);
        celula = celula->proxCelula;
    }
    destroy(pilhaInvertida);
    return pilhaAB;
}

int xCy(Pilha *pilhaX, Pilha *pilhaY) {
    if(vazia(pilhaX)) return 0;
    if(vazia(pilhaY)) return 0;
    Pilha *pilhaVf = inverterAB(pilhaX);
    if (vazia(pilhaVf)) return 0;
    Celula *celulaVf = pilhaVf->celulaTopo;
    Celula *celulaY = pilhaY->celulaTopo;
    while (celulaVf != NULL && celulaY != NULL) {
        if (celulaVf->valor != celulaY->valor) return 0;
        celulaVf = celulaVf->proxCelula;
        celulaY = celulaY->proxCelula;
    }
    destroy(pilhaVf);
    return 1;
}





#endif