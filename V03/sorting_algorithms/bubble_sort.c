#include <stdio.h>

#define MAX_SIZE 20

int main() {
    double a[MAX_SIZE];
    int i, j, n, changes;

    do {
        printf("Unesite broj elemenata nizova: ");
        scanf("%d", &n);
    } while(n <= 0 || n > 20);

    for(i = 0;i < n;i++) {
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }

    double temp;

    do {
        changes = 0;
        for(i = 1;i < n;i++) {
            if(a[i - 1] > a[i]) {
                temp = a[i - 1];
                a[i - 1] = a[i];
                a[i] = temp;
                changes = 1;
            }
        }
    } while(changes);

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
