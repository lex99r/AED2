#include <stdio.h>
#include "grafo.h"

int main(void){

	Grafo grafo = criaGrafo(10, 0);

	insereAresta(grafo, 1, 2);
	insereAresta(grafo, 1, 5);
	imprimeMatrizAdj(grafo); printf("\n");
	imprimeListaAdj(grafo);

	return 0;

}