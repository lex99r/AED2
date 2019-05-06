#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

void quickSort(int* vet, int inicio, int fim){

	int i, j, pivo, aux;

	i = inicio;
	j = fim - 1;

	pivo = vet[(inicio + fim)/2];

	while(i <= j){

		while(vet[i] < pivo && i < fim) i++;
		while(vet[j] > pivo && j > inicio) j--;

		if(i <= j){

			aux = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
			i++;
			j--;

		}

	}

	if(j > inicio) quickSort(vet, inicio, j + 1);
	if(i < fim) quickSort(vet, i, fim);

}

void insertionSort(int* vet, int N){

	int i, j, aux;

		for(i = 1; i < N; i++) {

		aux = vet[i];
		j = i - 1;

		while(j >= 0 && vet[j] > aux){

			vet[j + 1] = vet[j];
			j--;

		}

		vet[j + 1] = aux;

	}

}

void bubbleSort(int* vet, int N){

	int i, j, aux;

	for(i = 0; i < N; i++){

		for(j = i + 1; j < N; j++){

			if(vet[j] < vet[i]){

				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;

			}

		}

	}

}

int buscaSequencial(int* vet, int N, int chave){

	for(int i = 0; i < N; i++) if(vet[i] == chave) return i;

	return -1;

}

int buscaBinaria(int* vet, int N, int chave){

	int inicio = 0, fim = N - 1, meio;

	while(inicio <= fim){

		meio = (inicio + fim)/2;

		if(vet[meio] == chave) return meio;
		else if(vet[meio] < chave) inicio = meio + 1;
		else fim = meio - 1;

	}

	return -1;

}

void shuffle(int* vet, int N){

	for(int i = N - 1; i > 0; i--){

		int j = rand() % (i + 1);

		int aux = vet[j];
		vet[j] = vet[i];
		vet[i] = aux;

	}

}

void preencherVetorAleatoriamente(int* vet, int N){

	int* vetAux = (int*) malloc(N * 2 * sizeof(int));

	for(int i = 0; i < (N * 2); i++) vetAux[i] = i;

	shuffle(vetAux, N * 2);

	for(int i = 0; i < N; i++) vet[i] = vetAux[i];

	free(vetAux);

}

void imprimirVetor(int* vet, int N){

	for(int i = 0; i < N; i++) printf("%d ", vet[i]);

	printf("\n");

}