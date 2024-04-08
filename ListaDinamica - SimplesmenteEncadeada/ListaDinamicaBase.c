//Versao que so aponta para o começo
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
} No;

typedef struct batata{
    int qtd;
    No* inicio;
} Lista;

void inicializaLista(Lista *l){
    l->qtd=0;
    l->inicio=NULL;
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

int verInicio(Lista *l){
	return l->inicio->valor;
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
    if(k==0){
        novo->proximo=l->inicio;
        l->inicio=novo;
        return ++l->qtd;
    }
    No *nav=buscaPosicao(l,k-1);
    novo->proximo=nav->proximo;
    nav->proximo=novo;
    return ++l->qtd;
}

int inserirInicio(Lista *l, int valor){
    return inserirPosicao(l, valor, 0);
}

int inserirFim(Lista*l, int valor){
    return inserirPosicao(l,valor, l->qtd);
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

void main(){
    Lista *l=malloc(sizeof(Lista));
    inicializaLista(l);
    int i=0, k;
    while(i>-1){
        scanf("%d", &i);
        inserirInicio(l, i);
    }
    inserirFim(l, 10);
    imprimirLista(l);
    while(!listaVazia(l)){
    	printf("%d ", removerFim(l));
	}
}
