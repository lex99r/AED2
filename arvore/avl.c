#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

struct nodoAVL{
	int num;
	int bal;
	NodoAVL *esq;
	NodoAVL *dir;
	NodoAVL *pai;
};

NodoAVL* criarAVL(void){

    NodoAVL* sentinela = (NodoAVL*) calloc(1, sizeof(NodoAVL));

    sentinela -> num = -1000;
    sentinela -> esq = sentinela -> dir = sentinela -> pai = NULL;

    return sentinela;

}

void inserirAVL(NodoAVL* raiz, int num){

    NodoAVL *arvAVL, *aux, *auxPai;

    arvAVL = (NodoAVL*) calloc(1, sizeof(NodoAVL));

    arvAVL -> num = num;
    arvAVL -> esq = NULL;
    arvAVL -> dir = NULL;
    arvAVL -> pai = NULL;
    arvAVL -> bal = 0;

    if(raiz -> dir == NULL){

        raiz -> dir = arvAVL;
        arvAVL -> pai = raiz;

		return;

    }

    aux = raiz -> dir;

    while(aux != NULL){

    	auxPai = aux;

        if (num < aux -> num) aux = aux -> esq;
        else aux = aux -> dir;

    }

    if(num < auxPai -> num) auxPai -> esq = arvAVL;
    else auxPai -> dir = arvAVL;

    arvAVL -> pai = auxPai;

    atualizarBal(arvAVL -> pai, num);

}

void leftRotate(NodoAVL *x){
    NodoAVL * y;
    y = (NodoAVL*)calloc(1,sizeof(NodoAVL));
    y=x->dir;
    x->dir=y->esq;
    if(y->esq!=NULL){
        y->esq->pai=x;
    }
    y->pai=x->pai;
    if(x->pai->num==-1000){
        x->pai->dir=y;
    }else{
        if(x==x->pai->esq){
            x->pai->esq=y;
        }else{
            x->pai->dir=y;
        }
    }
    y->esq=x;
    x->pai=y;
    x->bal=0;
    y->bal=0;
}

// Rotação à direita
void rightRotate(NodoAVL *x){
    NodoAVL * y;
    y = (NodoAVL*)calloc(1,sizeof(NodoAVL));
    y=x->esq;
    x->esq=y->dir;
    if(y->dir!=NULL){
        y->dir->pai=x;
    }
    y->pai=x->pai;
    if(x->pai->num==-1000){
        x->pai->dir=y;
    }else{
        if(x==x->pai->esq){
            x->pai->esq=y;
        }else{
            x->pai->dir=y;
        }
    }
    y->dir=x;
    x->pai=y;
    x->bal=0;
    y->bal=0;
}

// Verificar balancemaneto para inserção
void balanceamento(NodoAVL * nodoAVL){
    NodoAVL * filho;
    int netoBal;
    if(nodoAVL->bal==2){
        filho=nodoAVL->dir;
        // Rotação dupla direita-esquerda
        if(filho->bal < 0){
            netoBal = filho->esq->bal;
            rightRotate(filho);
            leftRotate(nodoAVL);
            // Operação pós rotação para rotação dupla
            if(netoBal == 1){
                nodoAVL->bal = -1;
            }
            if(netoBal == 1){
                nodoAVL->bal = 1;
            }
        // Rotação simples esquerda
        }else{
            leftRotate(nodoAVL);
        }
    }else{
        filho=nodoAVL->esq;
        // Rotação dupla esquerda-direita
        if(filho->bal > 0){
            netoBal = filho->dir->bal;
            leftRotate(filho);
            rightRotate(nodoAVL);
            // Operação pós rotação para rotação dupla
            if(netoBal == -1){
                nodoAVL->bal = 1;
            }
            if(netoBal == 1){
                nodoAVL->bal = -1;
            }
        // Rotação simples direita
        }else{
            rightRotate(nodoAVL);
        }
    }
}

// Atualiza balanceamento para inserção
void atualizarBal(NodoAVL* nodoAVL, int num){
    // Condição de parada -> chegou à num
    if(nodoAVL->num==-1000){
        return;
    }
    if(num>nodoAVL->num){
        nodoAVL->bal=nodoAVL->bal+1;
    }else{
        nodoAVL->bal=nodoAVL->bal-1;
    }
    // Condição de parada -> FB = 0
    if(nodoAVL->bal==0){
        return;
    }else{
        // Condição de parada -> Encontrou nó desbalanceado
        if(nodoAVL->bal==2 || nodoAVL->bal==-2){
            balanceamento(nodoAVL);
            return;
        }else{
            atualizarBal(nodoAVL->pai,num);
        }
    }
}

