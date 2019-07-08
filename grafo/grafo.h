typedef struct{

	int v;
	int a;
	int** matriz;

} Grafo;

Grafo criaGrafo(int v, int a);
void insereAresta(Grafo grafo, int v1, int v2);
void removeAresta(Grafo grafo, int v1, int v2);
void imprimeMatrizAdj(Grafo grafo);
void imprimeListaAdj(Grafo grafo);