#include <stdio.h>
#include <stdlib.h>
#define qtd 6

char dados[qtd];
int topo;

void inicializaPilha(int topo){
    topo=0;
}

int pilhaCheia (int topo){
    if(topo == qtd){
        return 1;
    }
    return 0;
}

int pilhaVazia(int topo){
    if(topo == 0){
        return 1;
    }
    return 0;
}

int empilha(int *dados, int topo, int valor){
    if(pilhaCheia(topo)){
        printf("Pilha Cheia\n");
        return -1;
    }
    dados[topo]=valor;
    topo++;
    return topo;
}

int desempilha(int *dados, int topo){
    if(pilhaVazia(topo)){
        printf("Pilha Vazia\n");
        return -1;
    }
    topo--;
    return dados[topo];
}

int acessaTopo(int *dados, int topo){
    if(pilhaVazia(topo)){
        printf("Pilha Vazia\n");
        return -1;
    }
    return dados[topo-1];
}

int main(){
    inicializaPilha(topo);
    int valor, i;
    while(1){
        printf(" 1- Empilha\n 2- Desempilha\n 3-Acessar Topo\n 0- Finalizar programa\n");
        scanf("%d", &i);
        switch(i){
            case 0: exit(0);
            break;
            case 1: printf("Digite o valor a ser inserido: ");
                    scanf("%d", &valor);
                    empilha(dados, topo, valor);
            break;
            case 2: valor = desempilha(dados, topo);
                    printf("O valor retirado foi %d\n", valor);
            break;
            case 3: valor=acessaTopo(dados, topo);
                    printf("O valor do topo e %d\n", valor);
            break;
            default:;

        }
    }

}

