#include <stdio.h>
#include <stdlib.h>
#define qtd 10

int dados[qtd];
int fim;

void inicializaFila(){
    fim=-1;
}

int filaCheia(){
    if(fim==qtd-1){
        printf("Fila Cheia\n");
        return 1;
    }
    return 0;
}

int filaVazia(){
    if(fim==-1){
        printf("Fila Vazia\n");
        return 1;
    }
    return 0;
}

int enqueue(int valor){
    if(filaCheia()){
        return -1;
    }
    fim++;
    dados[fim]=valor;
    return fim;
}

int dequeue(){
    if(filaVazia()){
        return -1;
    }
    int i, aux;
    aux=dados[0];
    for(i=1;i<=fim;i++){
        dados[i-1]=dados[i];
    }
    fim--;
    return aux;
}

int verificaTamanho(){
    return fim;
}

void main(){
    inicializaFila();
    int i, valor;
    for(i=0;i<qtd;i++){
        printf("Num = %d, Fim = %d\n ", i+1, enqueue(i+1));
    }
    for(i=0;i<qtd;i++){
        valor = dequeue();
        printf("Num retirado = %d \n", valor);
    }
}

