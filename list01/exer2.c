//André Quintiliano Filho 0030481523006
//Matheus Luiz da Silva   0030481523028

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	int Poltrona[50];
	int i,c,Assento;
	int a=1;
	
	for (i=0;i<46;i++)
	{
		Poltrona[i]=0;
	}
	
	printf("\n");
	
	for (i=0;i<=1;i++)
	{
		printf("[%i]", a++);
		for(c=0;c<22;c++)
		{
			if(a>=15&&a<16)
				printf("\n");
			if(a>=27&&a<28)
				printf("\n\n");
			if(a>=37&&a<38)
				printf("\n");
			printf("[%i]", a++);
		}
	}
	printf("\n");
	printf("\nEscolha uma nova poltrona: ");
	scanf("%i", &Assento);
	if (Assento==0)
	{
		return(0);
	}
		
	do
	{
		if(Assento>0 && Assento<=46)
		{
			if (Poltrona[Assento-1]==0)
			{
				Poltrona[Assento-1]=1;
			}
			else
			{
				printf("Poltrona ocupada!");
			}
		}
		else
		{
			printf("Poltrona informada não existe!");
		}
		
		printf("\nEscolha uma nova poltrona: ");
		scanf("%i", &Assento);
		
	}while (Assento!=0);
		
}