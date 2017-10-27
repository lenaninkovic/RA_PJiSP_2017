/*
Izračunati površinu trougla upotrebom Heronovog obrasca, vrednosti stranica uneti sa tastature. Na izlazu štampati vrednost površine trougla na dve decimale.
*/

#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c;
    float s,P;
    
	printf("Unesite vrednost stranice a: ");
	scanf("%f", &a);
	printf("Unesite vrednost stranice b: ");
	scanf("%f", &b);
	printf("Unesite vrednost stranice c: ");
	scanf("%f", &c);

    s=(a+b+c)/2;
    P=sqrt( s*(s-a)*(s-b)*(s-c));
    
    printf("P = %.2f\n",P);
    
    return 0;
}
