#include<stdio.h>
#include<stdlib.h>

#define qtd 10

typedef struct batataC{
    int dados;
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
    f->fim=(f->fim+1)%qtd;
    return f->fim;
}

int dequeue(FilaC *f){
    if(filaVazia(f)){
        return -1;
    }
    int aux=f->dados[f->inicio];
    f->inicio=(f->inicio+1)%qtd;
    return aux;
}
