/*
	Iz ulazne datoteke ucitati niz studenata koji
	su polozili ispit (indeks, ime, ocena). Koristiti
	funkcije, ime ulazne datoteke prihvatiti kroz
	argumente komandne linije.
	U izlaznu datoteku "najvisi.txt" ispisati
	podatke o studentu sa najvisim prosekom
	U izlaznu datoteku "najnizi.txt" ispisati
	podatke o studentu sa najnizim prosekom
	Na standardnom izlazu ispisati prosecnu
	ocenu svih studenata
*/

//PRIMER POZIVA ./zadatak5 studenti.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 30
#define MAX_INDEX 10
#define MAX_SIZE 50

typedef struct student_st {
    char index[MAX_INDEX];
    char ime[MAX_NAME];
    unsigned ocena;
}STUDENT;

FILE *safe_open(char*, char*);
void ucitavanje (FILE *, STUDENT *, int *);
void resenje (FILE *, FILE*, STUDENT *, int);

int main(int brArg, char *args[]) {

    STUDENT niz[MAX_SIZE];
    int n;
    FILE *in, *max_out, *min_out;
    
    if (brArg != 2) {
      puts("Niste dobro pozvali program.");
      exit(EXIT_FAILURE);
    }
    
    char smax[] = "najvisi.txt";
    char smin[] = "najnizi.txt";

    in = safe_open(args[1], "r");
    max_out = safe_open(smax, "w");
    min_out = safe_open(smin, "w");

    ucitavanje(in, niz, &n);
    resenje(max_out,min_out,niz, n);

    fclose(in);
    fclose(max_out);
    fclose(min_out);

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

void ucitavanje (FILE *in, STUDENT *niz, int *i) {
    STUDENT temp;
    int br = 0;

    while(fscanf(in, "%s %s %u", temp.index, temp.ime, &temp.ocena)!=EOF) {
        strcpy(niz[br].ime, temp.ime);
        strcpy(niz[br].index, temp.index);
        niz[br].ocena = temp.ocena;
        br++;
    }
    *i = br;
}

void resenje (FILE *maxout, FILE *minout, STUDENT *niz, int n) {
    unsigned max_ocena = niz[0].ocena;
    unsigned min_ocena = niz[0].ocena;
    unsigned suma = niz[0].ocena;
    int i;

    for (i=1; i<n; i++) {
        suma += niz[i].ocena;
        if (niz[i].ocena > max_ocena) {
            max_ocena = niz[i].ocena;
        }

        if (niz[i].ocena < min_ocena) {
            min_ocena = niz[i].ocena;
        }
    }

    for (i=0; i<n; i++) {
        if (niz[i].ocena == max_ocena)
            fprintf(maxout, "%s %s %u\n", niz[i].index, niz[i].ime, niz[i].ocena);
        if (niz[i].ocena == min_ocena)
            fprintf(minout, "%s %s %u\n", niz[i].index, niz[i].ime, niz[i].ocena);
    }

    printf("Prosecna ocena studenata je %.2f.\n", (float)suma/n);
}
