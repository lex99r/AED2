#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

typedef struct elemento Elemento;

struct elemento{

	int num;
	Elemento* prox;

};

Elemento* criarElemento(int num){

	Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));

	elemento -> num = num;

	return elemento;

}

struct lista{

	Elemento* inicio;
	Elemento* final;

};

Lista* criarLista(void){

	Lista* lista = (Lista*) malloc(sizeof(Lista));

	lista -> inicio = lista -> final = NULL;

	return lista;

}

void inserirInicioLista(Lista* lista, int num){

	Elemento* elemento = criarElemento(num);

	elemento -> prox = lista -> inicio;

	if(lista -> inicio == NULL) lista -> final = elemento;

	lista -> inicio = elemento;

}

void inserirFinalLista(Lista* lista, int num){

	Elemento* elemento = criarElemento(num);

	elemento -> prox = NULL;

	if(lista -> inicio == NULL) lista -> inicio = elemento;
	else lista -> final -> prox = elemento;

	lista -> final = elemento;

}

int removerInicioLista(Lista* lista){

	int num = '\0';

	if(!listaVazia(lista)){

		Elemento* prox = lista -> inicio -> prox;

		num = lista -> inicio -> num;
		free(lista -> inicio);
		lista -> inicio = prox;

		if(lista -> inicio == NULL) lista -> final = NULL;

	}

	return num;

}

int removerFinalLista(Lista* lista){

	int num = '\0';

	if(!listaVazia(lista)){

		Elemento* ant = NULL;
		Elemento* aux = lista -> inicio;

		while(aux -> prox != NULL){

			ant = aux;
			aux = aux -> prox;

		}

		num = lista -> final -> num;
		free(lista -> final);
		lista -> final = ant;

		if(lista -> final == NULL) lista -> inicio = NULL;
		else ant -> prox = NULL;

	}

	return num;

}

void percorrerLista(Lista* lista, Callback callback){

	if(!listaVazia(lista)){

		Elemento* aux = lista -> inicio;

		while(aux != NULL){

			callback(aux -> num);
			aux = aux -> prox;

		}

	}

}

int inicioLista(Lista* lista){

	return lista -> inicio -> num;

}

int finalLista(Lista* lista){

	return lista -> final -> num;

}

short listaVazia(Lista* lista){

	return lista -> inicio == NULL && lista -> final == NULL;

}