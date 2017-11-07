#include <stdio.h>

int faktorijel(int);
int suma_faktorijela(int);
void ispis_trocifrenih();

int main() {
    
    ispis_trocifrenih();

    return 0;
}

int faktorijel(int n) {
    int i, fakt = 1;
    
    for(i = n; i > 0; i--) {
        fakt *= i;
    }

    return fakt;
}

int suma_faktorijela(int broj) {
    int jedinica = broj % 10;
    int desetica = (broj / 10) % 10;
    int stotina = broj / 100;
    
    return faktorijel(jedinica) + faktorijel(desetica) + faktorijel(stotina);
}

void ispis_trocifrenih() {
    int i;
    
    for(i = 100; i < 1000; i++) {
        if(suma_faktorijela(i) == i) {
            printf("%d\n", i);
        }
    }
}
