#include <stdio.h>
#include <stdlib.h>

#define quant 10

typedef struct no{
    int valor;
    struct no *proximo;
} No;

typedef struct batata{
    No *inicio;
    No* fim;
    int qtd;
}Fila;

void inicializaFila(Fila *f){
    f->inicio=NULL;
    f->qtd=0;
    f->fim=NULL;
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
        f->fim->proximo=novo;
    }
    f->fim=novo;
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
	No *i=f->inicio;
	if(filaVazia(f)){
		printf("\nFila Vazia\n");
	} else{
		printf("O inicio eh: %d\n", i->valor);
	}
}
void main(){
	Fila *f;
	f=malloc(sizeof(Fila));
	inicializaFila(f);
	int i, valor;
	for(i=0;i<quant;++i){
		scanf("%d", &valor);
		enqueue(f, valor);
		verInicio(f);
	}
	for(i=0;i<quant;++i){
		dequeue(f);
		verInicio(f);
	}
	finalizaFila(f);
}
