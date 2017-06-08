//André Quintiliano Filho RA 0030481523006
//Matheus Luiz da Silva   RA 0030481523028

#include <stdio.h>
#define MAX 10

int invertTab(int *tab, int tam)
{
   int troca;
   if (tam >= 1)
   {
		troca=*(tab+tam);
		*(tab+tam) = *tab;
		*tab=troca;
		
		invertTab(tab+1,tam-2);		
   }
   
}

main()
{
   int num[MAX];

   int i;
   
   for (i=0;i<10;i++)
   {
	   printf("Digite o Numero %i:", i+1);
	   scanf("%i",num+i);
   }
   
   invertTab(num, 9);
   for (i=0;i<10;i++)
   {
	   printf("%i ",*(num+i));	   
   }
   
   
}