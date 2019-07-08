#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int pai(int i){

	return (i - 1)/2;

}

int filhoEsquerda(int i){

	return 2 * i + 1;

}

int filhoDireita(int i){

	return 2 * i + 2;

}

void swap(int* vetor, int a, int b){

	int aux = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = aux;

}

Heap criaHeap(int max){

	Heap heap;

	heap.vetor = (int*) malloc(sizeof(int) * max);
	heap.ocup = 0;
	heap.max = max;

	return heap;

}

void heapifyUp(Heap* heap, int i){

	if(i > 0){

		int p = pai(i);

		if(heap -> vetor[i] > heap -> vetor[p]) swap(heap -> vetor, i, p);

		heapifyUp(heap, p);

	}

}

void insereHeap(Heap* heap, int val){

	if(heap -> ocup < heap -> max){

		heap -> vetor[heap -> ocup] = val;
		heapifyUp(heap, heap -> ocup);
		heap -> ocup++;

	}

}

void heapifyDown(Heap* heap, int i){

	int fEsq = filhoEsquerda(i), fDir = filhoDireita(i), maior = i;

	if(fEsq <= heap -> max && heap -> vetor[maior] < heap -> vetor[fEsq]) maior = fEsq;
	if(fDir <= heap -> max && heap -> vetor[maior] < heap -> vetor[fDir]) maior = fDir;

	if(maior != i){

		swap(heap -> vetor, i, maior);
		heapifyDown(heap, maior);

	}

}

void removeHeap(Heap* heap){

	if(heap -> ocup){

		heap -> vetor[0] = heap -> vetor[heap -> ocup - 1];
		heap -> vetor[heap -> ocup - 1] = '\0';
		heap -> ocup--;

		heapifyDown(heap, 0);

	}

}

void imprimeHeap(Heap heap){

	for(int i = 0; i < heap.ocup; i++) printf("%d ", heap.vetor[i]);

	printf("\n");

}