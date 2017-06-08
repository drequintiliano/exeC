//André Quintiliano Filho 0030481523006
//Matheus Luiz da Silva   0030481523028

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char char_ISBN[50]="";
	int S1[50]={0};
	int S2[50]={0};
	int i;
	int int_ISBN[50]={0};
	int Mod;
		
	do
	{
		printf("\nDigite o codigo do livro: ");
		scanf("%s", char_ISBN);
				
		for (i=0;i<strlen(char_ISBN);i++)
		{
			char_ISBN[i]=toupper(char_ISBN[i]);
		}
		if(strcmp(char_ISBN,"FIM")==0)
		{
			return(0);
		}
				
		for (i=0;i<9;i++)
		{
			if (char_ISBN[i] == 'X')
			{
				printf("\nISBN invalido! \n");
			}
		}
		if (strlen(char_ISBN) != 10)
		{
			printf ("\n*Quantidade de caracteres* ISBN invalido! \n");
		}
		
		atoi(char_ISBN);
		
		if(char_ISBN[9]==88)
		{
			char_ISBN[9]=char_ISBN[9]-30;
		}
		
		for(i=0;i<strlen(char_ISBN);i++)
		{
				int_ISBN[i]=char_ISBN[i]-48;
		}
		printf("\n");
		for (i=0;i<10;i++)
		{
			S1[i+1] = S1[i]+int_ISBN[i+1];//calcular S1
		}
		
		for(i=0;i<10;i++)
		{
			S2[i+1] = S2[i]+S1[i+1];//calcular S2
		}
		
		if (S2[9]%11 == 0)
		{
			for(i=0;i<9;i++)
			{
				printf("%i", int_ISBN[i]);
			}
			if(int_ISBN[9]==10)
			{
				printf("-X ISBN valido!\n");
			}
			else
			{
			printf("-%i ISBN valido!\n", int_ISBN[9]);
			}
		}
		else
		{
			Mod=S2[9]%11;
			printf("ISBN %i invalido!\n", Mod);
		}
	} while (strcmp(char_ISBN,"FIM") != 0);	
}