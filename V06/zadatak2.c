/*
	Napisi program koji ucitava niz od n
	elemenata niza strukture licnost, koja
	sadrži sledeca polja: ime, adresa, dan
	rodjenja, mesec rodjenja i godina
	rodjenja. Prikazati osobe koje su u
	horoskopu bik.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXIME 30
#define MAXADRESA 50
#define MAXDATUM 12
#define MAX_SIZE 30

typedef struct licnost_st {
    char ime[MAXIME];
    char adresa[MAXADRESA];
    unsigned dan;
    unsigned mesec;
    unsigned godina;
}LICNOST;

void ucitaj(LICNOST *, int *);
void ispisi_bikove(LICNOST*, int);
void ispisi_licnost(LICNOST);
void parsiraj(char *, unsigned*, unsigned*, unsigned*);

int main() {

    LICNOST niz[MAX_SIZE];
    int n;

    ucitaj(niz, &n);
    ispisi_bikove(niz,n);

    return 0;
}

void ucitaj(LICNOST *niz, int *pn) {

    do {
        printf("Unesite broj persona (do maksimalnih %d): ", MAX_SIZE);
        scanf("%d", pn);
    } while (*pn <= 0 || *pn > MAX_SIZE);

    int i;
    char datum[MAXDATUM];
    for(i=0; i<*pn; i++) {
        printf("Unesite ime %d persone: ", i+1);
        //fflush(stdin);
        __fpurge(stdin);
        gets(niz[i].ime);
        printf("Unesite adresu %d persone: ", i+1);
        //fflush(stdin);
        __fpurge(stdin);
        gets(niz[i].adresa);
        printf("Unesite datum %d persone (DD.MM.GGGG.):", i+1);
        gets(datum);
        parsiraj(datum, &niz[i].dan, &niz[i].mesec, &niz[i].godina);
    }
}

/*OVA FUNKCIJA NIJE OBAVEZNA, DATA JE KAO JOS JEDAN PRIMER KORISCENJA FUNKCIJA IZ BIBLIOTEKE string.h*/
void parsiraj(char *datum, unsigned *pd, unsigned *pm, unsigned *pg) {
    char temp[5];

    char *tacka = strchr(datum, '.');   //adresa prvog pojavljivanja . u datumu
    int i=0;
    while(datum!=tacka) {
        temp[i] = *datum;
        i++;
        datum++;
    }
    temp[i] = '\0';
    *pd = atoi(temp);


    datum++;
    tacka = strchr(datum, '.');         //adresa drugog pojavljivanja . u datumu
    i=0;
    while(datum!=tacka) {
        temp[i] = *datum;
        i++;
        datum++;

    }
    temp[i] = '\0';
    *pm = atoi(temp);



    datum++;
    tacka = strchr(datum, '.');         //adresa treceg pojavljivanja . u datumu
    i=0;
    while(datum!=tacka) {
        temp[i] = *datum;
        i++;
        datum++;

    }
    temp[i] = '\0';
    *pg = atoi(temp);
}


//od 21.04. do 22.05
void ispisi_bikove(LICNOST *niz, int n) {
    int i;
    for(i=0; i<n; i++) {
        if ((niz[i].mesec == 4 && (niz[i].dan>=21 && niz[i].dan <= 30)) || (niz[i].mesec == 5 && (niz[i].dan>=1 && niz[i].dan <= 22)))
            ispisi_licnost(niz[i]);
    }
}
void ispisi_licnost(LICNOST l) {
    printf("Ime: %s\nAdresa: %s\nDatum rodjenja: %u.%u.%u.\n", l.ime, l.adresa, l.dan, l.mesec, l.godina);
}
