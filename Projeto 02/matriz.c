#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

void lerArquivo(Node *raiz, const char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (!fp) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), fp)) {
        // Remove \n do final, se existir
        linha[strcspn(linha, "\n")] = 0;
        if (strlen(linha) > 0) {
            inserirCaminho(raiz, linha);
        }
    }

    fclose(fp);
}

int verificaArquivo(const char *nome) {
    // Procura o caractere '.' na string
    if (strchr(nome, '.') != NULL) {
        // Se encontrar, supõe que seja arquivo
        return 1;
    }
    // Se não encontrar, é pasta
    return 0;
}

Node* criarNo(const char *nome, int arquivo) {
    Node *novo = (Node *)malloc(sizeof(Node));
    strcpy(novo->nome, nome);
    novo->arquivo = arquivo;
    novo->pai = NULL;
    novo->filho = NULL;
    novo->irmao = NULL;
    return novo;
}


void inserirCaminho(Node *raiz, const char *caminho) {
    char copia[200];
    strcpy(copia, caminho);
    char *token = strtok(copia, "/");
    Node *atual = raiz;

    while (token != NULL) {
        Node *filho = atual->filho;
        Node *anterior = NULL;
        while (filho && strcmp(filho->nome, token) != 0) {
            anterior = filho;
            filho = filho->irmao;
        }
        if (!filho) {
            filho = criarNo(token, verificaArquivo(token));
            filho->pai = atual;
            if (anterior)
                anterior->irmao = filho;
            else
                atual->filho = filho;
        }
        atual = filho;
        token = strtok(NULL, "/");
    }
}


void listarConteudo(Node *no, int nivel) {
    if (no == NULL) return;

    // Indentação para mostrar a hierarquia
    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }
    printf("%s%s\n", no->nome, no->arquivo ? "" : "/");

    // Lista os filhos (recursivamente)
    listarConteudo(no->filho, nivel + 1);

    // Lista os irmãos (no mesmo nível)
    listarConteudo(no->irmao, nivel);
}

//--------------------------------------------
//--------------------------------------------
//Funçoes sobre terminal
//--------------------------------------------
Node* comando_cd(Node *atual, const char *nome) {
    if (!nome) {
        printf("Uso correto: cd <nome_da_pasta>\n");
        return atual;
    }

    Node *filho = atual->filho;
    while (filho != NULL) {
        if (!filho->arquivo && strcmp(filho->nome, nome) == 0) {
            return filho; // pasta encontrada
        }
        filho = filho->irmao;
    }

    // Se não encontrou
    printf("cd: %s: Diretorio nao encontrado.\n", nome);
    return atual; // permanece na pasta atual
}

void comando_mkdir(Node *atual, const char *nome) {
    if (!nome || strlen(nome) == 0) {
        printf("Uso correto: mkdir <nome_da_pasta>\n");
        return;
    }

    // Verifica se já existe pasta com esse nome
    Node *filho = atual->filho;
    while (filho != NULL) {
        if (strcmp(filho->nome, nome) == 0 && filho->arquivo == 0) {
            printf("mkdir: diretorio '%s' ja existe.\n", nome);
            return;
        }
        filho = filho->irmao;
    }

    // Criar nova pasta
    Node *novo = criarNo(nome, 0);
    novo->pai = atual;

    // Adiciona como filho
    if (atual->filho == NULL) {
        atual->filho = novo;
    } else {
        Node *ultimo = atual->filho;
        while (ultimo->irmao != NULL) {
            ultimo = ultimo->irmao;
        }
        ultimo->irmao = novo;
    }

    printf("Diretorio '%s' criado com sucesso.\n", nome);
}


void comando_search(Node *raiz, const char *nome, const char *caminho) {
    if (!raiz) return;

    char novoCaminho[512];
    // Concatena o caminho atual com o nome do nó atual
    if (strcmp(raiz->nome, "/") == 0) {
        strcpy(novoCaminho, "/"); // raiz especial
    } else {
        snprintf(novoCaminho, sizeof(novoCaminho), "%s/%s", caminho, raiz->nome);
    }

    // Verifica se o nome bate
    if (strcmp(raiz->nome, nome) == 0) {
        printf("Encontrado: %s%s\n", novoCaminho, raiz->arquivo ? "" : "/");
    }

    // Busca nos filhos
    comando_search(raiz->filho, nome, novoCaminho);

    // Busca nos irmãos
    comando_search(raiz->irmao, nome, caminho);
}


void comando_rm(Node *atual, const char *nome) {
    if (!nome || strlen(nome) == 0) {
        printf("Uso correto: rm <nome>\n");
        return;
    }

    Node *filho = atual->filho;
    Node *anterior = NULL;

    while (filho) {
        if (strcmp(filho->nome, nome) == 0) {
            // Remove o filho da lista
            if (anterior == NULL) {
                atual->filho = filho->irmao;
            } else {
                anterior->irmao = filho->irmao;
            }

            liberarArvore(filho);
            printf("'%s' removido com sucesso.\n", nome);
            return;
        }

        anterior = filho;
        filho = filho->irmao;
    }

    printf("rm: %s: Arquivo ou diretorio nao encontrado.\n", nome);
}

void comando_help() {
    printf("\nComandos disponiveis:\n");
    printf("1. cd <nome>      - Entra na pasta <nome>\n");
    printf("2. search <nome>  - Busca por arquivo ou pasta chamada <nome>\n");
    printf("3. rm <nome>      - Remove um arquivo ou diretorio\n");
    printf("4. list           - Lista o conteudo da pasta atual\n");
    printf("5. mkdir <nome>   - Cria uma nova pasta chamada <nome>\n");
    printf("6. clear          - Limpa a tela\n");
    printf("7. help           - Mostra esta mensagem de ajuda\n");
    printf("8. cfif           - Conta quantos arquivos tem dentro da pasta chamada <nome>\n");
    printf("9. exit           - Encerra o programa\n");
}

void comando_clear() {
        system("cls");   // Comando para limpar tela no Windows
}


void liberarArvore(Node *no) {
    // Exemplo de liberação recursiva
    if (no == NULL) return;

    liberarArvore(no->filho);
    liberarArvore(no->irmao);
    free(no);
}

int contarArquivos(Node *pasta) {
    if (!pasta) return 0;

    int count = 0;
    Node *filho = pasta->filho;
    while (filho) {
        if (filho->arquivo == 1) {
            count++;
        } else {
            count += contarArquivos(filho);
        }
        filho = filho->irmao;
    }
    return count;
}

Node* encontrarPasta(Node *raiz, const char *nome) {
    if (!raiz) return NULL;

    if (raiz->arquivo == 0 && strcmp(raiz->nome, nome) == 0)
        return raiz;

    Node *encontrado = encontrarPasta(raiz->filho, nome);
    if (encontrado) return encontrado;

    return encontrarPasta(raiz->irmao, nome);
}

void comando_contar(Node *raiz, const char *nomePasta) {
    if (!nomePasta) {
        printf("Uso correto: contar <nome_da_pasta>\n");
        return;
    }

    Node *pasta = encontrarPasta(raiz, nomePasta);
    if (!pasta) {
        printf("Pasta '%s' nao encontrada.\n", nomePasta);
        return;
    }

    int total = contarArquivos(pasta);
    printf("A pasta '%s' contem %d arquivo(s).\n", nomePasta, total);
}



