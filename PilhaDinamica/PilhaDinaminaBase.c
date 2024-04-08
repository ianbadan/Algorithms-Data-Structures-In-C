#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
} No;

typedef struct batata{
    No *topo;
    int qtd;
} Pilha;

void inicilizaPilha(Pilha *p){
    p->topo=NULL;
    p->qtd=0;
}
int empilhar(Pilha *p,int v){
    No *novo;
    novo=malloc(sizeof(No));
    novo->valor= v;
    novo->proximo= p->topo;
    p->topo=novo;
    return ++p->qtd;
}

int pilhaVazia(Pilha *p){
    if(p->topo==NULL){
        printf("\nPilha Vazia\n");
        return 1;
    }
    return 0;
}

int desempilhar(Pilha *p){
    if(pilhaVazia(p)){
        return -1;
    }
    No *t= p->topo;
    p->topo=t->proximo;
    p->qtd--;
    int aux= t->valor;
    free(t);
    t=NULL;
    return aux;
}

int verificaTopo(Pilha *p){
    return p->topo->valor;
}

int verificaTamanho(Pilha *p){
    return p->qtd;
}
