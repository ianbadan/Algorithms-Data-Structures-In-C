#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define qtd 6

typedef struct batata{
    int dados[qtd];
    int topo;
}Pilha;

void inicializaPilha(Pilha *p){
    p->topo=1;
}

int pilhaCheia (Pilha *p){
    if(p->topo == qtd){
        return 1;
    }
    return 0;
}

int pilhaVazia(Pilha *p){
    if(p->topo == 1){
        return 1;
    }
    return 0;
}

int empilha(Pilha *p, int valor){
    if(pilhaCheia(p)){
        printf("Pilha Cheia\n");
        return -1;
    }
    p->dados[p->topo]=valor;
    p->topo++;
    return p->topo;
}

int desempilha(Pilha *p){
    if(pilhaVazia(p)){
        printf("Pilha Vazia\n");
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
    int valor, i;
    while(1){
        printf(" 1- Empilha\n 2- Desempilha\n 3-Acessar Topo\n 0- Finalizar programa\n");
        i=getch();
        switch(i){
            case 0: exit(0);
            break;
            case 1: printf("Digite o valor a ser inserido: ");
                    scanf("%d", &valor);
                    empilha(&p, valor);
            break;
            case 2: valor = desempilha(&p);
                    printf("O valor retirado foi %d\n", valor);
            break;
            case 3: valor=acessaTopo(&p);
                    printf("O valor do topo e %d\n", valor);
            break;
            default:;

        }
    }

}

