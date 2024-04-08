/*n�o conhecemos o fim, para se 
fazer uma inser��o, � necess�rio navegar por todos 
os elementos desde o in�cio e reapontar o pr�ximo 
do �ltimo elemento*/
#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int valor;
    struct no *proximo;
} No;

typedef struct batata{
    No *inicio;
    int qtd;
}Fila;

void inicializaFila(Fila *f){
    f->inicio=NULL;
    f->qtd=0;
}

void finalizaFila(Fila *f){
	while(!filaVazia(f)){
		dequeue(f);
	}
	free(f);
	f=NULL;
	printf("Fila Finalizada\n");
}

int filaVazia(Fila *f){
    if(f->inicio==NULL){
        return 1;
    }
    return 0;
}

int enqueue(Fila *f, int v){
    No* novo;
    novo=malloc(sizeof(No));
    novo->valor=v;
    novo->proximo=NULL;
    if(filaVazia(f)){
        f->inicio=novo;
    } else{
        No *aux = f->inicio;
        while (aux->proximo!=NULL){
            aux=aux->proximo;
        }
        aux->proximo=novo;
    }
    return ++f->qtd;
}

int dequeue(Fila *f){
    if(filaVazia(f)){
        printf("\nFila Vazia\n");
        return -1;
    }
    No *i=f->inicio;
    f->inicio=i->proximo;
    int aux= i->valor;
    free(i);
    i=NULL;
    f->qtd--;
    return aux;
}

int verQuantidade(Fila *f){
	return f->qtd;
}

void verInicio(Fila *f){
	if(filaVazia(f)){
		printf("\n\tFila Vazia\n");
	} else{
		printf("O inicio eh: %d\n", f->inicio->valor);
	}
}

void main(){
	
}
