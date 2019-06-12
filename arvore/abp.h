typedef struct no No;

No* criarArvore(void);
void inserirArvore(No** no, int info);
void impressaoPrefixado(No* no);
void impressaoCentral(No* no);
void impressaoPosfixado(No* no);
No* buscaABP(No* arvore, int chave);
void liberarABP(No* raiz);