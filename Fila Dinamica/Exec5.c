#include <stdio.h>
#include <stdlib.h>

void main(){
    int *v, *aux, k=0,i, j=0;
    v=NULL;
    for(i=0;k>-1;i++){
        printf("Informe um numero ou digite um negativo para sair: ");
        scanf("%d", &k);
        if(k>-1){
            aux=malloc((i+1)*sizeof(int));
            aux[i]=k;
            for(j=0;j<i;j++){
                aux[j]=v[j];
            }
            free(v);
            v=aux;
            aux=NULL;
            j++;
        }
    }
    for(i=0; i<j ;i++){
        printf("%d\n", v[i]);
    }
}
