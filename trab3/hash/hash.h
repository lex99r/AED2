typedef struct{

	double chave;
	int linha;

} Indice;

struct hash{

	Indice** tab;
	int N;

};

typedef struct hash Hash;
typedef short (*Compara)(double, double);
typedef void (*Imprime)(void*);

Hash* criaHash(int N);
int insereHash(Hash* hash, double chave, int linha, Compara compara);
Indice* buscaHash(Hash* hash, int chave, Compara compara);
void imprimeHash(Hash* hash);