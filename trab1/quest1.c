#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../vetor/vetor.h"
#define N 1000000
#define LIM_MAX 11
#define NUM_MAX 10000001
#define RODADAS 30

void preencherVetor(int* vet){

	srand(clock());

	vet[0] = rand() % LIM_MAX;

	for(int i = 1; i < N; i++) vet[i] = vet[i - 1] + (rand() % LIM_MAX);

}

int main(void){

	int vet[N], chave, indice;
	clock_t inicio, fim;
	double tempo, tempoBinaria = 0.0, tempoSequencial = 0.0;

	preencherVetor(vet);

	for(int cont = 0; cont < RODADAS; cont++){

		chave = rand() % NUM_MAX;

		printf("====== Rodada %02d ======\n\n", cont + 1);
		printf("Chave de busca: %d\n\n", chave);

		inicio = clock();
		indice = buscaBinaria(vet, N, chave);
		fim = clock();
		tempoBinaria += tempo = (fim - inicio)/1000.0;
		printf("Busca binária: %.3lf ms    | Índice: %d\n", tempo, indice);

		inicio = clock();
		indice = buscaSequencial(vet, N, chave);
		fim = clock();
		tempoSequencial += tempo = (fim - inicio)/1000.0;
		printf("Busca sequencial: %.3lf ms | Índice: %d\n\n", tempo, indice);

	}

	printf("#######################\n\n");
	printf("Tempo médio de execução dos algoritmos de busca:\n\n");
	printf("Busca binária: %lf ms\n", tempoBinaria/RODADAS);
	printf("Busca sequencial: %lf ms\n", tempoSequencial/RODADAS);

	return 0;

}