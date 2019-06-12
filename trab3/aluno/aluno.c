#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

Aluno criaAluno(int mat, char* nome, int idade, char* email, double coef){

	// Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));

	Aluno aluno;

	aluno.mat = mat;
	strcpy(aluno.nome, nome);
	aluno.idade = idade;
	strcpy(aluno.email, email);
	aluno.coef = coef;

	return aluno;

}

Aluno criaAlunoAleatorio(int maxMat, int maxCoef){

	return criaAluno(rmat(maxMat), "Fulano da Silva", 18, "email@email.com", rcoef(maxCoef));

}

void imprimeAluno(Aluno aluno){

	printf("%06d %s %d %s %lf\n", aluno.mat, aluno.nome, aluno.idade, aluno.email, aluno.coef);

}

void gravaAluno(FILE* file, Aluno aluno){

	fwrite(&aluno, sizeof(Aluno), 1, file);

}

short comparaChave(double chaveA, double chaveB){

	if(chaveA < chaveB) return -1;
	else if(chaveA == chaveB) return 0;
	else return 1;

}

int rmat(int max){

	return rand() % max;

}

double rcoef(int max){

	return (rand() % max) + ((rand() % 100000)/100000.0);

}