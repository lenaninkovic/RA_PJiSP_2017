/*
	Napisati program koji ucitava niz od n
	elemenata niza strukture auto, koja
	sadrži sledeca polja:
	Marka automobila (jedna rec, do 20 karaktera)
	Kubikaza (prirodan broj)
	Godiste (prirodan broj)
	Na osnovu zadate kubikaze pronaci
	najnoviji auto sa kubikazom ne
	vecom od zadate i ispisati njegove
	podatke na standardni izlaz.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 30
#define MAX_MARKA 21

typedef struct auto_st {
    char marka[MAX_MARKA];
    int kubikaza;
    int godiste;
}AUTO;

void ucitaj(AUTO *, int *);
void ispisi_jednu(AUTO);
void ispisi_niz(AUTO *, int);
void najnoviji(AUTO *, int, int);

int main() {

    AUTO niz[MAX_SIZE];
    int n, kub;

    ucitaj(niz, &n);
    ispisi_niz(niz, n);

    printf("Unesite zeljenu kubikazu: ");
    scanf("%d", &kub);

    najnoviji(niz, n, kub);

    return 0;
}

void ucitaj(AUTO *niz, int *pn) {

    do {
        printf("Unesite broj automobila (do maksimalnih %d): ", MAX_SIZE);
        scanf("%d", pn);
    } while (*pn <= 0 || *pn > MAX_SIZE);

    int i;
    for(i=0; i<*pn; i++) {
        printf("Unesite marku %d. automobila: ", i+1);
        //fflush(stdin);
        __fpurge(stdin);
        gets(niz[i].marka);
        printf("Unesite kubikazu %d. automobila: ", i+1);
        scanf("%d", &niz[i].kubikaza);
        printf("Unesite godiste %d. automobila: ", i+1);
        scanf("%d", &niz[i].godiste);
    }
}

void ispisi_jednu(AUTO a) {

    printf("\tMarka: %s\n\tKubikaza: %d\n\tGodiste: %d\n", a.marka, a.kubikaza, a.godiste);
    
}

void ispisi_niz(AUTO *niz, int n) {

    int i;

    for(i=0; i<n; i++) {
        printf("%d. auto: \n", i+1);
        ispisi_jednu(niz[i]);
        printf("\n");
    }
}

void najnoviji(AUTO *niz, int n, int granica) {

    int i;
    int max_god;
    int max_index;

    for (i=0; i<n; i++) {       //Pronaci prvi auto kome kubikaza odgovara uslovu i proglasiti ga najnovijim
        if (niz[i].kubikaza <= granica) {
            max_god = niz[i].godiste;
            max_index = i;
            break;
        }
    }

    for (i=max_index+1; i<n; i++) {
        if (niz[i].kubikaza <= granica && max_god < niz[i].godiste) {
            max_god = niz[i].godiste;
            max_index = i;
        }
    }

    printf("Najnoviji auto sa kubikazom ne vecom od %d je: \n", granica);
    ispisi_jednu(niz[max_index]);
    
}
