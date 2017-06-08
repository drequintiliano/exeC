#include <stdio.h>

void Substring (char *str1, char *str2, int n1, int n2)
{
	int i=0;

	for (i=n1-1;i<n2;i++)
	{
		*str2=*(str1+i);
		str2++;
	}
	*str2='\0';
}
