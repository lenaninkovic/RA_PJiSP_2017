/*
    Napisati program koji ucitava vrednosti promenljivih a i b, 
    a zatim resava jednacinu ax + b = 0.
    Pokriti sve slucajeve za razlicite kombinacije vrednosti a i b.
*/

#include <stdio.h>

int main() {
    double a, b, x;

    printf("Unesite a: ");
    scanf("%lf", &a);

    printf("Unesite b: ");
    scanf("%lf", &b);

    printf("Jednacina %.2lf * x + %.2lf = 0 ", a, b); 
    if(a == 0) {
        if(b == 0) {
            printf("ima beskonacno mnogo resenja\n");
        } else {
            printf("nema resenje.\n");
        }
    } else {
        x = -b / a;
        printf("ima resenje %.2lf.\n", x);
    }

    return 0;
}
