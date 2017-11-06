/*
Napisati program koji od korisnika
učitava niz stringova i ispisuje ih na
ekran. Program treba od korisnika
najpre da učita dužinu niza (odnosno
broj stringova), a zatim svaki string.
*/

#include <stdio.h>
#define max_size 30

int main() {
	
	char str[max_size][max_size];
	int n, i;
	
	//unos stringova
	do{
		printf("Unesite broj stringova koje zelite da upisete do maksimalno %d: ", max_size);
		scanf("%d", &n);
	} while(n <= 0 || n > max_size);
	
	for(i = 0; i < n; i++) {
		printf("Unesite %d. string: ", i+1);
		scanf("%s", str[i]);
	}
	
	
	//ispis stringova
	for(i = 0; i < n; i++) {
		printf("%d. string: %s\n", i+1, str[i]);
	}
		
	return 0;
}
