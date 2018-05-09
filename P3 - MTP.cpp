#include <stdio.h>

int dec_all(int num, int vet[256])
{	
    int resto[100], guarda, i=0, j=0, base=2, num1=0;
	if(num < 0)
	{ 
	    num1 = num;
	    num = (-num) - 1;
	    guarda = num;
	}
	else if(num >= 0)
	{	
	    num1 = num;
		guarda = num;
	}
    resto[0] = 1;
    for(i=0; num >= base; i++)
	{	
	    resto[i] = num%base;	
		num = num/base;
		if(num < base)
		{	i++;
			resto[i] = num;		
		} 
	}	
	if(guarda>base) 
	{ 
	    i--;
	}
	num = guarda;	
	guarda = 32;
	for(j=0; j<guarda; j++)
	{	
	    if(j < (guarda-(i+1)))
		{	
		    vet[j] = 0;		
		}
		else
		{	
		    vet[j] = resto[i];
			i--;
		}
		if(num1 < 0)
		{	
		    if(vet[j] == 0)
			{	
			vet[j] = 1;		 
		    }
			else if(vet[j] == 1)
			{	
			    vet[j] = 0;			
			}
		}
	}
	return j; 
}

int main ()
{
	int opcao, i=0, j, k, numA, numB, numC, vet_n[256], vet_n1[256], vet_c[256];

	do
	{	
	    printf("CALCULADORA BITWISE");
		printf("\n1 - NOT");
		printf("\n2 - AND");
		printf("\n3 - OR");
		printf("\n4 - XOR");
		printf("\n5 - RIGHT SHIFT");
		printf("\n6 - LEFT SHIFT");
		printf("\n7 - Sair do programa");
		printf("\nDigite uma opcao: ");
		scanf("%d", &opcao);
		
		if(opcao == 7)
		{
		    return 0;
		}
		else if(opcao != 1 && opcao <= 7)
		{	printf("\nDigite dois valores: ");
			scanf("%d %d", &numA, &numB);
			getchar();	
		}
		else if(opcao == 1)
		{	printf("\nDigite um valor: ");
			scanf("%d", &numA);
			getchar();
		}
			
		switch(opcao)
		{	
		    case 1:
				j = dec_all(numA, vet_n);
				printf("\nNOT %d (", numA);
				for(i=0; i<j; i++)
				{	
				    printf("%d", vet_n[i]);
					if(i==(j-1))
				    {	
					    printf(") : ");
					}	
				}
				numA = ~numB;
				j = dec_all(numA, vet_n1);
				printf(" %d (", numA);
				for(i=0; i<j; i++)
				{	printf("%d", vet_n1[i]);
				    if(i==(j-1))
					{	
					    printf(") ");
					}	
				}
					printf("\n\n");
				break;
			case 2:
	 			j = dec_all(numA, vet_n);
				printf("\n%d (", numA);
				for(i=0; i<j; i++)
				{	
				    printf("%d", vet_n[i]);
					if(i==(j-1))
					{	
					    printf(") AND");
					}
				}
				j = dec_all(numB, vet_n1);
				printf(" %d (", numB);
				for(i=0; i<j; i++)
				{	
			        printf("%d", vet_n1[i]);
				    if(i==(j-1))
					{	
					printf(") :");
					}	
				}
				numC = numA & numB;
				j= dec_all(numC, vet_c);
				printf(" %d (" , numC);
				for(i=0; i<j; i++)
				{	
				    printf("%d", vet_c[i]);
				    if(i==(j-1))
					{
						printf(") ");
					}
				}
				printf("\n\n");
				break;
			case 3:
				j = dec_all(numA, vet_n);
				printf("\n%d (", numA);
				for(i=0; i<j; i++)
				{	
				    printf("%d", vet_n[i]); 
				    if(i==(j-1))
				        {	
				        printf(") OR");
				        }
			    }
				j = dec_all(numB, vet_n1);
				printf(" %d (", numB);
				for(i=0; i<j; i++)
				{	
				    printf("%d", vet_n1[i]);
				    if(i==(j-1))
					{	
					printf(") :");
					}	
				}
				numC = numA | numB;
				j= dec_all(numC, vet_c);
				printf(" %d (", numC);
				for(i=0; i<j; i++)
				{	printf("%d", vet_c[i]);
				    if(i==(j-1))
					{	
					    printf(") ");
					}	
				}
				printf("\n\n");
				break;
			case 4:
				j = dec_all(numA, vet_n);
				printf("\n%d (", numA);
				for(i=0; i<j; i++)
				{	
				    printf("%d", vet_n[i]);
				    if(i==(j-1))
					{	
					printf(") XOR");
					}
				}
				j = dec_all(numB, vet_n1);
				printf(" %d (", numB);
				for(i=0; i<j; i++)
				{	
				    printf("%d", vet_n1[i]);
				    if(i==(j-1))
					{	
					    printf(") :");
					}
				}
				numC = numA ^ numB;
				j= dec_all(numC, vet_c);
				printf(" %d (" ,numC);
				for(i=0; i<j; i++)
				{	
				    printf("%d", vet_c[i]);
				   if(i==(j-1))
				   {	
				   printf(") ");
			       }
				}
				printf("\n\n");
				break;
			case 5:
				j = dec_all(numA, vet_n);
				printf("\n%d (", numA);
				for(i=0; i<j; i++)
				{	
				    printf("%d", vet_n[i]);
				    if(i==(j-1))
					{
						printf(") >>");
					}
				}
				j = dec_all(numB, vet_n1);
				printf(" %d (", numB);
				for(i=0; i<j; i++)
				{	
				    printf("%d", vet_n1[i]);  if(i==(j-1))
					{	
					    printf(") :");
					}
				}
				numC = numA >> numB;
				j= dec_all(numC, vet_c);
				printf(" %d (" , numC);
				for(i=0; i<j; i++)
				{	
				    printf("%d", vet_c[i]);
				    if(i==(j-1))
					{
						printf(") ");
					}
				}
				printf("\n\n");
				break;
			case 6:
				j = dec_all(numA, vet_n);
				printf("\n%d (", numA);
				for(i=0; i<j; i++)
				{	
				    printf("%d", vet_n[i]);
				    if(i==(j-1))
					{	
					    printf(") >>");
					}
				}
				j = dec_all(numA, vet_n1);
				printf(" %d (", numB);
				for(i=0; i<j; i++)
				{	
				    printf("%d", vet_n1[i]);
				    if(i==(j-1))
					{	
					    printf(") :");
					}
				}
				numC = numA << numB;
				j= dec_all(numC, vet_c);
				printf(" %d (" ,numC);
				for(i=0; i<j; i++)
				{	
				    printf("%d", vet_c[i]);
				    if(i==(j-1))
					{	
					    printf(") ");
					}
				}
				printf("\n\n");
				break;
			default:
				break;
		}
	}while(1);
}
