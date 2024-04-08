//Versão que aponta tanto pro inicio quanto pro fim da lista
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
} No;

typedef struct batata{
    int qtd;
    No* inicio;
    No* fim;
} Lista;

void inicializaLista(Lista *l){
    l->qtd=0;
    l->inicio=NULL;
    l->fim=NULL;
}

int listaVazia(Lista *l){
	if(l->qtd==0){
		return 1;
	}
	return 0;
}

void finalizaLista(Lista *l){
	while(!listaVazia){
		removerInicio(l);
	}
	free(l);
	l=NULL;
	printf("Lista Finalizada\n");
}

void verInicio(Lista *l){
	printf("Inicio da Lista eh: %d\n", l->inicio->valor);
}

void verFim(Lista *l){
	if(listaVazia(l)){
		printf("Lista Vazia\n");
	} else{
		printf("Fim da Lista eh: %d\n", l->fim->valor);
	}
	
}

int testarPosicao(Lista *l, int k){
    if(k>=0 && k<l->qtd){
        return 1;
    }
    return 0;
}

No* buscaPosicao(Lista *l, int k){
    if(!testarPosicao(l, k)) return NULL;
    No *nav=l->inicio;
    int i;
    for(i=0;i<k;i++){
        nav=nav->proximo;
    }
    return nav;

}

int verPosicao(Lista *l, int k){
	No *nav=buscaPosicao(l, k);
	return nav->valor;
}

int inserirPosicao(Lista *l, int v, int k){
    if(testarPosicao(l,k) && k!=0 ) return -1;
    No *novo= malloc(sizeof(No));
    novo->valor=v;
    if(listaVazia(l)){
    	novo->proximo=l->inicio;
        l->inicio=novo;
        l->fim=novo;
        return ++l->qtd;
	}
	if(k==l->qtd){
		inserirFim(l, v);
		return l->qtd;
	}
    if(k==0){
        novo->proximo=l->inicio;
        l->inicio=novo;
    } else{
		No *nav=buscaPosicao(l,k-1);
    	novo->proximo=nav->proximo;
   		nav->proximo=novo;
	}
    return ++l->qtd;
}

int inserirInicio(Lista *l, int valor){
    return inserirPosicao(l, valor, 0);
}

int inserirFim(Lista *l, int v){
	No* novo=malloc(sizeof(No));
	novo->valor=v;
	novo->proximo=l->fim->proximo;
	l->fim->proximo=novo;
	l->fim=novo;
	return ++l->qtd;
}

int removerPosicao(Lista *l, int k){
    if(!testarPosicao(l,k)) return -2;
    No *nav;
    int aux;
    if(k==0){
        nav=l->inicio;
        aux=nav->valor;
        l->inicio=nav->proximo;
        free(nav);
        nav=NULL;
    } else{
        nav=buscaPosicao(l, k-1);
        No *lixo=nav->proximo;
        nav->proximo=lixo->proximo;
        aux=lixo->valor;
        if(k==l->qtd-1){
        	l->fim=nav;
		}
        free(lixo);
        lixo=NULL;
    }
    l->qtd--;
    return aux;
}

int removerInicio(Lista *l){
    return removerPosicao(l, 0);
}

int removerFim(Lista *l){
    return removerPosicao(l, l->qtd-1);
}

void imprimirLista(Lista *l){
    int i;
    No *nav=l->inicio;
    for(i=0;i<l->qtd;i++){
        printf("%d ", nav->valor);
        nav=nav->proximo;
    }
    printf("\n");
}

void verQtd(Lista *l){
	printf("A lista tem %d elementos\n", l->qtd);
}
void main(){
    Lista *l=malloc(sizeof(Lista));
    inicializaLista(l);
    int i=0, k;
    for(i=0;i<5;i++){
        inserirPosicao(l, i, i);
    }
    imprimirLista(l);
    verQtd(l);
    verFim(l);
    inserirFim(l, 10);
    verQtd(l);
	verFim(l);
	imprimirLista(l);
	removerFim(l);
	verQtd(l);
	verFim(l);
    imprimirLista(l);
}
