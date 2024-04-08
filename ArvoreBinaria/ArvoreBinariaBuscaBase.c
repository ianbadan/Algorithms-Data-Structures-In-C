#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
    int chave;
    struct no *esquerda, *direita;
} No;

typedef struct arvorebi{
    No* raiz;
    int qtd;
} ArvoreBi;

void delay(int segundos) { 
    int milisegundos = 1000 * segundos; 
  
    clock_t inicio = clock(); 
  
    while (clock() < inicio + milisegundos) 
        ; 
} 

int inicializaArvoreBi(ArvoreBi *a){
    a->raiz=NULL;
    a->qtd=0;
    return 0;
}

int ArvoreBiVazia(ArvoreBi *a){
    if(a->raiz==NULL){
        return 1;
    }
    return 0;
}

int insereRaiz(ArvoreBi *a, int valor){
    if(!ArvoreBiVazia(a)){
        return -2;
    }
    No *novo=malloc(sizeof(No));
    novo->chave=valor;
    novo->esquerda=NULL;
    novo->direita=NULL;
    a->raiz=novo;
    a->qtd++;
    return 0;
}

int inserirFolha(No *raiz, int valor){
    if(valor > raiz->chave){
        if(raiz->direita==NULL){
            No* novo=malloc(sizeof(No));
            novo->chave=valor;
            novo->esquerda=NULL;
            novo->direita=NULL;
            raiz->direita=novo;
            return 0;
        } else{
            return inserirFolha(raiz->direita, valor);
        }
    }
    if(valor < raiz->chave){
        if(raiz->esquerda==NULL){
            No *novo= malloc(sizeof(No));
            novo->chave=valor;
            novo->esquerda=NULL;
            novo->direita=NULL;
            raiz->esquerda=novo;
            return 0;
        } else{
            return inserirFolha(raiz->esquerda, valor);
        }
    }
    return 1;
}

int inserirArvore(ArvoreBi *a, int valor){
    if(ArvoreBiVazia(a)){
        insereRaiz(a, valor);
        return 0;
    }
    if(inserirFolha(a->raiz, valor)){
     return -1;
    }
    a->qtd++;
    return 0;
}

int busca(No *raiz, int valor){
    if(raiz==NULL){
        return 1;
    }
    if(raiz->chave==valor){
        return 0;
    }
    if(valor > raiz->chave){
        return busca(raiz->direita, valor);
    }
    if(valor < raiz->chave){
        return busca(raiz->esquerda, valor);
    }
}

No* removerNo(No *raiz, int valor){

	if(raiz == NULL) {
		return raiz;
	}
	if(valor<raiz->chave) {
        raiz->esquerda = removerNo(raiz->esquerda,valor);
    }else if(valor>raiz->chave){
        raiz->direita = removerNo(raiz->direita,valor);
    } 
    else{
        if(raiz->esquerda == NULL){
        	No *aux=raiz->direita;
        	free(raiz);
        	return aux;
        } else if(raiz->direita == NULL){
                No *aux=raiz->esquerda;
        		free(raiz);
        		return aux;
		}
        No *nav=raiz->direita;
        while(nav->esquerda != NULL){
            nav=nav->esquerda;
        }
        raiz->chave=nav->chave;
        raiz->direita = removerNo(raiz->direita, nav->chave);
	}
	return raiz;
}

int remover(ArvoreBi *a, int valor){
    if(ArvoreBiVazia(a)){
        printf("Arvore vazia");
        return -2;
    }
    if(busca(a->raiz, valor)){
        printf("Numero inexistente na arvore");
        return -3;
    }
    if(a->raiz->chave==valor){
    a->raiz=removerNo(a->raiz,valor);
    }
    removerNo(a->raiz,valor);
    a->qtd--;
    return 0;
}

int alturaNo(No *raiz){
    if(raiz==NULL){
        return -1;
    }
    if(alturaNo(raiz->esquerda)>alturaNo(raiz->direita)){
        return alturaNo(raiz->esquerda)+1;
    } else {
        return alturaNo(raiz->direita)+1;
    }
}

void imprimirPreOrdem(No *raiz){
    if(raiz==NULL){
        return;
    }
    printf("%d ", raiz->chave);
    imprimirPreOrdem(raiz->esquerda);
    imprimirPreOrdem(raiz->direita);
}

void imprimirEmOrdem(No *raiz){
    if(raiz==NULL){
        return;
    }
    imprimirEmOrdem(raiz->esquerda);
    printf("%d ", raiz->chave);
    imprimirEmOrdem(raiz->direita);
}

void imprimirPosOrdem(No *raiz){
    if(raiz==NULL){
        return;
    }
    imprimirPosOrdem(raiz->esquerda);
    imprimirPosOrdem(raiz->direita);
    printf("%d ", raiz->chave);

}

void VerificaValor(No* raiz, int n){
	int QtdNos = ContaNos(raiz, n);
	if(QtdNos > 30000){
		printf("Numero nao encontrado apos visitar %d nos", (QtdNos-30001));
	} 
	else{
		printf("Numero encontrado apos visitar %d nos", QtdNos);
	}
}

int ContaNos(No *raiz, int n){
	if(raiz == NULL){
        return 30000;
    }
	if(raiz->chave == n){
		return 1;
	}
    if(raiz->chave > n){
        return ContaNos(raiz->esquerda, n)+1;
    } else {
        return ContaNos(raiz->direita, n)+1;
    }
}
void finalizaArvore(No *raiz){
    if(raiz==NULL){
        return;
    }
    finalizaArvore(raiz->esquerda);
    finalizaArvore(raiz->direita);
    free(raiz);
    raiz=NULL;

}

void main(){
    ArvoreBi *arvore=malloc(sizeof(ArvoreBi));
    inicializaArvoreBi(arvore);
    int n, i, x, desejado;
	
	printf("Quantos numeros serao inseridos na arvore: \n");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		printf("Digite o %d numero: ", i+1);
		scanf("%d", &x);
		inserirArvore(arvore, x);
	}
	
	printf("Qual numero voce deseja procurar na arvore? \n");
	scanf("%d", &desejado);
	
	VerificaValor(arvore->raiz, desejado);
	
	finalizaArvore(arvore->raiz);
	free(arvore);
	arvore = NULL;
}
