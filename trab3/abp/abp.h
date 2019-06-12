typedef struct nodo Nodo;

struct nodo{

    double chave;
	int linha;
    Nodo* esq;
    Nodo* dir;

};

typedef short (*Compara)(double, double);
// typedef void (*Imprime)(void*);
// typedef void (*Grava)(FILE*, void*);

Nodo* criarArvore(void);
void inserirArvore(Nodo** arvore, double chave, int linha, Compara compara);
// void impressaoPrefixado(Nodo* nodo);
// void impressaoCentral(Nodo* nodo, Imprime imprime);
// void gravacaoOrdenada(FILE* file, Nodo* nodo, Grava grava);
void impressaoOrdenada(Nodo* nodo);
// void impressaoPosfixado(Nodo* nodo);
Nodo* buscaABP(Nodo* nodo, double chave, Compara compara);
Nodo* buscaMaiorIgualABP(Nodo* nodo, double chave, Compara compara);
// void liberarABP(Nodo* raiz);