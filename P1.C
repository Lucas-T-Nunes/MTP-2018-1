#include <stdio.h>

int main ()
{
	char binario[256];
	int contador=0, k, valor=0, ta_ficando_dificil =1;
	
	printf("Digite o autonomo finito: ");
	scanf("%s", &binario);
	do	{	contador++;		}while(binario[contador] != '\0');	
	contador -= 1;	
	for(k=0; contador>=k; contador--)
	{	if(binario[contador] == '0')
		{	valor += 0;		}
		if(binario[contador] == '1')
		{	valor += ta_ficando_dificil;	}
		ta_ficando_dificil *= 2;
	}
	if (valor%3==0)
	{	printf("\nE divisivel por 3");	}
	else
	{	printf("\nNao e divisivel por 3");	}
	return 0;
}
