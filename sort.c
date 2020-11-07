/* To sort the two arrays which are passed to the program */

void sel_sort(char *org, int *dup, int len) 
{
	void swap(int *, int *);
	void cswap(char *, char *);
	int i, j, min_idx; 

	for (i = 0; i < len-1; i++) 
	{ 

		min_idx = i; 
		for (j = i+1; j < len; j++) 
			if (org[j] < org[min_idx]) 
				min_idx = j; 

		cswap(&org[min_idx], &org[i]);
		swap(&dup[min_idx], &dup[i]); 
	} 
} 


void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void cswap(char *a, char *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void fill(int *arr, int len)
{
	for(int i=1;i<len+1;i++)
		arr[i-1] = i;
}
