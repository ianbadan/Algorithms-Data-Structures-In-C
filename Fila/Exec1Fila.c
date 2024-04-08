#include <stdio.h>
#include <stdlib.h>
#define qtd 10

typedef struct batata{
    int dados[qtd];
    int inicio, fim;
} Fila;

void inicializaFila(Fila *f){
    f->fim=-1;
    f->inicio=0;
}

int filaCheia(Fila *f){
    if(f->fim==qtd-1){
        printf("Fila Cheia\n");
        return 1;
    }
    return 0;
}

int filaVazia(Fila *f){
    if(f->fim+1==f->inicio){
        printf("Fila Vazia\n");
        return 1;
    }
    return 0;
}

int enqueue(Fila *f, int valor){
    if(filaCheia(f)){
        return -1;
    }
    f->fim++;
    f->dados[f->fim]=valor;
    return f->fim;
}

int dequeue(Fila *f){
    if(filaVazia(f)){
        return -1;
    }
    f->inicio++;
    return f->dados[f->inicio-1];
}

void main(){
    Fila f;
    inicializaFila(&f);
    int i, valor;
    for(i=0;i<qtd;i++){
        printf("Num = %d, Fim = %d\n ", i+1, enqueue(&f,i+1));
    }
    for(i=0;i<qtd;i++){
        valor = dequeue(&f);
        printf("Num retirado = %d \n", valor);
    }
}
