/*

Dat je niz C od maksimalno 80
karaktera.
Ucitati n karaktera u niz C i formirati
niz A, pri čemu su elementi niza A
samo slova iz niza C.


*/

#include <stdio.h>
#define MAX_SIZE 80

int main() {
	char C[MAX_SIZE], A[MAX_SIZE];
	
	int n, i, j = 0;
	
	do {
		printf("Unesite velicunu niza C (maksimalno do %d elemenata): ", MAX_SIZE);
		__fpurge(stdin);
		scanf("%d", &n);
	} while(n <= 0 || n > MAX_SIZE);
	
	for (i = 0; i < n; i++) {
		__fpurge(stdin);
		printf("C[%d] = ", i+1);
		scanf("%c", &C[i]); 
		/*
		ukoliko ne obrisem ulazni bafer pozivom funkcije __fpurge(stdin)
		(u Windows-u je to fflush(stdin)) moram scanf formatirati sa RAZMAKOM ISPRED %c
		scanf(" %c", &C[i]);
		*/
	}

	printf("Niz C = [");	
	for (i = 0; i < n; i++) {
		printf("%c", C[i]);
		if (i != n-1) printf(", ");
	}
	printf("]\n");	
	
	for (i = 0; i < n; i++) {
		//ako je u pitanju malo slovo   ILI   veliko slovo
		if ( ('a' <= C[i] && 'z' >= C[i]) || ('A' <= C[i] && 'Z' >= C[i])  ) {
			A[j++] = C[i];
		}
	}
	
	printf("Niz A = [");	
	for (i = 0; i < j; i++) {
		printf("%c", A[i]);
		if (i != j-1) printf(", ");
	}
	printf("]\n");

	return 0;
}
