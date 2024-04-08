#include<stdio.h>
#include<stdlib.h>

#define qtd 10

typedef struct batata{
    int dados[qtd];
    int fim;
}Lista;

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

int inserirPosicao(Lista *l, int valor, int pos){
    if(listaCheia(l)){
        return -1;
    }
    if(pos<0 || pos>l->fim){
        printf("Posicao Invalida. Insira entre 0 e %d\n", l->fim);
        return -2;
    }
    int i;
    for(i=l->fim;i>pos;i--){
        l->dados[i]=l->dados[i-1];
    }
    l->dados[pos]=valor;
    return ++l->fim;
}

int inserirPosicao2(Lista *l, int valor){
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

int inserirInicio(Lista *l, int valor){
    return inserirPosicao(l, valor, 0);
}

int inserirFim(Lista *l, int valor){
    return inserirPosicao(l, valor, l->fim);
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
	int aux, valor;
	Lista l1, l2, l3;
	inicializaLista(&l1);
	inicializaLista(&l2);
	inicializaLista(&l3);
	while(!listaCheia(&l1)){
		printf("Insira um valor: ");
		scanf("%d", &valor);
		inserirFim(&l1, valor);
	}
	imprimirLista(&l1);
	while(!listaVazia(&l1)){
		aux=removerFim(&l1);
		if(aux%2==0){
			inserirPosicao2(&l2, aux);
		} else {
			inserirPosicao2(&l3,aux);
		}
	}
	printf("\t\t Pares\n");
	imprimirLista(&l2);
	printf("\t\t Impares\n");
	imprimirLista(&l3);
}
