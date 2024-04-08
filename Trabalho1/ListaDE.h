#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Criado por Ian Mendes Badan
*/

typedef struct no{
    int dado;
    struct no *prox, *ant;
}No;

typedef struct batata{
    int qtd;
    No *inicio, *fim;
    int inicializada;
}Lista;

void inicializaLista(Lista *l);
int listaVazia(Lista *l);
int testarPosicao(Lista *l, int k);
No* buscaPosicao(Lista *l, int pos);
int inserirVazia(Lista *l, int valor);
int inserirFim(Lista *l, int valor);
void preencheLista(Lista *l, int tipo, int tamanho);
int removerUm(Lista *l);
int removerFim(Lista *l);
int contaNos(No* inicio,No* fim);
void esvaziaLista(Lista *l);
void finalizaLista(Lista *l);
void imprimirLista(Lista *l);

void inicializaLista(Lista *l){
    l->qtd=0;
    l->inicio=NULL;
    l->fim=NULL;
    l->inicializada=0;
}

int listaVazia(Lista *l){
    if(l->inicio==NULL){
        return 1;
    }
    return 0;
}

int testarPosicao(Lista *l, int k){
    if(k>=0 && k<=l->qtd){
        return 1;
    }
    return 0;
}

No* buscaPosicao(Lista *l, int pos){
    if(!testarPosicao(l,pos)) return NULL;
    No *nav;
    int i;
    if(pos<l->qtd/2){
        nav=l->inicio;
        for(i=0;i<pos;i++){
        nav=nav->prox;
        }
    } else{
        nav=l->fim;
        for(i=l->qtd-1;i>pos;i--){
            nav=nav->ant;
        }
    }
    return nav;
}

int inserirVazia(Lista *l, int valor){
    No *novo=(No*)malloc(sizeof(No));
    novo->dado=valor;
    novo->prox=NULL;
    novo->ant=NULL;
    l->inicio=novo;
    l->fim=novo;
    return ++l->qtd;
}

int inserirFim(Lista *l, int valor){
    if(listaVazia(l)){
        return inserirVazia(l, valor);
    }
    No *novo=(No*)malloc(sizeof(No));
    novo->dado=valor;
	l->fim->prox=novo;
    novo->ant=l->fim;
    novo->prox=NULL;
    l->fim=novo;
    return ++l->qtd;
}

void preencheLista(Lista *l, int tipo, int tamanho){
    int i, valor, k;
    srand((unsigned int) clock());
    //srand((unsigned int) time(NULL));
    switch(tipo){
        case 1:
            for(i=0;i<tamanho;i++){
                inserirFim(l,i);
            }
        break;
        case 2:
            for(i=tamanho;i>0;i--){
                inserirFim(l,i);
            }
        break;
        case 3:
            for(i=0;i<tamanho;i++){
                valor=rand();
                inserirFim(l, valor);
            }
        break;
        case 4:
            for(i=0;i<tamanho;i++){
                valor=rand()%100;
                inserirFim(l, valor);
            }
        break;
    }
}

int removerUm(Lista *l){
    int aux=l->inicio->dado;
    free(l->inicio);
    l->inicio=NULL;
    l->fim=NULL;
    l->qtd--;
    return aux;
}

int removerFim(Lista *l){
    if(listaVazia(l)){
        printf("Lista Vazia\n");
        return -2;
    }
    if(l->qtd==1){
        return removerUm(l);
    }
    int aux=l->fim->dado;
    No *lixo=l->fim;
    lixo->ant->prox=NULL;
    l->fim=lixo->ant;
    free(lixo);
    lixo=NULL;
    l->qtd--;
    return aux;
}

void esvaziaLista(Lista *l){
    while(!listaVazia(l)){
        removerFim(l);
    }
}

void finalizaLista(Lista *l){
    while(!listaVazia(l)){
        removerFim(l);
    }
    l->inicializada=1;
    free(l);
    l=NULL;
    printf("\nLista Finalizada\n");
}

void imprimirLista(Lista *l){
    int i;
    if(l->inicializada!=0){
        printf("\nLista nao inicializada\n");
        return;
    }
    if(listaVazia(l)){
        printf("\nLista Vazia\n");
        return;
    }
    No* nav=l->inicio;
    for(i=0;i<l->qtd;i++){
        printf("%d ", nav->dado);
        nav=nav->prox;
    }
}

int contaNos(No* inicio,No* fim){
	int qtd=0;
	No* nav=inicio;
	while (nav!=fim){
		nav=nav->prox;
		qtd++;
	}
	return qtd;
}
