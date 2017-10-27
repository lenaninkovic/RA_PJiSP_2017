/*
Sa standardnog ulaza učitati prirodne brojeve N i q.
Koristeći while ispisati sve brojeve od 2 do N koji 
su deljivi sa q.
*/

#include <stdio.h>

int main() {
	
	int N, q;
	do {
		printf("Unesite dva prirodna broja medjusobno odvojena zarezom - N,q:\t");
		scanf("%d,%d", &N, &q);

	} while (!(N > 0 && q > 0));	//}while (N<=0 || q <= 0);

	int i=2;
	while (i <= N) {
		if (i % q == 0) 
			printf("%d  ", i);
		i++;
	}

	printf("\n");
	return 0;
}


