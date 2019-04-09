#include "busca.h"
#include "../questao2/lista.h"

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