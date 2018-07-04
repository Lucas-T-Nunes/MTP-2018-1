#include <stdio.h>
#include <stdlib.h>

void gera_numeros(float *vetor, int tam)
{
	int i;
	float num;
	for(i = 0; i < tam; i++)
	vetor[i] = (float) rand()/(float) RAND_MAX + 0.5f;
}

float reduce(float *inicio_vetor, float *fim_vetor, float (*funcao)(float, float))
{
	return (inicio_vetor == fim_vetor)? 1 : (*funcao)(*inicio_vetor, reduce(inicio_vetor+1, fim_vetor, funcao));
}

float soma(float n1, float n2)
{
	return n1+n2;
}

float produto(float n1, float n2)
{
	return 	n1*n2;
}

int main(int argc, char ** argv)
{
	srand(123456);
	int opc = 0;
	float vetor[99];
	
	printf("Seja Bem-Vindo!\n");
	printf(" 1- Soma\n 2- Produtorio\n");
	printf("Digite a opcao desejada:\n");
	scanf("%d", &opc);
	getchar();
	
	gera_numeros(vetor,99);
	
	switch(opc)
	{
		case 1:
			printf("\nSoma: %f\n", reduce(vetor, vetor+99, soma)-1);
			return 0;
		case 2:
			printf("\nProdutorio: %f\n", reduce(vetor, vetor+99, produto));
			return 0;
	}
	
	return 0;
	
}
