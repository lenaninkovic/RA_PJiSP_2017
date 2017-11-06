/*
Napisati program koji ispisuje string
obrnutim redom. Napraviti kratak test
program (učitati string i ispisati obrnutim
redosledom karaktere) sa i bez upotrebe f-ije
strlen().
*/

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 101

void unesi(char*);
void ispisi_obrnuto(char *, int);
int duzina_stringa(char *);

int main() {

	char niz[MAX_SIZE];
	int i;
	
	printf("Unesite string za proveru: ");
	__fpurge(stdin);
	gets(niz);
	
	printf("Sa upotrebom funkcije strlen: \n");
	int duzina = strlen(niz);
	
	for (i = duzina; i >= 0; i--)
		printf("%c", niz[i]);

	printf("\n");
	
	printf("Bez upotrebe funkcije strlen: \n");
	
	//brojimo koliko ima znakova
	int brojac = 0;
	
	while(niz[brojac] != '\0') {
		brojac++;
	}
	
	//obrnuti ispis
	for (i = brojac; i >= 0; i--)
		printf("%c", niz[i]);

	printf("\n");
	
	return 0;
}



