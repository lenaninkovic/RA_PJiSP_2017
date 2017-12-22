#include <stdio.h>

int suma(int n);

int main() {
	int n;
	
	printf("Unesite broj: ");
	scanf("%d", &n);

	printf("%d\n", suma(n));

	return 0;
}

int suma(int n) {
	if (n == 0) {
		return 0;
	} else {
		return n % 10 + suma(n / 10); 
	}
}
