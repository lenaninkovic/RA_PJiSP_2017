/*
	Ucitati niz tačaka u prostoru (maksimalno
	30). Naci tacku koja je najbliza
	koordinatnom početku. Koristiti funkcije.
	Naci tacku koja je
	najudaljenija.
	Realizovati vektorski proizvod.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 30

typedef struct tacka_st {
    float x, y, z;
}TACKA;

void ucitaj(TACKA *, int *);
void ispisi_jednu(TACKA);
void ispisi_niz(TACKA *, int);
float rastojanje(TACKA, TACKA);
void najbliza(TACKA*, int);
void najdalja(TACKA *, int);
void vektorski_proizvod(TACKA*);

int main() {

    TACKA niz[MAX_SIZE];
    int n;

    ucitaj(niz, &n);
    ispisi_niz(niz, n);
    najbliza(niz, n);
    najdalja(niz, n);
    vektorski_proizvod(niz);
    
    return 0;
}

void ucitaj(TACKA *niz, int *pn) {

    do {
        printf("Unesite broj tacaka (do maksimalnih %d): ", MAX_SIZE);
        scanf("%d", pn);
    } while (*pn <= 0 || *pn > MAX_SIZE);

    int i;
    for(i=0; i<*pn; i++) {
        printf("Unesite koordinate tacke %d (X Y Z): ", i+1);
        scanf("%f %f %f", &niz[i].x, &niz[i].y, &niz[i].z);
    }
}

void ispisi_jednu(TACKA t) {
    printf("(%.2f, %.2f, %.2f)", t.x, t.y, t.z);
    printf("\n");
}

void ispisi_niz(TACKA *niz, int n) {
    int i;

    for(i=0; i<n; i++) {
        printf("%d. tacka: ", i+1);
        ispisi_jednu(niz[i]);
        //printf("\n");
    }
}

float rastojanje(TACKA t1, TACKA t2) {

    return sqrt((t1.x - t2.x)*(t1.x - t2.x) + (t1.y - t2.y)*(t1.y - t2.y) + (t1.z - t2.z)*(t1.z - t2.z));
    
}

void najbliza(TACKA *niz, int n) {

    int i, index;
    TACKA kp;
    kp.x = 0.0;
    kp.y = 0.0;
    kp.z = 0.0;
    float min = rastojanje(niz[0], kp);
    float temp;

    for(i=1;i<n;i++) {
        temp = rastojanje(niz[i], kp);
        if (min > temp) {
                min = temp;
                index = i;
        }
    }

    printf("Tacka koja je najbliza koordinatnom pocetku je: ");
    ispisi_jednu(niz[index]);
    printf("\n");
}

void najdalja(TACKA *niz, int n) {

    int i, index;
    TACKA kp;
    kp.x = 0.0;
    kp.y = 0.0;
    kp.z = 0.0;
    float max = rastojanje(niz[0], kp);
    float temp;

    for(i=1;i<n;i++) {
        temp = rastojanje(niz[i], kp);
        if (max < temp) {
                max = temp;
                index = i;
        }
    }

    printf("Tacka koja je najudaljenija od koordinatnog pocetka je: ");
    ispisi_jednu(niz[index]);
    printf("\n");
}

void vektorski_proizvod(TACKA *niz) {

    TACKA rezultat;
    TACKA t1 = niz[0];
    TACKA t2 = niz[1];
    
    rezultat.x = t1.y*t2.z - t1.z*t2.y;
    rezultat.y = t1.z*t2.x - t1.x*t2.z;
    rezultat.z = t1.x*t2.y - t1.y*t2.x;

    printf("Za vektore: A ");
    ispisi_jednu(t1);
    printf(" i B ");
    ispisi_jednu(t2);
    printf(" rezultat vektorskog proizvoda je: ");
    ispisi_jednu(rezultat);
}
