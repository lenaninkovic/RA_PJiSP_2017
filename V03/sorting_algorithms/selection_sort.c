#include <stdio.h>

#define MAX_SIZE 20

int main() {
    double a[MAX_SIZE];
    int i, j, n;

    do {
        printf("Unesite broj elemenata nizova: ");
        scanf("%d", &n);
    } while(n <= 0 || n > 20);

    for(i = 0;i < n;i++) {
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }

    double temp;

    for(i = 0;i < n;i++) {
        for(j = i + 1;j < n;j++) {
            if(a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Niz nakon sortiranja: ");
    for(i = 0;i < n;i++) {
        if(i > 0) {
            printf(", ");
        }
        printf("%.2lf", a[i]);
    }

    printf("\n");

    return 0;
}
