/*
    Dat je niz od maksimalno 20 realnih elemenata. 
	Ucitati n elemenata,
    a zatim naci maksimalnu vrednost.
*/

#include <stdio.h>
#define MAX_SIZE 20


int main() {
    double a[MAX_SIZE], max;
    int i, n;

    do {
        printf("Unesite broj elemenata niza: ");
        scanf("%d", &n);
    } while(n <= 0 || n > MAX_SIZE);

    for(i = 0;i < n;i++) { 
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }

    max = a[0];
    for(i = 1;i < n;i++) {  // nema potrebe ponovo proveravati prvi, jer smo njega proglasili za maksimum u prethodnoj liniji
        if(a[i] > max) {
            max = a[i]; 	// ako je trenutni element veci, on je novi maksimum
        }
    }

    /* prosli smo kroz ceo niz i pokusavali da trenutni maksimum "oborimo" 
	vecom trenutnom vrednoscu
    u ovom momentu se u promenljivoj max nalazi maksimalna vrednost niza */

    printf("Maksimalni element niza je %lf.\n", max);

    return 0;
}
