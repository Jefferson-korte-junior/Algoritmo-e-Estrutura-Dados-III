# Projeto 01 de Matriz Dinâmica - Algoritmo e Estrutura de Dados 3

Este projeto implementa uma matriz dinâmica utilizando listas duplamente encadeadas para cada elemento, permitindo operações como inserção, consulta, busca, remoção, impressão de vizinhos e limpeza de dados.

## Funcionalidades

- **Criar matriz** com número de linhas e colunas definidos pelo usuário.
- **Inserir elemento** em qualquer posição da matriz.
- **Consultar valor** de uma posição específica.
- **Buscar valor** em toda a matriz, mostrando todas as posições onde ele aparece.
- **Imprimir os vizinhos** (cima, baixo, esquerda, direita) de qualquer posição.
- **Remover valor** de uma posição específica.
- **Limpar todos os dados** da matriz (zera todos os valores).
- **Imprimir a matriz** de forma visual.
- **Liberar toda a matriz** da memória.

## Estruturas Utilizadas

- Cada elemento da matriz é um nó com ponteiros para cima, baixo, esquerda e direita.
- A matriz é representada por uma struct que armazena ponteiros para todos os elementos e para o início da matriz.

## Como compilar

No terminal, execute:

```sh
gcc main.c matriz.c -o matriz
```

## Como usar

O programa apresenta um menu interativo no terminal, onde você pode escolher as opções digitando o número correspondente.

## Organização dos arquivos

- `main.c` — Interface com o usuário e controle do menu.
- `matriz.c` — Implementação das funções de manipulação da matriz.
- `matriz.h` — Declaração das funções e tipos de dados.


**Desenvolvido para a disciplina de Algoritmo e Estrutura de Dados 3.**




# Projeto 02 -  Sistema de Gerenciamento de Arquivos em Árvore - Algoritmo e Estrutura de Dados 3

## Descrição

Este projeto simula um sistema de gerenciamento de arquivos e pastas utilizando uma **estrutura de árvore genérica** em C.  
O objetivo é permitir operações semelhantes a um terminal de sistemas operacionais, como criar, remover, listar, buscar e contar arquivos e pastas, além de navegar entre diretórios.

---

## Funcionalidades

- **Leitura de estrutura inicial** a partir de um arquivo texto (`in.txt`), onde cada linha representa um caminho de arquivo ou pasta.
- **Criação de pastas** (`mkdir <nome>`)
- **Remoção de arquivos ou pastas** (`rm <nome>`)
- **Listagem do conteúdo** da pasta atual (`list`)
- **Navegação entre pastas** (`cd <nome>`)
- **Busca por arquivos ou pastas** pelo nome (`search <nome>`)
- **Contagem de arquivos** dentro de uma pasta específica (`cfif <nome_da_pasta>`)
- **Ajuda** com os comandos disponíveis (`help`)
- **Limpeza da tela** (`clear`)
- **Saída do programa** (`exit`)

---

## Estrutura dos arquivos

- `main.c` — Interface principal do usuário e loop de comandos.
- `matriz.c` — Implementação das funções de manipulação da árvore e comandos.
- `matriz.h` — Definição da estrutura `Node` e protótipos das funções.
- `in.txt` — Arquivo de entrada com a estrutura inicial de arquivos e pastas.

---

## Exemplo de uso
[ROOT]$ list ROOT/ Meus Documentos/ fontes/ main.c main.h imagens/ apresentacao.ppt relatorio.doc Meus Downloads/ 7zip.exe t2.rar Arquivos e Programas/ Firefox/ Chrome/ Opera/

[ROOT]$ mkdir novaPasta Diretório 'novaPasta' criado com sucesso.

[ROOT]$ cfif Meus Documentos A pasta 'Meus Documentos' contem 4 arquivo(s).

[ROOT]$ search main.c Encontrado: /Meus Documentos/fontes/main.c
