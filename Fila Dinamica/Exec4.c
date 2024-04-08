#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
	char nome[30];
	float media;
	int faltas;
} Aluno;

void main(){
	int i, n, j;
	float media1, media2;
	Aluno *dados, aux;
	printf("Informe o numero de alunos: ");
	scanf("%d", &n);
	dados=malloc(n*sizeof(Aluno));
	for(i=0;i<n;i++){
		setbuf(stdin, NULL);
		printf("Nome:");
		fgets(dados[i].nome, 30,stdin);
		setbuf(stdin, NULL);
		printf("Media: ");
		scanf("%f", &dados[i].media);
		printf("Faltas: ");
		scanf("%d", &dados[i].faltas);
	}

	for(i=0;i<n;i++){
		j=i;
		while(j>0 &&(dados[j-1].media)<(dados[j].media)){
			aux=dados[j];
			dados[j]=dados[j-1];
			dados[j-1]=aux;
			j--;
		}	
	}
	printf("\n\nAlunos ordenados por media decrescente\n");
	for(i=0;i<n;i++){
		printf("Nome: %s", dados[i].nome);
		printf("Media: %.2f\n", dados[i].media);
		printf("Faltas: %d\n", dados[i].faltas);
	}
}

