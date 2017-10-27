#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ocena;

    printf("Uneti ocenu: \n");
    scanf("%d", &ocena);

    if(ocena == 5)
        printf("Odlican! \n");
    else if (ocena == 4)
        printf("Vrlo dobar! \n");
    else if (ocena == 3)
        printf("Dobar! \n");
    else if (ocena == 2)
        printf("Dovoljan! \n");
    else
        printf("Nedovoljan! \n");

    return 0;
}
