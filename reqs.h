#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define HEADLEN 32

/* Defined in sort.c */
void sel_sort(char *, int *, int);
void fill(int *, int);

/* Defined in utilites.c */
void clear_ext(char *, const char *);
void casting(char *, int *, int);
void invcasting(int *, char *, int );

/* Defined in crypto.c */
void put_header(const char *, int, FILE *);
void get_header(char *, int, FILE *);
void pshift_data(int *, int, int *, int);
void nshift_data(int *, int, int *, int);
