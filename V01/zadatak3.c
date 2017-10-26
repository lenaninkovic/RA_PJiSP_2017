/*
Napisati program koji od korisnika traži da unese tri celobrojne vrednosti, a zatim ispisuje njihov aritmetičku, harmonijsku, geometrijsku i kvadratnu sredinu.
*/

#include <stdio.h>
#include <math.h>

int main() {
	
	int a, b, c;
	float sredina;
	
	printf("Unesite tri celobrojne vrednosti, medjusobno odvojene zarezom (u formatu a,b,c):\t");
	scanf("%d,%d,%d", &a, &b, &c);
	
	sredina = (a+b+c)/3.0;
	printf("Aritmeticka sredina sledeca tri broja - %d, %d i %d - iznosi %f\n", a, b, c, sredina);

	sredina = 3/((1.0/a)+(1.0/b)+(1.0/c));
	printf("Harmonijska sredina sledeca tri broja - %d, %d i %d - iznosi %f\n", a, b, c, sredina);

	sredina = pow(a*b*c, 1/3.0);
	printf("Geometrijska sredina sledeca tri broja - %d, %d i %d - iznosi %f\n", a, b, c, sredina);

	sredina = sqrt((a*a + b*b + c*c)/3.0);
	printf("Kvadratna sredina sledeca tri broja - %d, %d i %d - iznosi %f\n", a, b, c, sredina);

	return 0;
}
