// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

//Verifica se a arvore esta vazia, se a arvore esta vazia cria um novo nó. Se o ponteiro para a raiz for nulo, aloca um novo nó, inicializa seus campos e o insere como raiz.

//Busca a posição correta para inserir, se a arvore nao esta vazia ela compara o valor a ser inserido com o valor do nó que esta. Chama recursivamente a função de inserção para o nó esquerdo ou direito, dependendo se o valor.

//struct NO *atual = *raiz;
//if(valor < atual->info){
//    res = insere_ArvAVL(&(atual->esq), valor);
    // ...verifica balanceamento...
//}else if(valor > atual->info){
//    res = insere_ArvAVL(&(atual->dir), valor);
    // ...verifica balanceamento...
//}else{
    // Valor já existe
//    return 0;
//}

//Depois atualiza a altura de no. Função usada: maior(int x, int y) retorna o maior valor entre os dois inteiros. E tambem é usada a altura_NO(struct NO* no) que retorna a altura do nó.

//Verifica e corrige o balanceamento, apos inserir verificamos se o no ficou desbalanceado e caso precisa faz as rotaçoes para corrigir.


//int fb = fatorBalanceamento_NO(atual);
//if(fb < -1){
 //   if(valor > (*raiz)->dir->info){
//        RotacaoRR(raiz);
//    }else{
//        RotacaoRL(raiz);
//    }
//}else if(fb > 1){
//    if(valor < (*raiz)->esq->info){
//        RotacaoLL(raiz);
//    }else{
//        RotacaoLR(raiz);
//    }
//}

//Função usada Fatorbalanceamento_NO(struct NO* no) que calcula o fator de balanceamento do nó.
//RotacaoRR, RotacaoLL, RotacaoLR e RotacaoRL são funções que realizam as rotações necessárias para manter a árvore balanceada.

//E no final retorna o resultado da inserção (1 para sucesso, 0 para falha).