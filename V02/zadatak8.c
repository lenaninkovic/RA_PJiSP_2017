#include <stdio.h>
#include <stdlib.h>

int main(){

    int fak, n, i;

    fak = 1;

	do {
		printf("Unesite broj n: \n");
		scanf("%d", &n);
	} while (n < 1);

    for(i = 1; i <= n; i++)
        fak = fak*i;
        

    printf("Faktorijel od n je %d. \n", fak);

    return 0;
}
