//Lucas Tomaz Nunes
//11721EEL007

#include <stdio.h>

int main ()
{	
    int vetA[256], a = 0, b, c = 0;
	char vetB[256];
	printf("Digite um numero: ");
	scanf("%s", &vetB);	
	for(a=0; vetB[a] != '\0'; a++)
	{	
	    if(vetB[a] >= 48 && vetB[a] <= 57)
		{
			vetA[c] = vetB[a] - 48;
			c++;
		}
	}
	b=0;
	printf("Valor retornado = ");
	do
	{	
	    printf("%d", vetA[b]);
		b++;
	}while(b < c);
	return 0;
}
