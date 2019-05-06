#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../vetor/vetor.h"
#include "../arvore/abp.h"
#include "../arvore/avl.h"
#define N 1000
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

	int vet[N];
	No* arvABP = criarArvore();
	NodoAVL* raiz = criarAVL();
	clock_t inicio, fim;
	double tempo, tempoCriacaoABP = 0.0, tempoCriacaoAVL = 0.0,
	tempoBuscaABP = 0.0, tempoBuscaAVL = 0.0;

	// for(int i = 0; i < QUANT_ARVS; i++){

		preencherVetorAleatoriamente(vet, N);

		// printf("====== Árvore %02d ======\n\n", i + 1);

		// inicio = clock();
		// preencherABP(arvABP, vet);
		// fim = clock();
		// tempoCriacaoABP += tempo = (fim - inicio)/CLOCKS_PER_MSEC;
		// printf("Tempo de criação ABP: %lf ms\n", tempo);

		inicio = clock();
		preencherAVL(raiz, vet);
		fim = clock();
		tempo = (fim - inicio)/CLOCKS_PER_MSEC;
		// printf("Tempo de criação AVL: %lf ms\n\n", tempo);

		percorreOrdem(raiz); printf("\n");

	// }

	return 0;

}