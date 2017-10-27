/*
Napisati program kojim se za zadato x izračunava f(x) po
formuli.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float y, x;

    printf("Uneti vrednost x: \n");
    scanf("%f", &x);

    if (x < 0)
        y = -7;
    else if (x >= 0 && x < 1)
        y = pow(x, 1/4) + 4.0;
    else if (x >= 1 && x < 13)
        y = 2 * sqrt(x) -5.1;
    else if (x >= 13)
        y = pow(x, 2)/9;

    printf("Vrednost funkcije: %.2f\n", y);

    return 0;
}
