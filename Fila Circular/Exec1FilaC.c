#include<stdio.h>
#include<stdlib.h>

#define qtd 11

typedef struct batataC{
    int dados[qtd];
    int inicio;
    int fim;
} FilaC;

void inicializaFilaC(FilaC *f){
    f->inicio=0;
    f->fim=0;
}

int filaCheia(FilaC *f){
    if((f->fim+1)%qtd==f->inicio){
        printf("Fila Cheia\n");
        return 1;
    }
    return 0;
}

int filaVazia(FilaC *f){
    if(f->fim==f->inicio){
        printf("Fila Vazia\n");
        return 1;
    }
    return 0;
}

int enqueue (FilaC *f, int valor){
    if(filaCheia(f)){
        return -1;
    }
    f->dados[f->fim]=valor;
    if(f->fim ==qtd-1){
        f->fim=0;
    } else {
        f->fim++;
    }
    return f->fim;
}

int dequeue(FilaC *f){
    if(filaVazia(f)){
        return -1;
    }
    if(f->inicio == qtd-1){
        f->inicio=0;
    } else {
        f->inicio++;
    }
    return f->inicio;
}

void main(){
    FilaC f;
    inicializaFilaC(&f);
    int i, valor;
    for(i=0;i<qtd-1;i++){
        valor=rand()%100;
        printf("Numero: %d Fim: %d\n", valor, enqueue(&f, valor));
    }
    for(i=0;i<qtd-1;i++){
        printf("Topo: %d\n", dequeue(&f));
    }
}
