/*
Napisati program kojim se štampaju svi trocifreni Armstrongovi brojevi. 
Broj je Armstrongov ako je jednak zbiru kubova svojih cifara.
*/

#include <stdio.h> 
#include <math.h>

int main() {

	int i;
	int stotine, desetice, jedinice;

	printf("Svi trocifreni Armstrongovi brojevi su:\n");
	for(i = 100; i < 1000; i++) {
		jedinice = i % 10;
		desetice = (i/10) % 10;
		stotine = i/100;

		if (i == (pow(stotine, 3) + pow(desetice, 3) + pow(jedinice, 3)))
			printf("%d  ", i);
	}
	printf("\n");

	return 0;
}
