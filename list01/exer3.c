//André Quintiliano Filho 0030481523006
//Matheus Luiz da Silva   0030481523028

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
	char Frase[100]="";
	char Crip[100]="";
	int i,K=0;
	
	do
	{
		printf("\nEscreva uma nova Frase: ");
		scanf(" %[^\n]s", Frase);			
			
		for(i=0;i<strlen(Frase);i++)
		{
			Frase[i]=toupper(Frase[i]);
		}
					
		printf("Atribua um valor a K: ");
		scanf("%i", &K);
			
		for (i=0;i<=strlen(Frase);i++)	
		{
			if (Frase[i]==32)
			{
				Crip[i]=32;
			}
			if (Frase[i]>=65 && Frase[i]<=90)
			{
				Crip[i] = Frase[i]+K;
			}	
		}
		for (i=0;i<strlen(Crip);i++)
		{
			if (Crip[i]>90)
			{
				Crip[i]=Crip[i]-26;
			}
		}
		if(K>0)
		{
			printf("Frase Criptografada: %s \n", Crip);
		}
	} while (K!=0);
}