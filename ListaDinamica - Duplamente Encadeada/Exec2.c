#include <stdio.h>
#include <stdlib.h>

#define TIPO int

typedef struct no{
    int dado;
    struct no *prox, *ant;
} No;

typedef struct batata{
    int qtd;
    No *inicio, *fim;
}Lista;

void inicializaLista(Lista *l);
int listaVazia(Lista *l);
int testarPosicao(Lista *l, int k);
No* buscaNumero(Lista *l, int pos);
No* buscaPosicao(Lista *l, int pos);
int inserirVazia(Lista *l, int valor);
int inserirInicio(Lista *l, int valor);
int inserirFim(Lista *l, int valor);
int inserirCrescente(Lista *l, int valor);
int removerUm(Lista *l);
int removerInicio(Lista *l);
int removerFim(Lista *l);
int removerPosicao(Lista *l, int pos);
void verFim(Lista *l);
void finalizaLista(Lista *l);
void imprimirLista(Lista *l);

void main(){
    Lista *l=malloc(sizeof(Lista));
    inicializaLista(l);
    int i=0;
    while(i>-1){
        printf("Informe o valor: ");
        scanf("%d", &i);
        inserirCrescente(l, i);
    }
    imprimirLista(l);
}

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

int testarPosicao(Lista *l, int k){
    if(k>=0 && k<=l->qtd){
        return 1;
    }
    return 0;
}

No* buscaNumero(Lista *l, int valor){
    No *nav=l->fim;
    while(valor<nav->dado){
        nav=nav->ant;
        }
    return nav;
}

No* buscaPosicao(Lista *l, int pos){
    if(!testarPosicao(l,pos)) return NULL;
    No *nav;
    int i;
    if(pos<=l->qtd/2){
        nav=l->inicio;
        for(i=0;i<=pos;i++){
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
    No *novo=malloc(sizeof(No));
    novo->dado=valor;
    l->inicio=novo;
    l->fim=novo;
    novo->prox=NULL;
    novo->ant=NULL;
    return ++l->qtd;
}

int inserirInicio(Lista *l, int valor){
    if(listaVazia(l)){
       return inserirVazia(l, valor);
    }
    No *novo=malloc(sizeof(No));
    novo->dado=valor;
    l->inicio->ant=novo;
    novo->prox=l->inicio;
    novo->ant=NULL;
    l->inicio=novo;
    return ++l->qtd;
}

int inserirFim(Lista *l, int valor){
    if(listaVazia(l)){
        return inserirVazia(l, valor);
    }
    No *novo=malloc(sizeof(No));
    novo->dado=valor;
    l->fim->prox=novo;
    novo->ant=l->fim;
    novo->prox=NULL;
    l->fim=novo;
    return ++l->qtd;
}

int inserirCrescente(Lista *l, int valor){
    if(listaVazia(l)){
        return inserirVazia(l, valor);
    }
    if(valor<=l->inicio->dado){
        return inserirInicio(l, valor);
    }
    if(valor>=l->fim->dado){
        return inserirFim(l, valor);
    }
    No* novo=malloc(sizeof(No));
    novo->dado=valor;
    No *aux=buscaNumero(l,valor);
    novo->prox=aux->prox;
    novo->ant=aux;
    aux->prox->ant=novo;
    aux->prox=novo;
    return ++l->qtd;
}

int removerUm(Lista *l){
    int aux=l->inicio->dado;
    free(l->inicio);
    l->inicio=NULL;
    l->fim=NULL;
    l->qtd--;
    return aux;
}

int removerInicio(Lista *l){
    if(listaVazia(l)){
        printf("Lista Vazia\n");
        return -2;
    }
    if(l->qtd==1){
        return removerUm(l);
    }
    int aux=l->inicio->dado;
    No *lixo=l->inicio;
    lixo->prox->ant=NULL;
    l->inicio=lixo->prox;
    free(lixo);
    lixo=NULL;
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

int removerPosicao(Lista *l, int pos){

    if(listaVazia(l)){
        printf("Lista Vazia\n");
        return -1;
    }
    if(!testarPosicao(l,pos-1)){
        printf("Posicao Invalida, escolha entre 0 e %d\n", l->qtd-1);
        return -2;
    }
    if(pos==0){
       return removerInicio(l);
    }
    if(pos==l->qtd-1){
        return removerFim(l);
    }
    No *lixo=buscaPosicao(l,pos);
    int aux=lixo->dado;
    lixo->ant->prox=lixo->prox;
    lixo->prox->ant=lixo->ant;
    free(lixo);
    lixo=NULL;
    l->qtd--;
    return aux;
}

void verFim(Lista *l){
    printf("O fim eh: %d", l->fim->dado);
}

void finalizaLista(Lista *l){
    while(!listaVazia){
        removerInicio(l);
    }
    free(l);
    l=NULL;
    printf("\nLista Finalizada\n");
}

void imprimirLista(Lista *l){
    int i;
    printf("Lista: ");
    No* nav=l->inicio;
    for(i=0;i<l->qtd;i++){
        printf("%d ", nav->dado);
        nav=nav->prox;
    }
}
