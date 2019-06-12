#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

Nodo* criarNodo(Nodo* esq, Nodo* dir, double chave, int linha){

    Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));

	nodo -> chave = chave;
	nodo -> linha = linha;
	nodo -> esq = esq;
	nodo -> dir = dir;

	return nodo;

}

Nodo* criarArvore(void){

	return NULL;

}

void inserirArvore(Nodo** arvore, double chave, int linha, Compara compara){

	if(*arvore == NULL) *arvore = criarNodo(NULL, NULL, chave, linha);
	else if(compara((*arvore) -> chave, chave) == 1) inserirArvore(&((*arvore) -> esq), chave, linha, compara);
	else inserirArvore(&((*arvore) -> dir), chave, linha, compara);

}

void impressaoOrdenada(Nodo* nodo){

	if(nodo != NULL){

		impressaoOrdenada(nodo -> esq);
		printf("%.0lf %d\n", nodo -> chave, nodo -> linha);
		impressaoOrdenada(nodo -> dir);

	}

}

Nodo* buscaABP(Nodo* nodo, double chave, Compara compara){

	if(nodo == NULL) return NULL;
	else if(compara(nodo -> chave, chave) == 1) return buscaABP(nodo -> esq, chave, compara);
	else if(compara(nodo -> chave, chave) == -1) return buscaABP(nodo -> dir, chave, compara);
	else return nodo;

}

Nodo* buscaMaiorIgualABP(Nodo* nodo, double chave, Compara compara){

	if(nodo == NULL) return NULL;
	else if(compara(nodo -> chave, chave) == -1) return buscaMaiorIgualABP(nodo -> dir, chave, compara);
	else return nodo;

}