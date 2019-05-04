// TAD: vetor de inteiros

// Ordenação quicksort, classe: O(N log N)
void quickSort(int* vet, int inicio, int fim);

// Ordenação por inserção direta, classe: O(N²)
void insertionSort(int* vet, int N);

// Ordenação bolha, classe: O(N²)
void bubbleSort(int* vet, int N);

// Busca binária, classe: O(log N)
int buscaBinaria(int* vet, int N, int chave);

// Busca sequencial, classe: O(N)
int buscaSequencial(int* vet, int N, int chave);