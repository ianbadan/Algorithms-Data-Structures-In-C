#include <stdio.h>
#include <stdlib.h>
/*Criado por Ian Mendes Badan
*/

void selectionSort(Lista *l){
    No * min;
    No * i = l->inicio;
    No * j;
    int aux;

    while(i->prox!=NULL){
        min = i;
        j = i->prox;
        while(j!=NULL){
            if(min->dado > j->dado){
                min = j;
            }
            j = j->prox;
        }
        if(i != min){
            aux=i->dado;
            i->dado = min->dado;
            min->dado = aux;
        }
        i=i->prox;
    }
}

void insertionSort(Lista *l){
    No* i;
    No* j;
    int aux;
    i= l->inicio->prox;
    while(i!=NULL){
        aux=i->dado;
        j=i;
        while((j->ant!=NULL) && (aux < j->ant->dado)){
            j->dado=j->ant->dado;
            j=j->ant;
        }
        j->dado = aux;
        i=i->prox;

    }
}

void bubbleSort(Lista *l){
	No* i=l->fim;
	No* j;
	int aux;
	while(i->ant!=NULL){
        j=l->inicio;
        while(j!=i){
            if((j->dado) > (j->prox->dado)){
                aux=j->dado;
                j->dado=j->prox->dado;
                j->prox->dado=aux;
            }
            j=j->prox;
        }
        i=i->ant;
	}
}

void shellSort(Lista *l){
    int i = (l->qtd - 1) / 2;
   int chave, k, aux;
    No* a;
    No* b;
   while(i != 0){
      do{
         chave = 1;
         a=l->inicio;
         for(k = 0; k < l->qtd - i; ++k){
            b=a->prox;
            if(a->dado > b->dado){
               aux = a->dado;
               a->dado = b->dado;
               b->dado = aux;
               chave = 0;
            }
            a=a->prox;
         }
      }while(chave == 0);
      i = i / 2;
   }
}

No* quickPart(No* inicio,  No* fim){  
	if(inicio==fim) return inicio;

    int aux;
    No *menor = inicio ,*pivo = fim,*atual = inicio,temp;

    while(atual!=NULL && atual!=fim)
    {
        if(atual->dado < pivo->dado)
        {
            aux = menor->dado;
            menor->dado = atual->dado;
            atual->dado = aux;
            menor = menor->prox;
        }
        atual = atual->prox;

    }
    aux = pivo->dado;
    pivo->dado = menor->dado;
    menor->dado = aux;
    
	return menor;
    
}

void quickSort(Lista *l, No* inicio, No* fim){
	No* p;
    p = quickPart(inicio,fim);
    if(inicio!=p){
    	quickSort(l,inicio,(p->ant));
	}
    if(p!=fim){
    	quickSort(l,(p->prox),fim);
	}
    
}

void heapSort(Lista *l){
    int n=l->qtd;
    No* a;
    No* b;
    No* c;
    int i = n / 2, pai, filho, t;
    while(1) {
        if (i > 0) {
            i--;
            a = buscaPosicao(l,i);
            t = a->dado;
        }
        else{
            n--;
            if (n == 0){
                return;
            }
            a = buscaPosicao(l,n);
            t = a->dado;
            b = buscaPosicao(l,0);
            a->dado = b->dado;
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < n) {
            a = buscaPosicao(l,filho+i);
            b = buscaPosicao(l,filho);
            if ((filho + 1 < n)  &&  (a->dado > b->dado))
                filho++;
            if (b->dado > t) {
                a = buscaPosicao(l,pai);
                a->dado = b->dado;
                pai = filho;
                filho = pai * 2 + 1;
            }
            else {
                break;
            }
        }
        a = buscaPosicao(l,pai);
        a->dado = t;
    }
}
