#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"
#include "../questao1/busca.h"
#define N 1000000
#define LIM_MAX 11
#define NUM_MAX 10000001
#define RODADAS 30

void preencherEstruturas(int* vet, Lista* lista){

	srand(clock());

	int num = 0;

	for(int i = 0; i < N; i++){

		num += (rand() % LIM_MAX);
		vet[i] = num;
		inserirFinalLista(lista, num);

	}

}

int main(void){

	int vet[N], chave, indice;
	Lista* lista = criarLista();
	clock_t inicio, fim;
	double tempo, tempoVetor = 0.0, tempoLista = 0.0;

	preencherEstruturas(vet, lista);

	for(int cont = 0; cont < RODADAS; cont++){

		chave = rand() % NUM_MAX;

		printf("====== Rodada %02d ======\n\n", cont + 1);
		printf("Chave de busca: %d\n\n", chave);

		inicio = clock();
		indice = buscaSequencial(vet, N, chave);
		fim = clock();
		tempoVetor += tempo = (fim - inicio)/1000.0;
		printf("Vetor: %.3lf ms | Índice: %d\n", tempo, indice);

		inicio = clock();
		indice = buscaLista(lista, chave);
		fim = clock();
		tempoLista += tempo = (fim - inicio)/1000.0;
		printf("Lista: %.3lf ms | Índice: %d\n\n", tempo, indice);

	}

	printf("#######################\n\n");
	printf("Tempo médio de execução dos algoritmos de busca em cada estrutura:\n\n");
	printf("Vetor: %lf ms\n", tempoVetor/RODADAS);
	printf("Lista: %lf ms\n", tempoLista/RODADAS);

	return 0;

}