#include <stdio.h>
#include "lista.h"

void imprimirNum(int num){

	printf("%d ", num);

}

int main(void){

	Lista* lista = criarLista();

	inserirFinalLista(lista, 1);
	inserirFinalLista(lista, 2);
	inserirFinalLista(lista, 3);

	percorrerLista(lista, imprimirNum); printf("\n");

	removerInicioLista(lista);
	removerFinalLista(lista);

	percorrerLista(lista, imprimirNum); printf("\n");

	return 0;

}