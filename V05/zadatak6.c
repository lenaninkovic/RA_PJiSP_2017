#include <stdio.h>
#include <math.h>

void ucitavanje(int *);
int prost(int);
void ispis_prostih(int);

int main() {
    int n;
    
    ucitavanje(&n);
    ispis_prostih(n);

    return 0;
}

void ucitavanje(int *n) {

    do {
        printf("Ucitati pozitivan broj: ");
        scanf("%d", n);
    } while(*n < 0);
}

int prost(int n) {
    int i;
    
    if(n == 2) {
        return 1;       // 2 je granicni slucaj zato sto je prost broj, a deljiva je sa svim ciframa pre nje, ukljucujuci i nju (1, 2)
    }
    
    for(i = 2; i <= (int) ceil(sqrt(n)); i++) { //funkcija ceil vraca najmanji integer sa vrednoscu ne manjom od prosledjene
        if(n % i == 0) {
            return 0;
        } 
    }
    
    return 1;
}

void ispis_prostih(int n) {
    int i;
    
    for(i = 2; i <= n; i++) {
        if(prost(i)) {
            printf("%d\n", i);
        }
    }
}
