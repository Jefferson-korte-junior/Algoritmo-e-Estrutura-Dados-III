#include "matriz.h"

//Quantidade de arquivos
//Quantidades de arquivos dentros de uma pasta

int main() {
    Node *raiz = criarNo("ROOT", 0);
    Node *pastaAtual = raiz;

    lerArquivo(raiz, "in.txt");

    char comando[256];

    while (1) {
        
        printf("\n[%s]$ ", pastaAtual->nome); // como um terminal
        fgets(comando, sizeof(comando), stdin);

        // Remove quebra de linha
        comando[strcspn(comando, "\n")] = 0;

        // Divide comando em palavra-chave e argumento
        char *cmd = strtok(comando, " ");
        char *arg = strtok(NULL, "");

        if (!cmd) continue;

        if (strcmp(cmd, "cd") == 0) {
            pastaAtual = comando_cd(pastaAtual, arg);
        } else if (strcmp(cmd, "mkdir") == 0) {
            comando_mkdir(pastaAtual, arg);
        } else if (strcmp(cmd, "list") == 0) {
            listarConteudo(pastaAtual, 0);
        } else if (strcmp(cmd, "search") == 0) {
            comando_search(raiz, arg, "");
        } else if (strcmp(cmd, "rm") == 0) {
            comando_rm(pastaAtual, arg);
        } else if (strcmp(cmd, "help") == 0) {
            comando_help();
        } else if (strcmp(cmd, "clear") == 0) {
            comando_clear();
        } else if (strcmp(cmd, "cfif") == 0) {
            comando_contar(raiz, arg);
        } else if (strcmp(cmd, "exit") == 0) {
            liberarArvore(raiz);
            break;
        } else {
            printf("Comando invalido. Digite 'help' para ver os comandos disponiveis.\n");
        }
    }

    return 0;
}
