#include <stdio.h>
#include <stdlib.h>

#include "lista.c"

int main() {

    struct aluno alunos1[4] = {
        {1, "Jefferson", 9.7, 6.7, 8.4},
        {2, "Bruno", 9.5, 7.8, 8.5},
        {3, "Marciano", 5.7, 6.1, 7.4},
        {4, "Igor", 7.5, 8.7, 6.8}
    };

    struct aluno alunos2[4] = {
        {5, "Jose", 9.7, 6.7, 8.4},
        {6, "Igor", 5.7, 6.1, 7.4},
        {7, "Gabriel", 7.5, 8.7, 6.8},
        {8, "Gustavo", 7.5, 8.7, 6.8}
    };

    Lista *lista1 = cria_lista();
    Lista *lista2 = cria_lista();

    for (int i = 0; i < 4; i++) {
        insere_lista_final(lista1, alunos1[i]);
        insere_lista_final(lista2, alunos2[i]);
    }

    Lista *lista3 = concatenar(lista1, lista2);

    imprime_lista(lista3);

    libera_lista(lista1);
    libera_lista(lista2);
    libera_lista(lista3);

    return 0;
}

/*
    Crio dois vetores com 4 alunos cada, após isso, duas listas, em seguida preencho a lista 1
    com o vetor 1, e a lista 2 com o vetor 2, assim chamando a função concatenar passando as
    duas listas como parâmetro, onde na função ele roda cada lista, inserindo seus valores na 
    terceira lista, assim retornando para a lista3, concluindo, imprimo a lista para mostrar
    o conteudo das duas listas agora em uma só e ao final libero a memória da lista.
*/