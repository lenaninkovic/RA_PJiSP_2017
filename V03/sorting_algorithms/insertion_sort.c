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
        j = i;
        while(j >= 0 && a[j] < a[j - 1]) {
            // pomeranje svih clanova udesno kako bi se trenutni element "ubacio"
            // na odgovarajuce mesto (otud ime Insertion Sort)
            temp = a[j - 1];
            a[j - 1] = a[j];
            a[j] = temp;
            j--;
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
