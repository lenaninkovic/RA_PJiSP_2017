/*
Napisati program koji pronalazi prvi
element niza koji je najbliži srednjoj
vrednosti niza celih brojeva zadate
dužine n. Niz može da ima najviše 20
elemenata.

*/
#include <stdio.h>
#include <math.h>
#define MAX_SIZE 20

int main() {
	int niz[MAX_SIZE];
	float sr_vr = 0;
	int n, i, najblizi;
	
	do {
		printf("Unesite velicinu niza (maksimalno do %d elemenata): ", MAX_SIZE);
		scanf("%d", &n);
	} while(n <= 0 || n > MAX_SIZE);

	for (i = 0; i < n; i++) {
		printf("niz[%d] = ", i+1);
		scanf("%d", &niz[i]); 
	}
	
	printf("\nNiz: [");	
	for (i = 0; i < n; i++) {
		printf("%d", niz[i]);
		if (i != n-1) printf(", ");
	}
	printf("]\n");	
	
	for (i = 0; i < n; i++) {
		sr_vr += niz[i];
	}
	
	sr_vr /= n;
	
	najblizi = niz[0];
	for (i = 1; i < n; i++) {
		if(fabs(sr_vr - niz[i]) < fabs(sr_vr - najblizi)) {
			najblizi = niz[i];
		}
	}
	
	printf("Element najblizi srednjoj vrednosti %.2f je %d.\n", sr_vr, najblizi);
	
	return 0;
}
