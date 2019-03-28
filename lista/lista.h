// TAD: Lista de inteiros

// Definições de tipos auxiliares para a lista

typedef struct lista Lista;
typedef void (*Callback)(int);

// Função que aloca e retorna nova lista
Lista* criarLista(void);

// Função que insere novo elemento no ínicio da lista
void inserirInicioLista(Lista* lista, int num);

// Função que insere novo elemento no final da lista
void inserirFinalLista(Lista* lista, int num);

// Função que remove primeiro elemento da lista
int removerInicioLista(Lista* lista);

// Função que remove último elemento da lista
int removerFinalLista(Lista* lista);

// Função que retorna o primeiro elemento da lista
int inicioLista(Lista* lista);

// Função que percorre a lista e aplica uma função callback para cada elemento
void percorrerLista(Lista* lista, Callback callback);

// Função que retorna o último elemento da lista
int finalLista(Lista* lista);

// Função que responde se a lista está vazia
short listaVazia(Lista* lista);