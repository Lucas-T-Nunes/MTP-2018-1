#include <stdio.h>

int main()
{
	int i = 0, j = 0, op, *pont, vetor[64];
	char *a;
	char texto[256];
	pont = (int*)texto;
	a = (char*)vetor;
	do 
	{
		printf("\nEscolha sua opcao:\n 1 - Codificar \n 2 - Decodificar \n 3 - Sair\n ");
		scanf("%d", &op);
		getchar();
		switch(op)
		{
			case 1:
				printf("\n\nDigite a frase a ser codificada: ");
				fgets(texto, 256, stdin);
				while(sizeof(texto) <= pont[i])
				{
					printf("\n%d", pont[i]);
					i++;
				}
				break;
			case 2:
				for(j = 0; j < 64; j++)
				{
					vetor[j]=0;
				}
				for(j = 0; j < 64; j++)
				{
					printf("\nDigite o codigo (terminando com '0'): ");
					scanf("%d", &vetor[j]);
					if(vetor[j] == 0)
					{
						break;
					}
			    }
			    printf("\n");
			    for(j = 0; j < sizeof(vetor); j++)
			    {
			    	printf("%c", a[j]);
				}
				break;
			case 3:
				break;	
		}
		
	}while(op != 3);
	return 0;
}
