#include <stdio.h>

int nzd(int, int);

int main() {
	int x, y;
	
	do {
		printf("Unesite x (x > 0): ");
		scanf("%d", &x);
	} while (x <= 0);
	do {
		printf("Unesite y (y > 0) : ");
		scanf("%d", &y);
	} while (y <= 0);

	printf("NZD(%d, %d) = %d\n", x, y, nzd(x,y));

	return 0;
}

int nzd(int x, int y) {
	if (x == 0) {
		return y;
	} else {
		return nzd(y % x, x);
	}
}
