#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ListaDE.h"
#include "Ordenacao.h"

#define LimTeste 1

int obterMediaTempo(Lista *l){
    float tinicio,tfim,tIntervalo=0;
    int i, j, k, tamanho;
    for(i=1;i<4;i++){
        if(i==1) printf("\nOrdem Crescente\n");
        if(i==2) printf("\nOrdem Decrescente\n");
        if(i==3) printf("\nOrdem Aleatoria\n");
        for(j=0;j<5;j++){
            switch (j){
                case 0 :
                    tamanho = 100;
                break;
                case 1 :
                    tamanho = 1000;
                break;
                case 2 :
                    tamanho = 10000;
                break;
                case 3 :
                    tamanho = 50000;
                break;
                case 4 :
                    tamanho = 100000;
                break;
                default :
                break;
            }
                printf("\nTamanho %d\n", tamanho);
                tIntervalo=0;
                for(k=0;k<LimTeste;k++){
                    esvaziaLista(l);
                    preencheLista(l,i,tamanho);
                    tinicio=clock();
                    selectionSort(l);
                    tfim=clock();
                    tIntervalo+=((tfim-tinicio)/CLOCKS_PER_SEC);
                    }
                printf("SelectionSort %f segs\n", tIntervalo/LimTeste);
                tIntervalo=0;

                for(k=0;k<LimTeste;k++){
                    esvaziaLista(l);
                    preencheLista(l,i,tamanho);
                    tinicio=clock();
                    insertionSort(l);
                    tfim=clock();
                    tIntervalo+=((tfim-tinicio)/CLOCKS_PER_SEC);
                }
                printf("InsertionSort %f segs\n", tIntervalo/LimTeste);
                tIntervalo=0;

                for(k=0;k<LimTeste;k++){
                    esvaziaLista(l);
                    preencheLista(l,i,tamanho);
                    tinicio=clock();
                    bubbleSort(l);
                    tfim=clock();
                    tIntervalo+=((tfim-tinicio)/CLOCKS_PER_SEC);
                    }
                printf("BubbleSort %f segs\n", tIntervalo/LimTeste);
                tIntervalo=0;

                for(k=0;k<LimTeste;k++){
                    esvaziaLista(l);
                    preencheLista(l,i,tamanho);
                    tinicio=clock();
                    shellSort(l);
                    tfim=clock();
                    tIntervalo+=((tfim-tinicio)/CLOCKS_PER_SEC);
                }
                printf("ShellSort %f segs\n", tIntervalo/LimTeste);
                tIntervalo=0;

                for(k=0;k<LimTeste;k++){
                    esvaziaLista(l);
                    preencheLista(l,i,tamanho);
                    tinicio=clock();
                    quickSort(l, l->inicio,l->fim);
                    tfim=clock();
                    tIntervalo+=((tfim-tinicio)/CLOCKS_PER_SEC);
                    }
                printf("QuickSort %f segs\n", tIntervalo/LimTeste);
                tIntervalo=0;

                /*for(k=0;k<LimTeste;k++){
                    esvaziaLista(l);
                    preencheLista(l,i,tamanho);
                    tinicio=clock();
                    heapSort(l);
                    tfim=clock();
                    tIntervalo+=((tfim-tinicio)/CLOCKS_PER_SEC);
                }*/
                printf("HeapSort %f segs\n", tIntervalo/LimTeste);
                tIntervalo=0;
            }
    }
}

int verificaOrdenacao(Lista *l){
    int tamanho=10;
        esvaziaLista(l);
        printf("\n\tTamanho %d\n", tamanho);

        printf("\tSelectionSort\n");
        preencheLista(l,4,tamanho);
        printf("\tLista Desordenada\n");
        imprimirLista(l);
        selectionSort(l);
        printf("\n\tLista Ordenada\n");
        imprimirLista(l);

        esvaziaLista(l);
        printf("\n\n\tInsertionSort\n");
        preencheLista(l,4,tamanho);
        printf("\tLista Desordenada\n");
        imprimirLista(l);
        insertionSort(l);
        printf("\n\tLista Ordenada\n");
        imprimirLista(l);

        esvaziaLista(l);
        printf("\n\n\tBubbleSort\n");
        preencheLista(l,4,tamanho);
        printf("\tLista Desordenado\n");
        imprimirLista(l);
        bubbleSort(l);
        printf("\n\tLista Ordenado\n");
        imprimirLista(l);

        esvaziaLista(l);
        printf("\n\n\tShellSort\n");
        preencheLista(l,4,tamanho);
        printf("\tLista Desordenado\n");
        imprimirLista(l);
        shellSort(l);
        printf("\n\tLista Ordenado\n");
        imprimirLista(l);

        esvaziaLista(l);
        printf("\n\n\tQuickSort\n");
        preencheLista(l,4,tamanho);
        printf("\tLista Desordenado\n");
        imprimirLista(l);
        quickSort(l, l->inicio,l->fim);
        printf("\n\tLista Ordenado\n");
        imprimirLista(l);

        esvaziaLista(l);
        printf("\n\n\tHeapSort\n");
        preencheLista(l,4,tamanho);
        printf("\tLista Desordenado\n");
        imprimirLista(l);
        heapSort(l);
        printf("\n\tLista Ordenado\n");
        imprimirLista(l);
}

void menu(Lista *l){
    int i;
    while(1){
        printf("\n\nO que deseja fazer?\n1) Obter as medias aritmeticas de cada metodos \n2) Verificar o funcionamento dos metodos \n3)Finalizar o programa\n");
        scanf("%d", &i);
        switch(i){
            case 1: obterMediaTempo(l);
            break;
            case 2: verificaOrdenacao(l);
            break;
            case 3:
                finalizaLista(l);
                exit(0);
            break;
        }
    }
}

int main(int argc, char *argv[]) {
	Lista *l=malloc(sizeof(Lista));
    inicializaLista(l);
    menu(l);
	return 0;
}
