//André Quintiliano Filho 0030481523006
//Matheus Luiz da Silva   0030481523028

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
	char Str1[100];
	char StrComp[100]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i,j;
	int Quant[100];
		
	do 
	{
		int Quant[50]={0};
		printf("\nEscreva uma nova frase: ");
		scanf(" %[^\n]s", Str1);
		
		for(i=0;i<strlen(Str1);i++)
		{
			Str1[i]=toupper(Str1[i]);
		}
		
		if(strcmp(Str1,"FIM")==0)
		{
			return(0);
		}
		
		for(i=0;i<strlen(StrComp);i++)
		{
			for(j=0;j<strlen(Str1);j++)	
				if (StrComp[i] == Str1[j])
				{
					Quant[i]++;
				}
		}
		for(i=0;i<strlen(StrComp);i++)
		{
			if (Quant[i]>0)
			{
			printf("%c = ", StrComp[i]);
			printf("%d \n", Quant[i]);
			}
		}
	} while (strcmp(Str1,"FIM")!=0);
}