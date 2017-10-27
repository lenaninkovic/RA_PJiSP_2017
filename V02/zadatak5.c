/*
    Tri tačke su zadate koordinatama u ravni. Napisati program kojim se izračunava površina paralelograma čiji su vrhovi date tačke.
*/

#include <stdio.h>
#include <math.h>

int main() {
    int x1, x2, x3, y1, y2, y3;
    
    printf("Unesite koordinate prve tacke u obliku x,y:\t");
    scanf("%d,%d", &x1, &y1);
    printf("Unesite koordinate druge tacke u obliku x,y:\t");
    scanf("%d,%d", &x2, &y2);
    printf("Unesite koordinate trece tacke u obliku x,y:\t");
    scanf("%d,%d", &x3, &y3);

    float a, b, c;

    a = sqrt (pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt (pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt (pow(x1 - x3, 2) + pow(y1 - y3, 2));

    if((a + b) > c && (b + c) > a && (a + c) > b) {
        float s, P;

        s = (a+b+c)/2;
        P = 2 * sqrt(s * (s - a) * (s - b) * (s - c));

        printf("Povrsina paralelograma odredjenog datim tackama iznosi %.3f.\n", P);
    } else {
        printf("Date koordinate ne zadovoljavaju nejednakost trougla, samim tim nisu ni deo nekog paralelograma.\n");
    }

    return 0;
}

