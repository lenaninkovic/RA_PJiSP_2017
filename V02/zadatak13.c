/*
Napisati program koji za dati prirodan broj n izračunava:
    S = 1 * 2 + 2*3*4 + ... + (n+0)*(n+1)*...*(n+n).
*/

#include <stdio.h>

int main() {
	
	int n, S = 0, p;
	do {
		printf("Unesite prirodan broj:\t");
		scanf("%d", &n);

	} while (n <= 0);	//}while (!(n>0));

	
	int i,j;
	//Prvi ciklus sluzi da bi se kreirali sabirci
	for (i = 1; i <= n; i++) {
		//Drugi ciklus sluzi da bi se kreirali cinioci u okviru svakog sabirka
		p = 1;
		for (j = i; j <= 2*i; j++) {
			p *= j;		
		}
		S += p;
	}	
	
	printf("Vrednost datog niza za prirodan broj %d iznosi %d.\n", n, S);

	return 0;
}
