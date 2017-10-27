#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, s = 0;

    printf("Uneti broj n: \n");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
        s += i;

    printf("s = %d\n", s);

    return 0;
}
