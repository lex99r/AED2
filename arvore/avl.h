typedef struct nodoAVL NodoAVL;

NodoAVL* criarAVL(void);
void inserirAVL(NodoAVL* raiz, int num);
void leftRotate(NodoAVL *x);
void rightRotate(NodoAVL *x);
void balanceamento(NodoAVL *no);
void atualizarBal(NodoAVL *no, int num);
void percorreOrdem(NodoAVL *A);