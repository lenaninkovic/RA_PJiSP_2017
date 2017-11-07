/*
*	Napisati program za transponovanje kvadratne
*	matrice sa realnim elementima. Na početku
*	programa potrebno je učitati dimenziju i
*	elemente matrice. (Zadatak 3.12 iz zbirke L. K.)

*/

#include <stdio.h>
#define MAX 10

int main() {
	int n; //Dimenzija kv. matrice
	double A[MAX][MAX]; //Kvadratna matrica maksimalnih dimenzija MAX x MAX
	int i, j;

	printf("n=");
	scanf("%d", &n);

	//Učitavanje matrice
	printf("Unesite elemente matrice: \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("A[%d][%d] = ", i, j);
			scanf("%lf", &A[i][j]);
		}
	}

	// Ispisivanje matrice, cisto radi lakse preglednosti
    	for(i = 0;i < n;i++) {
		for(j = 0;j < n;j++) {
			printf("%lf\t", A[i][j]);
		}
	printf("\n");
    }

	//Transponovanje
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) { //Ne idemo do kraja da ne bismo 2x transponovali i poništili efekat
			double t = A[i][j]; //Pomoćna promenljiva
			A[i][j] = A[j][i];
			A[j][i] = t; 
		}
	}

	//Ispis matrice
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%.2lf ", A[i][j]);
		}
		printf("\n");
	}

	return 0;
}
