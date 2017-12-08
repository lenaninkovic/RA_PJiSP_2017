#include <stdio.h>
#include <stdlib.h>

struct dynamic_array_st {
	int *parray;
	int filled;
	int capacity;
};

void init_array(struct dynamic_array_st *);
void resize_array(struct dynamic_array_st *);
void add(struct dynamic_array_st *, int);
int size(struct dynamic_array_st);
void print_array(struct dynamic_array_st);
void destroy_array(struct dynamic_array_st *);
struct dynamic_array_st prime_numbers(struct dynamic_array_st);

int main() {
	
	struct dynamic_array_st d;
	
	init_array(&d);
		
	add(&d, 3);
	add(&d, 1);
	add(&d, 2); 
	
	print_array(d);
	printf("Array size: %d\n", size(d));
	
	add(&d, 5);
	
	print_array(d);
	printf("Array size: %d\n", size(d));
	
	add(&d, 6);
	
	print_array(d);
	printf("Array size: %d\n", size(d));
		
	printf("\nPrime numbers array: \n");
	print_array(prime_numbers(d));
		
	destroy_array(&d);
	
	printf("\nAfter destroy:\n");
	print_array(d);
	printf("Array size: %d\n", size(d));
	
	return 0;
}

void init_array(struct dynamic_array_st *pd) {
	pd->parray = NULL;
	pd->filled = 0;
	pd->capacity = 0;
}


void resize_array(struct dynamic_array_st *pd) {
	if(pd->parray == NULL) {
		pd->capacity = 1;
	} else {
		pd->capacity *=2;
	} 
	
	pd->parray = realloc(pd->parray, pd->capacity * sizeof(int));
}

void add(struct dynamic_array_st *pd, int value) {
	if(pd->filled == pd->capacity) {
		resize_array(pd);
	}
	
	pd->parray[pd->filled] = value;
	pd->filled++;
}

int size(struct dynamic_array_st d) {
	return d.capacity;
}

void print_array(struct dynamic_array_st d) {
	int i;
	printf("[");
	for(i = 0; i < d.filled; i++) {
		if(i > 0) {
			printf(", ");
		}
		printf("%d", d.parray[i]);
	}
	printf("]\n");
}

struct dynamic_array_st prime_numbers(struct dynamic_array_st d) {

	int i, j, isPrime;
	struct dynamic_array_st primes;
	
	init_array(&primes);
	
	for(i = 0; i < d.filled; i++) {
		isPrime = 0;
		for (j = 2; j < d.parray[i]; j++) {
			if (d.parray[i] % j == 0) {
				isPrime = 1;
				break;
			}
		}
		if(!isPrime) {
			add(&primes, d.parray[i]);
		}
	}
	
	return primes;
}

void destroy_array(struct dynamic_array_st *pd) {
	free(pd->parray);
	init_array(pd);
}
