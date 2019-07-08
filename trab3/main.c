#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abp/abp.h"
#include "hash/hash.h"
#include "aluno/aluno.h"
#define N 100000
#define MAX_MAT N * 10
#define MAX_COEF 10
#define RODADAS 30
#define CLOCKS_PER_MSEC 1000.0

int main(void){

	srand(time(NULL));

	Nodo* indiceMat = criarArvore();
	Nodo* indiceCoef = criarArvore();
	Hash* hash = criaHash(N + N * 0.1 + 27);
	FILE* file = fopen("file.bin", "wb+");

	Aluno aluno;
	int colisoes;

	for(int i = 0; i < N; i++){

		aluno = criaAlunoAleatorio(MAX_MAT, MAX_COEF);

		inserirArvore(&indiceMat, aluno.mat, i, comparaChave);
		inserirArvore(&indiceCoef, aluno.coef, i, comparaChave);
		colisoes = insereHash(hash, aluno.mat, i, comparaChave);
		gravaAluno(file, aluno);

	}

	printf("\nQuantidade de colisões na criação da tabela hash: %d\n\n", colisoes);

	clock_t inicio, fim;
	double tempo, acmMat = 0.0, acmCoef = 0.0, acmHash = 0.0, acmArq = 0.0;

	for(int i = 0; i < RODADAS; i++){

		int mat = rmat(MAX_MAT);

		printf("==== Rodada %d ====\n\n", i + 1);
		printf("Matrícula: %d\n\n", mat);

		inicio = clock();
		Nodo* nodo = buscaABP(indiceMat, mat, comparaChave);

		printf("Aluno: ");

		if(nodo != NULL){

			fseek(file, (nodo -> linha) * sizeof(Aluno), SEEK_SET);
			fread(&aluno, sizeof(Aluno), 1, file);
			imprimeAluno(aluno);

		}else printf("%p\n", NULL);

		fim = clock();
		acmMat += tempo = (fim - inicio)/CLOCKS_PER_MSEC;

		printf("Tempo de busca na ABP: %lf ms\n\n", tempo);

		// -----------------------------------------------------

		inicio = clock();
		Indice* indice = buscaHash(hash, mat, comparaChave);

		printf("Aluno: ");

		if(indice != NULL){

			fseek(file, (indice -> linha) * sizeof(Aluno), SEEK_SET);
			fread(&aluno, sizeof(Aluno), 1, file);
			imprimeAluno(aluno);

		}else printf("%p\n", NULL);

		fim = clock();
		acmHash += tempo = (fim - inicio)/CLOCKS_PER_MSEC;

		printf("Tempo de busca na tabela hash: %lf ms\n\n", tempo);

		// ------------------------------------------------------

		inicio = clock();
		int cont = 0, achou = 0;

		while(!achou && cont < N){

			fseek(file, cont * sizeof(Aluno), SEEK_SET);
			fread(&aluno, sizeof(Aluno), 1, file);

			if(aluno.mat == mat) achou = 1;

			cont++;

		}

		fim = clock();
		acmArq += tempo = (fim - inicio)/CLOCKS_PER_MSEC;

		printf("Aluno: "); if(achou) imprimeAluno(aluno); else printf("%p\n", NULL);

		printf("Tempo de busca direta no arquivo: %lf ms\n\n", tempo);

	}

	printf("#######################\n\n");
	printf("Tempo médio de busca em cada estrutura:\n\n");
	printf("ABP: %lf ms\n", acmMat/RODADAS);
	printf("Tabela hash: %lf ms\n", acmHash/RODADAS);
	printf("Arquivo: %lf ms\n", acmArq/RODADAS);
	
	return 0;

}