#include <stdio.h>

int fib(int);

int main() {
	int n;
	
	do {
		printf("Unesite redni broj clana fibonacijevog niza: ");
		scanf("%d", &n);
	} while (n <= 0);

	printf("%d-ti clan fibonacijevog niza je: %d\n", n, fib(n));
	
	return 0;
}

int fib(int n) {
	if (n == 1 || n == 2) { 
		return 1; //prva dva člana su 1
	} else {
		return fib(n - 1) + fib(n - 2);
	}
}
