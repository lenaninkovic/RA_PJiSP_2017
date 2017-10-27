/*
    Napisati program koji ucitava matricu A 
	i ispisuje sumu elemenata koji se nalaze
    ispod glavne dijagonale matrice.
*/

#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int A[MAX_SIZE][MAX_SIZE];
    int i, j, n;

    do {
        printf("Unesite dimenzije matrice: ");
        scanf("%d", &n);
    } while (n <= 0 || n > MAX_SIZE);

    for(i = 0;i < n;i++) {
        for(j = 0;j < n;j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Ispisivanje matrice, cisto radi lakse preglednosti
    for(i = 0;i < n;i++) {
        for(j = 0;j < n;j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    int suma = 0;

    for(i = 0;i < n;i++) {
        for(j = 0;j < n;j++) {
            if(i > j) {
                suma += A[i][j];
            }
        }
    }

    printf("Suma elemenata ispod glavne dijagonale je: %d\n", suma);

    return 0;
}
