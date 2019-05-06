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

void shuffle(int* vet, int N);
void preencherVetorAleatoriamente(int* vet, int N);

// Função que exibe os elementos do vetor
void imprimirVetor(int* vet, int N);