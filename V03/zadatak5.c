/*
*	Napisati program za uređivanje kolona
*	pravougaone matrice sa realnim elementima po
*	neopadajućem redosledu zbirova elemenata po
*	kolonama. (Zadatak 3.13 iz zbirke L. K.)
*/

#include <stdio.h>
#define MAX_N 10
#define MAX_M 10

int main() {
	double A[MAX_N][MAX_M];
	double S[MAX_N]; // i-ti član niza sadrži sumu i-te kolone
	int n, m; // Veličine matrice
	int i, j, k;

	printf("n = ");
	scanf("%d", &n);
	printf("m = ");
	scanf("%d", &m);

	// Učitavanje matrice
	printf("Unesite elemente matrice: \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("A[%d][%d] = ", i, j);
			scanf("%lf", &A[i][j]);
		}
	}

	// Ispisivanje matrice, cisto radi lakse preglednosti
	for(i = 0;i < n; i++) {
			for(j = 0; j < m; j++) {
				printf("%lf\t", A[i][j]);
			}
			printf("\n");
	}

	// Računanje suma kolona
	for (j = 0; j < m; j++) {
		S[j] = 0; // Elementa vektora koji sadrzi sumu za j-tu kolonu
		for (i = 0; i < n; i++) {
			S[j] += A[i][j]; // Dodavanje članova kolone u sumu
		}
	}

	// Ispis sluzi kao provera da li su kolone sumirane kako treba
	printf("Niz suma kolona matrice: ");
	for (j = 0; j < m; j++) {
		printf("%lf ", S[j]);
	}
	printf("\n");

	// Proces sortiranja
	// Promenljive 'i' i 'j' odredjuju redne brojeve kolona u matrici
	for (i = 0; i < m; i++) {
		for (j = i; j < m; j++) {
			// Promene mesta kolonama
			if (S[i] > S[j]) {
				// Promenljiva 'k' za fiksirano 'i' i 'j' iterira kroz sve elemente te dve kolone.
				for (k = 0; k < n; k++) {
					double t = A[k][i];
					A[k][i] = A[k][j];
					A[k][j] = t;
				}
				// Promena vrednosti niza
				double p = S[i];
				S[i] = S[j];
				S[j] = p;
			}
		}
	}

	// Ispisivanje matrice
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%.2lf ", A[i][j]);
		}
		printf("\n");
	}

	return 0;
}
