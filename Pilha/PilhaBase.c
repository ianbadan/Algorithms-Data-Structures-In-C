#include <stdio.h>
#include <stdlib.h>
#define qtd 6

typedef struct batata{
    int dados[qtd];
    int topo;
}Pilha;

void inicializaPilha(Pilha *p){
    p->topo=0;
}

int pilhaCheia (Pilha *p){
    if(p->topo == qtd){
        return 1;
    }
    return 0;
}

int pilhaVazia(Pilha *p){
    if(p->topo == 0){
        return 1;
    }
    return 0;
}

int empilha(Pilha *p, int valor){
    if(pilhaCheia(p)){
        printf("Pilha Cheia");
        return -1;
    }
    p->dados[p->topo]=valor;
    p->topo++;
    return p->topo;
}

int desempilha(Pilha *p){
    if(pilhaVazia(p)){
        printf("Pilha Vazia");
        return -1;
    }
    p->topo--;
    return p->dados[p->topo];
}

int acessaTopo(Pilha *p){
    if(pilhaVazia(p)){
        printf("Pilha Vazia");
        return -1;
    }
    return p->dados[p->topo-1];
}

int main(){
    Pilha p;
    inicializaPilha(&p);

}
