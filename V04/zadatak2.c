/*
Napisati program koji proverava da li je
učitani string palindrom. Program napraviti
tako da radi za reči a potom ga proširiti da
radi i sa rečenicama (ignorišući znakove
razmaka) kako bi string “Ana voli Milovana”
program registrovao kao palindrom.
*/

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 101

int main() {
	
	char niz[MAX_SIZE], b[MAX_SIZE];
	int i, j;
	
	//unos stringa
	printf("Unesite string: ");
	__fpurge(stdin);
	gets(niz);
	
	//smanjujemo slova
	i = 0;
	while(niz[i]) {
		if (niz[i] >= 'A' && niz[i] <= 'Z')
			niz[i] += 32;
		i++;
	}
	
	
	
	//izbacivanje razmaka
	j = 0;
	for (i = 0; i < (int)strlen(niz); i++) {
		if(niz[i]!= ' ' && niz[i] != '\t') {
			b[j] = niz[i];
			j++;
		}
	}
	b[j] = '\0';
	int ind = 0;
	
	//provera da li je palindrom
	for(i = 0, j = (int)strlen(b) - 1; i < (int)strlen(b)/2; i++, j--){
		if(b[i] == b[j])
			ind = 1;
		else 
			ind = 2;
	}
	
	if (ind == 1) printf("String je palindrom. \n");
	else printf("String nije palindrom.\n");
	
	return 0;
}



