#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

struct no{

    int info;
    No* esq;
    No* dir;

};

No* criarNo(No* esq, No* dir, int info){

    No* no = (No*) malloc(sizeof(No));

	no -> info = info;
	no -> esq = esq;
	no -> dir = dir;

}

No* criarArvore(void){

    return NULL;

}

void inserirArvore(No** no, int info){

	if(*no == NULL){

		*no = criarNo(NULL, NULL, info);

	}else if((*no) -> info > info){

		inserirArvore(&((*no) -> esq), info);

	}else{

		inserirArvore(&((*no) -> dir), info);

	}

}

void impressaoPrefixado(No* no){

	if(no != NULL){

		printf("%d ", no -> info);
		impressaoPrefixado(no -> esq);
		impressaoPrefixado(no -> dir);

	}

}

void impressaoCentral(No* no){

	if(no != NULL){

		impressaoCentral(no -> esq);
		printf("%d ", no -> info);
		impressaoCentral(no -> dir);

	}

}

void impressaoPosfixado(No* no){

	if(no != NULL){

		impressaoPosfixado(no -> esq);
		impressaoPosfixado(no -> dir);
		printf("%d ", no -> info);

	}

}

No* buscaArvore(No* arvore, int chave){

	if(arvore == NULL) return NULL;
	else if (arvore -> info > chave) return buscaArvore(arvore -> esq, chave);
	else if (arvore -> info < chave) return buscaArvore(arvore -> dir, chave);
	else return arvore;

}