#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../vetor/vetor.h"
#include "../arvore/abp.h"
#include "../arvore/avl.h"
#define N 1000000
#define MAX 10000000
#define QUANT_ARVS 10
#define QUANT_BUSCAS 30
#define CLOCKS_PER_MSEC 1000.0

void preencherABP(No** raiz, int* vet){

	for(int i = 0; i < N; i++) inserirArvore(raiz, vet[i]);

}

void preencherAVL(NodoAVL* raiz, int* vet){

	for(int i = 0; i < N; i++) inserirAVL(raiz, vet[i]);

}

int main(void){

	int vet[N], chave;
	No* raizABP;
	No* noChaveABP;
	No* vetABP[QUANT_ARVS];
	NodoAVL* raizAVL;
	NodoAVL* noChaveAVL;
	NodoAVL* vetAVL[QUANT_ARVS];
	clock_t inicio, fim;
	double tempo, tempoCriacaoABP = 0.0, tempoCriacaoAVL = 0.0,
	tempoBuscaABP = 0.0, tempoBuscaAVL = 0.0;

	srand(clock());

	for(int i = 0; i < QUANT_ARVS; i++){

		preencherVetorAleatoriamente(vet, N);

		printf("====== Criação %02d ======\n\n", i + 1);

		inicio = clock();
		raizABP = criarArvore();
		preencherABP(&raizABP, vet);
		fim = clock();
		tempoCriacaoABP += tempo = (fim - inicio)/CLOCKS_PER_MSEC;
		printf("Tempo de criação ABP: %lf ms\n", tempo);

		vetABP[i] = raizABP;

		inicio = clock();
		raizAVL = criarAVL();
		preencherAVL(raizAVL, vet);
		fim = clock();
		tempoCriacaoAVL += tempo = (fim - inicio)/CLOCKS_PER_MSEC;
		printf("Tempo de criação AVL: %lf ms\n\n", tempo);

		vetAVL[i] = raizAVL;

	}

	printf("########################\n\n");
	printf("Tempo médio de criação de cada estrutura:\n\n");
	printf("Vetor: %lf ms\n", tempoCriacaoABP/QUANT_ARVS);
	printf("AVL: %lf ms\n\n", tempoCriacaoAVL/QUANT_ARVS);
	printf("########################\n\n");

	for(int j = 0; j < QUANT_BUSCAS; j++){

		chave = rand() % MAX;

		printf("====== Busca %02d ======\n\n", j + 1);
		printf("Chave de busca: %d\n\n", chave);

		inicio = clock();
		noChaveABP = buscaABP(vetABP[0], chave);
		fim = clock();
		tempoBuscaABP += tempo = (fim - inicio)/CLOCKS_PER_MSEC;

		printf("ABP: %lf ms   | Ponteiro: %p\n\n", tempo, noChaveABP);

		inicio = clock();
		noChaveAVL = buscaAVL(vetAVL[0], chave);
		fim = clock();
		tempoBuscaAVL += tempo = (fim - inicio)/CLOCKS_PER_MSEC;

		printf("AVL: %lf ms   | Ponteiro: %p\n\n", tempo, noChaveAVL);

	}

	printf("#######################\n\n");
	printf("Tempo médio de busca em cada estrutura:\n\n");
	printf("ABP: %lf ms\n", tempoBuscaABP/QUANT_BUSCAS);
	printf("AVL: %lf ms\n", tempoBuscaAVL/QUANT_BUSCAS);

	return 0;

}