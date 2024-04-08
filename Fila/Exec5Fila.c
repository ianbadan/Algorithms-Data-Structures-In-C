#include <stdio.h>
#include <stdlib.h>
#define qtd 15

typedef struct batata{
    int dados[qtd];
    int fim;
} Fila;

void inicializaFila(Fila *f){
    f->fim=-1;
}

int filaCheia(Fila *f){
    if(f->fim==qtd-1){
        printf("Fila Cheia\n");
        return 1;
    }
    return 0;
}

int filaVazia(Fila *f){
    if(f->fim==-1){
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
    int i, aux;
    aux=f->dados[0];
    for(i=1;i<=f->fim;i++){
        f->dados[i-1]=f->dados[i];
    }
    f->fim--;
    return aux;
}

int verificaTamanho(Fila *f){
    return f->fim+1;
}

void main(){
    Fila f1; 
	Fila f2;
    inicializaFila(&f1);
    inicializaFila(&f2);
    int i, valor;
    printf("Informe 15 valores\n");
    for(i=0;i<qtd;i++){
    	scanf("%d", &valor);
        enqueue(&f1, valor);
    }
    printf("\nOrdem Inversa\n");
    while(!filaVazia(&f1)){
        while(verificaTamanho(&f1)!=1){
            enqueue(&f2, dequeue(&f1));
        }
        printf("%d\n", dequeue(&f1));
        memcpy(&f1, &f2, sizeof f1);
        inicializaFila(&f2);
    }

}

