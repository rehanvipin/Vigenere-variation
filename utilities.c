#include"reqs.h"

/* To contain all the utility functions which did not come under any category */

void clear_ext(char *dest, const char *source)
{
	strcpy(dest, source);
	int len = strlen(dest), c;

	while(((c=*(dest+len))!='.')&&(len>0))
		len--;
	if(c=='.')
		dest[len] = 0;
	strcat(dest+len,".secure");
}

void casting(char * source, int *dest, int len)
{
	for(int i=0;i<len;i++)
		dest[i] = source[i];
}

void invcasting(int * source, char *dest, int len)
{
	for(int i=0;i<len;i++)
		dest[i] = source[i];
}
