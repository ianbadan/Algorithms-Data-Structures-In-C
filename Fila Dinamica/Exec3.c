#include <stdio.h>
#include <stdlib.h>
/*Criado por Ian Mendes Badan
*/
void main(){
	int *v, t, i, soma;
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &t);
	v=malloc(t*sizeof(int));
	for(i=0;i<t;i++){
		scanf("%d", &v[i]);
	}
	for(i=0;i<t;i++){
		printf("%d ", v[i]);
	}
	soma=0;
	printf("\n", v[i]);
	for(i=0;i<t;i++){
		if(v[i]%2!=0){
			soma+=v[i];
		}
	}
	
	printf("A soma dos numeros impares eh: %d", soma);
}
