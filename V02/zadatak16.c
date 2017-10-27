/*
	Dat je niz X od maksimalno 25
	celobrojnih elemenata. Učitati n
	elemenata u niz X i formirati nizove A i
	B, pri čemu su elementi niza A parni
	elementi niza X, a elementi niza B su
	negativni elementi niza X. Ispisati
	nizove X, A i B.
*/
#include <stdio.h>
#define MAX_SIZE 25

int main() {
	
	int X[MAX_SIZE], A[MAX_SIZE], B[MAX_SIZE];
	//j sluzi da indeksira niz A, k da indeksira niz B
    int i, j=0, k=0, n;

    do {
        printf("Unesite broj clanova nizova: ");
        scanf("%d", &n);
    } while(n <= 0 || n > MAX_SIZE);

    for(i = 0;i < n;i++) {
        printf("X[%d] = ", i+1);
        scanf("%d", &X[i]);
    }
    
    for(i=0; i<n; i++) {
    	if (X[i]%2==0) {
    		A[j]=X[i];
    		j++;
    	}
    	if (X[i]<0) {
    		B[k]=X[i];
    		k++;
    	}
    }
    
    printf("\n");
    
    for(i = 0;i < n;i++) {
        printf("X[%d] = %d\n", i+1, X[i]);
    }
    
     printf("\n");
     
     for(i = 0;i < j;i++) {
        printf("A[%d] = %d\n", i+1, A[i]);
    }
    
     printf("\n");
     
     for(i = 0;i < k;i++) {
        printf("B[%d] = %d\n", i+1, B[i]);
    }
    
	return 0;
}
