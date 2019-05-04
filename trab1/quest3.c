#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../vetor/vetor.h"
#define N 100000
#define MAX 1000000
#define MIN -1000000
#define RODADAS 30

void preencherVetores(int* vetA, int* vetB, int* vetC){

	srand(clock());

	for(int i = 0; i < N; i++) vetA[i] = vetB[i] = vetC[i] = (rand() % (MAX + 1 - MIN)) + MIN;

}

int main(void){

	int vetA[N], vetB[N], vetC[N];
	clock_t inicio, fim;
	double tempo, tempoQuick = 0.0, tempoInsertion = 0.0, tempoBolha = 0.0;

	for(int cont = 0; cont < RODADAS; cont++){

		preencherVetores(vetA, vetB, vetC);

		printf("======== Rodada %02d ========\n\n", cont + 1);

		inicio = clock();
		quickSort(vetA, 0, N);
		fim = clock();
		tempoQuick += tempo = (fim - inicio)/1000.0;
		printf("Quicksort: %.3lf ms\n", tempo);

		inicio = clock();
		insertionSort(vetB, N);
		fim = clock();
		tempoInsertion += tempo = (fim - inicio)/1000.0;
		printf("Inserção direta: %.3lf ms\n", tempo);

		inicio = clock();
		bubbleSort(vetC, N);
		fim = clock();
		tempoBolha += tempo = (fim - inicio)/1000.0;
		printf("Bolha: %.3lf ms\n\n", tempo);

	}

	printf("###########################\n\n");
	printf("Tempo médio de execução dos algoritmos de ordenação:\n\n");
	printf("Quicksort: %.4lf ms\n", tempoQuick/RODADAS);
	printf("Inserção Direta: %.4lf ms\n", tempoInsertion/RODADAS);
	printf("Bolha: %.4lf ms\n", tempoBolha/RODADAS);

	return 0;

}