#include"reqs.h"

/* To contain the crypto functions which will put and get data from the files */

void put_header(const char *filename, int hedlen, FILE *fp)
{
	fwrite(filename, sizeof(char), hedlen, fp);
}

void get_header(char *output, int hedlen, FILE *fp)
{
	fread(output, sizeof(char), hedlen, fp);
}

void pshift_data(int *buffer, int len_buf, int *indc, int len)
{
	int temp = 0;
	while(temp < len_buf)
	{
		buffer[temp] += indc[temp % len];
		buffer[temp] %= 255;
		temp++;
	}
}

void nshift_data(int *buffer, int len_buf, int *indc, int len)
{
	int temp = 0;
	while(temp < len_buf)
	{
		buffer[temp] -= indc[temp % len];
		buffer[temp] %= 255;
		temp++;
	}
}

