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
void kodiraj(FILE *ul_dat, FILE *izl_dat);
void dekodiraj(FILE *ul_dat, FILE *izl_dat);

int main() {

    FILE *in, *code, *decode;
    char sin[] = "ulazna";
    char scode[] = "kodirana.txt";
    char sdecode[] = "dekodirana.txt";

    in = safe_open(sin, "r");
    code = safe_open(scode, "w");
    decode = safe_open(sdecode, "w");

    kodiraj(in, code);
    fclose(code);
    code = safe_open(scode, "r");
    dekodiraj(code, decode);

    fclose(in);
    fclose(code);
    fclose(decode);

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

void kodiraj(FILE *ul_dat, FILE *izl_dat) {
    char c;
    while ((c=fgetc(ul_dat)) != EOF) {
        fprintf(izl_dat, "%c", c+1);
    }
}
void dekodiraj(FILE *ul_dat, FILE *izl_dat) {
    char c;
    while ((c=fgetc(ul_dat)) != EOF) {
        fprintf(izl_dat, "%c", c-1);
    }
}
