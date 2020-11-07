#include"reqs.h"

char HELPMSG[] = "Usage:\n"
				 "seint -[OPTION] file\n"
				 "Options- \n"
				 "\t-e : encrypt the file\n" 
				 "\t-d : decrypt the file\n" 
				 "\t-h : Display this help message";

int main(int argc, char **argv)
{
	char passwd[20];

	if(argc < 3)
	{
		printf("%s\n", HELPMSG);
		return 0;
	}

	char *flags = argv[1], filename[HEADLEN];
	strcpy(filename, argv[2]);
	int encrypt = 0, c;

	// Getting the encrypt or decrypt options
	while((c = *(flags++))!=0)
	{
		switch(c)
		{
			case('d'):break;
			case('e'):{encrypt = 1; break;}
			case('h'):{printf("%s\n", HELPMSG); return 0;}
			case('-'):continue;
			default:{printf("Wrong option %c\n",*flags);return -1;}
		}
	}

	// Get the password from the user and perfrom magic on the indices array
	printf("Enter the password (Max 19 chars)\n");
	scanf("%s",passwd);

	int len = strlen(passwd);
	int *indc = calloc(sizeof(int)*len,sizeof(int));

	fill(indc, len); // Fills indc with 0,1,2....
	sel_sort(passwd, indc, len);
	//Done with the indices magic Continue with the encrpytion or decryption
	
	char secure_file[HEADLEN];
	int buffer[BUFSIZ];
	char cbuffer[BUFSIZ];
	clear_ext(secure_file, filename);

	FILE *safe_file = fopen(filename, "rb");	// File given to read in both cases
	if(!safe_file)
	{
		printf("Cannot open the file for reading\n");
		return 0;
	}
	
	if(encrypt)
	{
		FILE *output = fopen(secure_file, "wb");
		int red = 0; // To count how many numbers were read
		put_header(filename, HEADLEN, output);

		do
		{
			red = fread(cbuffer, sizeof(char), BUFSIZ, safe_file);
			casting(cbuffer, buffer, red);
			pshift_data(buffer, red, indc, len);
			fwrite(buffer, sizeof(int), red, output);
			memset(buffer, 0, red);
		}
		while(red==BUFSIZ);
		
		fclose(output);
	}
	else
	{
		char og_filename[HEADLEN] = {0};
		int red = 0;
		get_header(og_filename, HEADLEN, safe_file);
		FILE *og_file = fopen(og_filename, "wb");

		do
		{
			red = fread(buffer, sizeof(int), BUFSIZ, safe_file);
			nshift_data(buffer, red, indc, len);
			invcasting(buffer, cbuffer, red);
			fwrite(cbuffer, sizeof(char), red, og_file);
			memset(buffer, 0, red);
		}
		while(red==BUFSIZ);

		fclose(og_file);
	}


	fclose(safe_file);
	free(indc);
	putchar('\n');
	return 0;
}
