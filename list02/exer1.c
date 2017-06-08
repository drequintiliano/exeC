//André Quintiliano Filho RA 0030481523006
//Matheus Luiz da Silva   RA 0030481523028


#include <stdio.h>
#include "func.c"
typedef struct
    {
        int CodForne;
        char NomeForne[40];
        float ValorPagar;
        char CodBanco[4];
        char CodAgencia[5];
        char NumContBanco[7];
        char CNPJ[15];
	} TReg;


void bolha (int n, TReg *v)
{
  int i, j;
  TReg temp;
  int troca;
  for (i=n-1; i>0; i--) 
  {
    troca = 0;
    for (j=0; j<i; j++)
      if (strcmp(v[j].NomeForne,v[j+1].NomeForne)>0) 
      { /* troca */
        temp = v[j];		
        v[j]= v[j+1];
		v[j+1] = temp;
        troca = 1;
      }
      if (troca == 0) /* nao houve troca */
      return;
   }
	
}

int ProcuraNome (TReg *v, int inicio, int fim, char *NomePesq)
{
	int meio;

	if (inicio>fim)
	{
		return -1;
	}
	meio=(inicio+fim)/2;
	if (strcmp(v[meio].NomeForne,NomePesq)<0)
	{
		return(ProcuraNome(v,meio+1,fim,NomePesq));
	}
	if (strcmp(v[meio].NomeForne,NomePesq)>0)
	{
		return(ProcuraNome(v,inicio,meio-1,NomePesq));
	}
	return meio;
}

int main ()
{
    char Linha[80];

    FILE *arq, *erro;
    char CodForn[6], Banco[4], vCNPJ[15];
    char valor1[10], codigo[6];
    TReg pagamento[100];
	int x, p;
	int y=0;
	int i=0;
	char PesqNome[100];
	int indice;
	TReg vNomeForne[100];
	

    arq = fopen("pagamento.txt", "r");
    erro = fopen("erro.txt", "w");

    if (arq==NULL)
	{
	   printf("erro ao procurar arquivo");
	   return;
	}

    fgets(Linha,80,arq);
    while (!feof(arq))
    {
        Substring(Linha,Banco,57,62);
        Substring(Linha,vCNPJ,63,76);

       if (strcmp(Banco,"001")!=0 && strcmp(vCNPJ,"00000000000000")==0)
        {
            fprintf(erro,"%s\n",Linha);
            }
            else
            {
                Substring(Linha,codigo,1,5);
                Substring(Linha,pagamento[i].NomeForne,6,40);
                Substring(Linha,valor1,41,49);
                Substring(Linha,pagamento[i].CodBanco,50,52);
                Substring(Linha,pagamento[i].CodAgencia,53,56);
                Substring(Linha,pagamento[i].NumContBanco,57,62);
                Substring(Linha,pagamento[i].CNPJ,63,76);
                pagamento[i].ValorPagar = atoi(valor1)/100.0;
                pagamento[i].CodForne = atoi(codigo);
				
				for(x = 0; pagamento[i].NomeForne[x] != '\0'; x++)
				{
					while(pagamento[i].NomeForne[x] == ' ')
					{
						for(y = x; pagamento[i].NomeForne[y] != '\0'; y++)
						{
							pagamento[i].NomeForne[y] = pagamento[i].NomeForne[y + 1];
						}
					}
				}
				
                printf("\n Conta: %i   %s %.2f %s %s %s %s ",pagamento[i].CodForne,pagamento[i].NomeForne,pagamento[i].ValorPagar,
                                    pagamento[i].CodBanco,pagamento[i].CodAgencia,pagamento[i].NumContBanco,pagamento[i].CNPJ);
									
				i++;
            }
        fgets(Linha,80,arq);
    }
	
	bolha(i,pagamento);

	printf("\n");

	/*printf( "\nInforme o nome a pesquisar:" );
	scanf( "%s", PesqNome);
	
	fread( &pagamento[i], sizeof(TReg), 1, arq );
	while( !feof(arq) && strcmp(PesqNome, pagamento[i].NomeForne) != 0 )
	{	
     	fread( &pagamento[i], sizeof(TReg), 1, arq );
	}
	if( feof(arq) )
		printf( "\nNao ACHOU %s no arquivo\n\n", PesqNome );
	else
		printf( "\n%s tem o codigo %s\n\n", PesqNome, pagamento[i].NomeForne );
	*/

	printf( "\nInforme o nome a pesquisar:" );
	scanf( "%s", PesqNome);

	indice=ProcuraNome(vNomeForne,0,4,PesqNome);

	if(indice==-1)
	{
		printf("\nNome NAO encontrado!\n\n");
	}
	else
	{
		printf("\nNome do fornecedor %s encontrado\n\n",vNomeForne[indice].NomeForne);
	}


	/*for (p=0;p<7;p++)
	{
		pagamento[i].ValorPagar=pagamento[i].ValorPagar[p]+pagamento[i].ValorPagar[p+1];
		printf("%.2f\n",pagamento[i].ValorPagar);
	}*/

	
    fclose(arq);
    fclose(erro);
}
