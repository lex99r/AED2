#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo criaGrafo(int v, int a){

	Grafo grafo;

	grafo.v = v;
	grafo.a = a;

	int** matriz = (int**) malloc(v * sizeof(int*));

	for(int i = 0; i < v; i++) matriz[i] = (int*) malloc(v * sizeof(int));

	for(int i = 0; i < v; i++) for(int j = 0; j < v; j++) matriz[i][j] = 0;

	grafo.matriz = matriz;

	return grafo;

}

void insereAresta(Grafo grafo, int v1, int v2){

	if(grafo.matriz[v1][v2] == 0){

		grafo.matriz[v1][v2] = 1;
		grafo.a++;

	}

}

void removeAresta(Grafo grafo, int v1, int v2){

	if(grafo.matriz[v1][v2] == 1){

		grafo.matriz[v1][v2] = 0;
		grafo.a--;

	}

}

void imprimeMatrizAdj(Grafo grafo){

	printf("  "); for(int i = 0; i < grafo.v; i++) printf("%d ", i); printf("\n");

	for(int i = 0; i < grafo.v; i++){

		printf("%d ", i);

		for(int j = 0; j < grafo.v; j++) printf("%d ", grafo.matriz[i][j]);

		printf("\n");

	}

}

void imprimeListaAdj(Grafo grafo){

	for(int i = 0; i < grafo.v; i++){

		printf("%d: ", i);

		for(int j = 0; j < grafo.v; j++) if(grafo.matriz[i][j] == 1) printf("%d ", j);

		printf("\n");

	}

}