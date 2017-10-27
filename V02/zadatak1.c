/*
Napisati C program koji
ispisuje veci od dva
cela broja.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a, b;

    printf("Uneti prvi broj: \n");
    scanf("%d", &a);
    printf("Uneti drugi broj: \n");
    scanf("%d", &b);

    if (a>b)
        printf("Broj %d je veci. ", a);
    else
        printf("Broj %d je veci. ", b);

    return 0;
}
