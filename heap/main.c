#include "heap.h"

int main(void){

	int array[] = {25, 20, 22, 17, 19, 10, 12, 15, 7, 9, 18};
	Heap heap = criaHeap(15);

	heap.vetor = array;
	heap.ocup = 11;

	imprimeHeap(heap);
	insereHeap(&heap, 24);
	imprimeHeap(heap);
	removeHeap(&heap);
	imprimeHeap(heap);

	return 0;

}