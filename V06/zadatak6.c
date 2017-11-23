/*
	Napisati funkciju void kodiraj(char *ul_dat, char
	*izl_dat) koja kodira ulaznu datoteku tako sto svako
	slovo iz ulazne datoteke pomera za jednu poziciju
	unapred, u alfabetu. Parametri ul_dat i izl_dat su
	nazivi ulazne, odn. izlazne datoteke.
	 Napisati funkciju void dekodiraj(char *ul_dat, char
	*izl_dat) koja dekodira ulaznu datoteku tako sto
	svako slovo iz ulazne datoteke pomera za jednu
	poziciju unazad, u alfabetu. Parametri ul_dat i
	izl_dat su nazivi ulazne, odn. izlazne datoteke.
	 Napisati program koji testira prethodno defiisane
	funkcije
*/

#include <stdio.h>
#include <stdlib.h>

FILE *safe_open(char*, char*);
void kodiraj(char *ul_dat, char *izl_dat);
void dekodiraj(char *ul_dat, char *izl_dat);

int main() {

    char sin[] = "ulazna.txt";
    char scode[] = "kodirana.txt";
    char sdecode[] = "dekodirana.txt";

    kodiraj(sin, scode);
    dekodiraj(scode, sdecode);

    return 0;
}

FILE *safe_open(char *name, char *mode) {
    FILE *fp = fopen(name, mode);

    if(fp == NULL) {
        printf("Doslo je do greske prilikom otvaranja fajla %s.\n", name);
        exit(EXIT_FAILURE);
    }

    return fp;
}

void kodiraj(char *ul_dat, char *izl_dat) {
    char c;
    FILE *in, *code;
    
    in = safe_open(ul_dat, "r");
    code = safe_open(izl_dat, "w");
    
    while ((c=fgetc(in)) != EOF) {
    	if(isalpha(c) > 0)
        	fprintf(code, "%c", c+1);
        else
        	fprintf(code, "%c", c);
    }
    
    fclose(in);
    fclose(code);
}
void dekodiraj(char *ul_dat, char *izl_dat) {
    char c;
    FILE *code, *decode;
    
    code = safe_open(ul_dat, "r");
    decode = safe_open(izl_dat, "w");

    while ((c=fgetc(code)) != EOF) {
    	if(isalpha(c - 1) > 0)
        	fprintf(decode, "%c", c-1);
        else
        	fprintf(decode, "%c", c);
    }
    
    fclose(code);
    fclose(decode);
}
