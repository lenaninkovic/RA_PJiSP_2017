#include <stdio.h>
#include <math.h>
int main() {
	double a = 2.0;
	double b = 4.0;
	double c = 5.0;
	double s, P;

	s = (a + b + c) / 2;
	P = sqrt(s * (s-a) * (s-b) * (s-c));

	printf("P = %d\n",P);

	return 0;
}
