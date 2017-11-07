#include <stdio.h>
#define MAX_SIZE 30

void ucitavanje(int *, int *);
void ispis(int *, int);
int suma(int *, int);
double srednja_vrednost(int *, int);
int min(int *, int);
int max(int *, int);

int main() {

	int niz[MAX_SIZE];
	int n, izbor;
    
    do {
    	printf("1. Ucitavanje niza\n");
        printf("2. Izracunavanje sume elemenata niza\n");
        printf("3. Izracunavanje srednje vrednosti elemenata niza\n");
        printf("4. Minimalni element niza\n");
        printf("5. Maksimalni element niza\n");
        printf("6. Ispisivanje niza\n");
        printf("7. Izlazak iz programa\n");
    
        printf("Izabrati opciju: ");
        scanf("%d", &izbor);
        
        switch(izbor) {
        	case 1: ucitavanje(niz, &n); break;
            case 2: printf("Suma elemenata niza je: %d\n", suma(niz, n)); break;
            case 3: printf("Srednja vrednost elemenata niza je: %.2lf\n", srednja_vrednost(niz, n)); break;
            case 4: printf("Minimalni element niza je: %d\n", min(niz, n)); break;
            case 5: printf("Maksimalni element niza je: %d\n", max(niz, n)); break;
            case 6: ispis(niz, n); break;
            case 7: break;
            default: printf("Uneti vrednost izmedju 1 i 7\n");
        }
        
        printf("\n");
    
    } while(izbor != 7); 
    
}

void ucitavanje(int *a, int *n) {
    int i;
    
    do {
        printf("Unesite broj elemenata niza: ");
        scanf("%d", n);
    } while(*n <= 0 || *n > MAX_SIZE);
    
    for(i = 0; i < *n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}    
    
void ispis(int *a, int n) {
    int i;
    
    printf("[");
    for(i = 0; i < n; i++) {
        if(i > 0) {
            printf(", ");
        }
        printf("%d", a[i]);
    }
    printf("]\n");
}

int suma(int *a, int n) {
    int i, s = 0;
    
    for(i = 0; i < n; i++) {
        s += a[i];
    }
    
    return s;
}

double srednja_vrednost(int *a, int n) {
    return (double) suma(a, n) / n;                  // ovde je moguce samo ovo napisati, jer je zabranjeno unosenje 0 za velicinu niza, 															inace obratiti paznju na taj slucaj "0/0"
}

int min(int *a, int n) {
    int i, min = a[0];
    
    for(i = 1; i < n; i++) {
        if(min > a[i]) {
            min = a[i];
        }
    }
    
    return min;
}

int max(int *a, int n) {
    int i, max = a[0];
    
    for(i = 1; i < n; i++) {
        if(max < a[i]) {
            max = a[i];
        }
    }
    
    return max;
}
	

