// Feito em dupla Jeferson Korte Junior RA 2651114 e Bruno Alcantara RA 2677156

/*

/////////////////////////////////////////////////////
/// Função Remover                                 //
/////////////////////////////////////////////////////

A função remove_ArvAVL remove um nó de uma árvore AVL mantendo o balanceamento. Ela busca o valor recursivamente comparando com o conteúdo do nó atual. Ao encontrar o valor, três casos são tratados:

Caso 1: O nó tem zero ou um filho. Ele é removido e substituído diretamente por seu filho (ou NULL se for folha).

Caso 2: O nó tem dois filhos. Nesse caso, o valor do nó é substituído pelo menor valor da subárvore direita (usando a função procuraMenor), e esse valor é então removido recursivamente.

Rebalanceamento: Após a remoção, a árvore pode ficar desbalanceada. O fator de balanceamento é recalculado e, se necessário, são aplicadas rotações: RotacaoLL, RotacaoRR, RotacaoLR ou RotacaoRL, conforme o tipo de desequilíbrio.

A altura de cada nó é atualizada ao final do processo com a função maior. Assim, a árvore AVL continua balanceada mesmo após remoções.

/////////////////////////////////////////////////////
/// Funções auxiliares utilizadas                  //
/////////////////////////////////////////////////////

Função procuraMenor: Localiza o menor valor da subárvore direita de um nó. É usada para substituir um nó com dois filhos durante a remoção.

Função altura_NO: Retorna a altura de um determinado nó. É usada para calcular o fator de balanceamento e também para atualizar as alturas após modificações.

Função fatorBalanceamento_NO: Calcula a diferença entre as alturas da subárvore esquerda e direita de um nó, indicando se há desequilíbrio.

Função maior: Retorna o maior entre dois números inteiros. É utilizada para determinar a nova altura de um nó após remoções ou rotações.

Funções de rotação (RotacaoLL, RotacaoRR, RotacaoLR, RotacaoRL): São responsáveis por corrigir o balanceamento da árvore após a remoção de um nó. A rotação aplicada depende do tipo de desequilíbrio detectado na árvore.

*/