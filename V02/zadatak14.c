/*
    Dat je niz od maksimalno 30 celobrojnih elemenata.
    Ucitati n elemenata, zatim ucitati ceo broj br.
    Na izlazu ispisati ceo niz i broj pojavljivanja broja br u nizu.    
*/

#include <stdio.h>

#define MAX_SIZE 30

int main() {
    int a[MAX_SIZE];
    int i, n, br;

    do {
        printf("Unesite broj clanova nizova: ");
        scanf("%d", &n);
    } while(n <= 0 || n > MAX_SIZE);

    for(i = 0;i < n;i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("Unesite cifru ciji ce se broj pojavljivanja proveravati: ");
    scanf("%d", &br);

    int broj_pojavljivanja = 0;

    for(i = 0;i < n;i++) {
        if(a[i] == br) {
            broj_pojavljivanja++;
        }
    }

    printf("Broj %d u nizu a = [", br);

    for(i = 0;i < n;i++) {
        if(i > 0) {
            printf(", ");
        }
        printf("%d", a[i]);
    }
    printf("] pojavljuje se %d puta.\n", broj_pojavljivanja);

    return 0;
}
