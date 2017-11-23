#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 30
#define MAX_INDEX 12
#define MAX_SIZE 100

typedef struct student_st {
    char index[MAX_INDEX];
    char ime[MAX_NAME];
    char prezime[MAX_NAME];
    unsigned poeni;
} STUDENT;

FILE *safe_open(char*, char*);
void ucitavanje (FILE *, STUDENT *, int *);
void ispis(FILE *, STUDENT *, int);
void sortiraj(STUDENT *, int);
void min_max_duzina_prezimena(STUDENT *, int, int *, int *);
void min_max_prezime(STUDENT *, int);
void preko_poena(STUDENT *, int, char *);
void prosecna_duzina_imena(STUDENT *, int);


int main(int brArg, char *args[]) {

    STUDENT niz[MAX_SIZE];
    int n;
    FILE *in;
    
    if (brArg != 3) {
      puts("Niste dobro pozvali program.");
      exit(EXIT_FAILURE);
    }
    
    in = safe_open(args[1], "r");
    
    ucitavanje(in, niz, &n);
    preko_poena(niz, n, args[2]);
    sortiraj(niz, n);
	min_max_prezime(niz, n);
	prosecna_duzina_imena(niz, n);
	
    fclose(in);
    
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

void ucitavanje(FILE *in, STUDENT *niz, int *i) {
    STUDENT temp;
    int br = 0;

    while(fscanf(in, "%s %s %s %u", temp.index, temp.ime, temp.prezime, &temp.poeni) != EOF) {
        strcpy(niz[br].index, temp.index);
        strcpy(niz[br].ime, temp.ime);
        strcpy(niz[br].prezime, temp.prezime);
        niz[br].poeni = temp.poeni;
        br++;
    }
    
    *i = br;
}

void sortiraj(STUDENT *niz, int n) {
    FILE *s;
    int j, i = 0;
    STUDENT temp;
    
    s = safe_open("sortirani_studenti.txt", "w");
    
    for(; i < n -1; ++i)
        for(j = i + 1; j < n ; ++j) {
            if(strcmp(niz[i].index, niz[j].index) > 0) {
                strcpy(temp.index, niz[i].index);
                strcpy(temp.ime, niz[i].ime);
                strcpy(temp.prezime, niz[i].prezime);
                temp.poeni = niz[i].poeni;
                
                strcpy(niz[i].index, niz[j].index);
                strcpy(niz[i].ime, niz[j].ime);
                strcpy(niz[i].prezime, niz[j].prezime);
                niz[i].poeni = niz[j].poeni;
                
                strcpy(niz[j].index, temp.index);
                strcpy(niz[j].ime, temp.ime);
                strcpy(niz[j].prezime, temp.prezime);
                niz[j].poeni = temp.poeni;
            }
        }
    ispis(s, niz, n);
    
    fclose(s);
}

void min_max_duzina_prezimena(STUDENT *niz, int n, int *mins, int *maxs) {
	int i = 1;
	*maxs = strlen(niz[0].prezime);
	*mins = strlen(niz[0].prezime);
	
	for(; i < n; i++) {
		if(strlen(niz[i].prezime) > *maxs) {
			*maxs = strlen(niz[i].prezime);
		} else if(strlen(niz[i].prezime) < *mins) {
			*mins = strlen(niz[i].prezime);
		}
	}

}
void min_max_prezime(STUDENT *niz, int n) {
	int i = 0, maxs, mins;
	
	//Zbog mogucnosti da vise prezimena ima istu duzinu trazi se koje su duzine najduzeg i najkraceg
	min_max_duzina_prezimena(niz, n, &mins, &maxs);
	
	for(; i < n; i++) {
		//za svako prezime se poredi da li ima istu duzinu kao najduze, ako da ispisuje se
		if(strlen(niz[i].prezime) == maxs) {
			printf("Student sa najduzim prezimenom je:\n%s %s %s.\n", niz[i].index, niz[i].ime, niz[i].prezime);
		}
		//za svako prezime se poredi da li ima istu duzinu kao najkrace, ako da ispisuje se
		if(strlen(niz[i].prezime) == mins) {
			printf("Student sa najkracim prezimenom je:\n%s %s %s.\n", niz[i].index, niz[i].ime, niz[i].prezime);
		}
	}
}

void preko_poena(STUDENT *niz, int n, char *ppoeni) {
	FILE *p;
	int i = 0;
	
	char naziv[100];
	strcpy(naziv, "preko_");
	strcat(naziv, ppoeni);
	strcat(naziv, "_poena.txt");
	
	p = safe_open(naziv, "w");
	
	for(; i < n; i++) {
		if(niz[i].poeni > atoi(ppoeni))
			fprintf(p, "%s %s %s %u\n", niz[i].index, niz[i].ime, niz[i].prezime, niz[i].poeni);
	}
	
	fclose(p);
}

void prosecna_duzina_imena(STUDENT *niz, int n) {
	FILE *p;
	int i = 0;
	float dimena = 0;
	
	p = safe_open("izlaz.txt", "w");
	
	for(; i < n; i++) {
		dimena += strlen(niz[i].ime);
	}
	
	fprintf(p, "Prosecna duzina imena studenta iznosi %.2f karaktera.\n", dimena/n);
	
	fclose(p);
}

void ispis(FILE *pizlazni, STUDENT *niz, int n){
	int i = 0;
	for(; i <n; i++) {
    	fprintf(pizlazni, "%s %s %s %u\n", niz[i].index, niz[i].ime, niz[i].prezime, niz[i].poeni);
    }
}
