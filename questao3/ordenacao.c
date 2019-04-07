#include "ordenacao.h"

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