void liberarAVL(NodoAVL* raiz){

    if(raiz != NULL){

        liberarAVL(raiz -> esq);
        liberarAVL(raiz -> dir);
		free(raiz);

    }

}

// Verificar balancemaneto para remoção
// void balanceamentoRemocao(NodoAVL * nodoAVL){
//     NodoAVL * filho;
//     int filhoBal;
//     int netoBal;
//     if(nodoAVL->bal==2){
//         filho=nodoAVL->dir;
//         filhoBal=filho->bal;
//         // Rotação dupla direita-esquerda
//         if(filho->bal<0){
//             netoBal = filho->esq->bal;
//             rightRotate(filho);
//             leftRotate(nodoAVL);
//             // Operação pós rotação para rotação dupla
//             if(netoBal == 1){
//                 nodoAVL->bal = -1;
//             }
//             if(netoBal == 1){
//                 nodoAVL->bal = 1;
//             }
//         // Rotação simples esquerda
//         }else{
//             leftRotate(nodoAVL);
//             // Operação pós rotação para rotação simples
//             if(filhoBal == 0){
//                 nodoAVL->bal=1;
//                 filho->bal=-1;
//             }
//         }
//     }else{
//         filho=nodoAVL->esq;
//         filhoBal = filho->bal;
//         // Rotação dupla esquerda-direita
//         if(filho->bal>0){
//             netoBal = filho->dir->bal;
//             leftRotate(filho);
//             rightRotate(nodoAVL);
//             // Operação pós rotação para rotação dupla
//             if(netoBal == -1){
//                 nodoAVL->bal = 1;
//             }
//             if(netoBal == 1){
//                 nodoAVL->bal = -1;
//             }
//         }else{
//             // Rotação simples direita
//             rightRotate(nodoAVL);
//             // Operação pós rotação para rotação simples
//             if(filhoBal == 0){
//                 nodoAVL->bal=-1;
//                 filho->bal=1;
//             }
//         }
//     }
// }

// Atualiza balanceamento para remoção
// void atualizarBalRemocao(NodoAVL *nodoAVL,int num){
//     // Condição de parada -> Chegou à num
//     if(nodoAVL->num==-1000){
//         return;
//     }
//     if(num>nodoAVL->num){
//         nodoAVL->bal=nodoAVL->bal-1;
//     }else{
//         nodoAVL->bal=nodoAVL->bal+1;
//     }
//     if(nodoAVL->bal==2 || nodoAVL->bal==-2){
//         balanceamento(nodoAVL);
//         nodoAVL=nodoAVL->pai;
//         // Condição de parada -> Após balanceamento nó que desbaçanceou a árvore tem FB = 1 ou FB = -1
//         if(nodoAVL->bal==1 || nodoAVL->bal==-1){
//             return;
//         }
//     }else{
//         atualizarBalRemocao(nodoAVL->pai,num);
//     }

// }

// Obter elemento da extrema direita
// NodoAVL *maisDireita(NodoAVL *a){
// 	NodoAVL *aux = a;
// 	while(aux->dir) aux = aux->dir;
// 	return aux;
// }

// // Obter elemento da extrema esquerda
// NodoAVL *maisEsquerda(NodoAVL *a){
// 	NodoAVL *aux = a;
// 	while(aux->esq) aux = aux->esq;
// 	return aux;
// }

// // Ordem
void percorreOrdem (NodoAVL *A){
    if(A!=NULL){
        percorreOrdem(A->esq);
        printf(" %d ", A->num);
        percorreOrdem(A->dir);
    }
}


NodoAVL* buscaAVL(NodoAVL* raiz, int chave){

	if(raiz == NULL) return NULL;
	else if (raiz -> num > chave) return buscaAVL(raiz -> esq, chave);
	else if (raiz -> num < chave) return buscaAVL(raiz -> dir, chave);
	else return raiz;

}

// // PreOrdem
// void percorrePreOrdem(NodoAVL *A){
//     if(A!=NULL){
//         printf(" %d ", A->num);
//         percorrePreOrdem(A->esq);
//         percorrePreOrdem(A->dir);
//     }
// }