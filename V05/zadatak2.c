#include <stdio.h>
#include <math.h>

double hipotenuza(double a, double b);

int main() {
	
	double a, b;
	double rez;
	
	printf("Unesite duzine kateta u formatu a, b: \n");
	scanf("%lf, %lf", &a, &b);
	
	rez = hipotenuza(a, b);
	
	//provera nejednakosti trouglova
	//provera unesenih vrednosi za a i b	
	while (a <= 0 || b <= 0) {
		printf("Unete vrednosti nisu bile dobre, unesite duzine kateta u formatu a, b: \n");
		scanf("%lf, %lf", &a, &b);
		rez = hipotenuza(a, b);
	}
	
	printf("Duzina hipotenuze je: %lf\n", rez);
	
	return 0;
}

double hipotenuza(double a, double b) {
	
	double c;
	c = sqrt(pow(a, 2) + pow(b, 2));
	
	return c;
}
