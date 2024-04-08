#include<stdio.h>
#include<stdlib.h>

#define qtd 10

typedef struct batata{
    int dados[qtd];
    int fim;
} Lista;

void inicializaLista(Lista *l){
    l->fim=0;
}

int listaCheia(Lista *l){
    if(l->fim==qtd){
        printf("Lista Cheia\n");
        return 1;
    }
    return 0;
}

int listaVazia (Lista *l){
    if(l->fim == 0){
        printf("Lista Vazia\n");
        return 1;
    }
    return 0;

}

int inserirPosicao(Lista *l, int valor){
    if(listaCheia(l)){
        return -1;
    }
    if(l->fim==0){
    	l->dados[0]=valor;
    	return ++l->fim;
	}
    int i=0, j, aux;
    while(valor>l->dados[i] && i<l->fim){
    	i++;
	}
	for(j=l->fim;j>i;j--){
        l->dados[j]=l->dados[j-1];
    }
    l->dados[i]=valor;
    return ++l->fim;
}

int removerPosicao (Lista *l, int k){
    if(listaVazia(l)){ 
    return -1;
    }
    if(k<0 || k>=l->fim){
        printf("Posicao Invalida. Remova entre 0 e %d\n", l->fim);
        return -2;
    }
    int i,aux = l->dados[k];
    for(i=k ; i< l->fim-1; i++){
        l->dados[i]=l->dados[i+1];
    }
    l->fim --;
    return aux;
}

int removerInicio (Lista *l){
    return removerPosicao(l,0);
}

int removerFim (Lista *l){
    return removerPosicao (l,l->fim-1);
}

int tamanhoLista (Lista *l){
    return l->fim;
}

void imprimirLista(Lista *l){
	int i=0;
	printf("Elementos da Lista: ");
	while(i<l->fim){
		printf("%d ", l->dados[i]);
		i++;
	}
	printf("\n");
}

void main(){
	Lista l;
	int i, valor, pos;
	inicializaLista(&l);
	while(!listaCheia(&l)){
		printf("Insira um valor: ");
		scanf("%d", &valor);
		inserirPosicao(&l, valor);
		imprimirLista(&l);
	}
	while(!listaVazia(&l)){
		printf("Escolha uma posicao a ser removida: ");
		scanf("%d", &pos);
		removerPosicao(&l, pos);
		imprimirLista(&l);
	}
}
