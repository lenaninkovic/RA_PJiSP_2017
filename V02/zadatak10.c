/*
Napisati program koji ispituje da li je dati prirodan
broj n prost. Broj je prost ako je deljiv samo sa jedan
i sa samim sobom.
*/

#include <stdio.h>

int main() {
	
	int n;
	do {
		printf("Unesite prirodan broj:\t");
		scanf("%d", &n);

	} while (n <= 0);	//}while (!(n>0));

	int i, podeljen = 0;
	/*
	Promenljiva podeljen sluzi mi kao indikator prostog broja. 
	Ukoliko zadati broj n nije deljiv ni sa jednim brojem izmedju
	2 i sebe samog, njena vrednost ostace 0. Pri prvom deljenju bez 
	ostatka, pak, njena vrednost postavlja se na 1 i prekida se sa 
	daljom proverom, jer broj nije prost.
	*/
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			printf("Broj %d nije prost.\n", n);
			podeljen = 1;
			break;
		}
	}
	
	if (!podeljen) {
		printf("Broj %d je prost.\n", n);
	}
	
	return 0;
}


