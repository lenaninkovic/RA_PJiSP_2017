/*
	Prebrojati reci iz ulazne datoteke. U
	izlaznoj datoteci ispisati broj reci i
	najduzu pronadjenu rec. Koristiti
	funkcije, imena datoteka prihvatiti
	kroz argumente komandne linije.
*/


//PRIMER POZIVA ./zadatak4 ulazna izlazna

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 101

FILE *safe_open(char*, char*);
void prebrojavanje(FILE *, FILE *);

int main(int brArg, char *args[]) {

    FILE *in, *out;
    
    if (brArg != 3) {
      puts("Niste dobro pozvali program.");
      exit(EXIT_FAILURE);
    }

    in = safe_open(args[1], "r");
    out = safe_open(args[2], "w");

    prebrojavanje(in, out);

    fclose(in);
    fclose(out);

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


void prebrojavanje(FILE *in, FILE *out) {

    int broj =0;
    char string[MAX_STRING];
    int max_s = 0;
    int tmp_s;
    char longest[MAX_STRING];

    while(fscanf(in, "%s", string) != EOF) {
        broj++;
        tmp_s = strlen(string);
        if (max_s < tmp_s) {
            max_s = tmp_s;
            strcpy(longest, string);
        }
    }

    fprintf(out,"Ucitano je %d stringova od kojih je najduzi: %s.\n", broj, longest);
}
