#include <stdio.h>
#define MAX_SIZE 30

int main() {

	int a[MAX_SIZE];
	int n, i, pom, *pa;
	pa = a;
	
	do {
		printf("Unesite broj elemenata niza: ");
		scanf("%d", &n);
	} while (n < 0 || n > MAX_SIZE);
	
	printf("Unesite elemente niza: \n");
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", pa + i);
	}
	
	//obrtanje redosleda elemenata
	for (i = 0; i < n/2; i++) {
		pom = *(pa + i);
		*(pa + i) = *(pa + n - 1 - i);
		*(pa + n  -1 - i) = pom;
	}
	
	printf("\nIspis elemenata niza: \n");
	for (i = 0; i < n; i++) {
		printf("a[%d] = %d \n", i, *(pa + i));
	}
	
	
	return 0;
}
