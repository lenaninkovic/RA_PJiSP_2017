/*
Napisati funkciju koja kao parametre uzima
jedan string i karakter, a vraća broj
pojavljivanja tog karaktera u string. Napisati
test program. (Primer: str=“tatatatira”,
c=‘a’, povratna vrednost je 4).
*/

#include <stdio.h>
#include <string.h>
#define max_size 20

int main() {

	char string[max_size];
	char c;
	int i, brojac = 0;
	
	printf("Unesite string: ");
	__fpurge(stdin);
	scanf("%s", string);
	
	printf("Unesite karakter za proveru: ");
	__fpurge(stdin);
	scanf("%c", &c);
	
	for(i = 0; i < strlen(string); i++ )
		if(string[i] == c) {
			brojac++;
		}
	
	printf("Broj ponavljanja karaktera %c u stringu %s je %d\n", c, string, brojac);
	

	return 0;
}
