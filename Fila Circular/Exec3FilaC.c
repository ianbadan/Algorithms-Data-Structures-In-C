#include<stdio.h>
#include<stdlib.h>

#define qtd 10

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

int tamanhoFila(FilaC *f){
    if(f->fim >= f->inicio) return f->fim - f->inicio;
    return (f->fim+qtd) - f->inicio;
}
void main(){
    int i, valor;
    FilaC f;
    inicializaFilaC(&f);
    printf("%d\n", tamanhoFila(&f));
    for(i=0;i<qtd-1;i++){
        valor=rand()%100;
        printf("Fim: %d\n", enqueue(&f, valor));
    }
    printf("%d\n", tamanhoFila(&f));
    for(i=0;i<3;i++){
        printf("Valor Retirado: %d\n", dequeue(&f));
    }
    for(i=0;i<1;i++){
        valor=rand()%100;
        printf("Fim: %d\n", enqueue(&f, valor));
    }
    printf("%d\n", tamanhoFila(&f));
}

