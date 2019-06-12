#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int fhash(int chave, int N){

	return chave % N;

}

Hash* criaHash(int N){

	Hash* hash = (Hash*) malloc(sizeof(Hash));

	hash -> tab = malloc(N * sizeof(Indice*));
	hash -> N = N;

	memset(hash -> tab, '\0', N * sizeof(Indice*));

	return hash;

}

Indice* buscaHash(Hash* hash, int chave, Compara compara){

	int h = fhash(chave, hash -> N);

	while(hash -> tab[h] != NULL){

		if(compara(hash -> tab[h] -> chave, chave) == 0) return hash -> tab[h];

		h = (h + 1) % hash -> N;

	}

	return NULL;

}

int insereHash(Hash* hash, double chave, int linha, Compara compara){

	int colisoes = 0;
	int h = fhash(chave, hash -> N);

	while(hash -> tab[h] != NULL && compara(hash -> tab[h] -> chave, chave) != 0){

		h = (h + 1) % hash -> N;
		colisoes++;

	}

	if(hash -> tab[h] == NULL){

		Indice* indice = (Indice*) malloc(sizeof(Indice));
		indice -> chave = chave;
		indice -> linha = linha;
		hash -> tab[h] = indice;

	}

	return colisoes;

}

void imprimeHash(Hash* hash){

	for(int i = 0; i < hash -> N; i++){

		if(hash -> tab[i] != NULL){
			
			printf("%03d: %.0lf %d\n", i + 1, hash -> tab[i] -> chave, hash -> tab[i] -> linha); 

		}else printf("%p\n", NULL);

	}

}