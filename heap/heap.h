typedef struct{

	int* vetor;
	int ocup;
	int max;

} Heap;

int pai(int i);
int filhoEsquerda(int i);
int filhoDireita(int i);
void swap(int* vetor, int a, int b);
Heap criaHeap(int max);
void heapifyUp(Heap* heap, int i);
void insereHeap(Heap* heap, int val);
void heapifyDown(Heap* heap, int i);
void removeHeap(Heap* heap);
void imprimeHeap(Heap heap);