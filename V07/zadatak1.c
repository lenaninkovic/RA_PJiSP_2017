#include <stdio.h>
#include <stdlib.h>

struct dynamic_array_st {
	int *parray;
	int filled;
	int capacity;
};

void init_array(struct dynamic_array_st *);
void resize_array(struct dynamic_array_st *, int);
void add(struct dynamic_array_st *, int);
int size(struct dynamic_array_st);
void print_array(struct dynamic_array_st);
void destroy_array(struct dynamic_array_st *);
void remove_element_by_value(struct dynamic_array_st *);

int main() {
	
	struct dynamic_array_st d;
	init_array(&d);
	
	add(&d, 3);
	add(&d, 1);
	//add(&d, 2); //zakomentarisano da bismo imali slucaj da iskoriscenost niza padne ispod polovine njegovog kapaciteta 
	add(&d, 1); //za proveru da li brise ukoliko ima vise elementa sa istom vrednoscu
	
	print_array(d);
	printf("Array size: %d\n", size(d));
	
	add(&d, 5);
	
	print_array(d);
	printf("Array size: %d\n", size(d));
	
	add(&d, 6);
	
	print_array(d);
	printf("Array size: %d\n", size(d));
	
	remove_element_by_value(&d);
	
	print_array(d);
	printf("Array size: %d\n", size(d));
	
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

//metoda je prosirena sa parametrom mode - govori nam da li je bilo brisanja ili dodavanja u niz - 0 za dodavanje, 1 za brisanje
void resize_array(struct dynamic_array_st *pd, int mode) {
	if(pd->parray == NULL) {
		pd->capacity = 1;
	} else  if(mode == 0) {
		pd->capacity *=2;
	} else if(mode == 1) {
		pd->capacity /=2;
	}
	
	
	pd->parray = realloc(pd->parray, pd->capacity * sizeof(int));
}

void add(struct dynamic_array_st *pd, int value) {
	if(pd->filled == pd->capacity) {
		resize_array(pd, 0);
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

void remove_element_by_value(struct dynamic_array_st *pd) {

	int i, j, value;
	printf("Insert element value (to remove): \n");
	scanf("%d", &value);
	
	for(i = 0; i < pd->filled; i++) {
		if(pd->parray[i] == value) {
			//ukoliko se naisao na element koji treba da brise svi elementi posle njega se pomeraju za jedno mesto u levo
			for(j = i; j < pd->filled; j++){
            	pd->parray[j] = pd->parray[j+1];
			}
			pd->filled--;
			// da li je iskorišćenost niza pala ispod polovine njegovog kapaciteta 
			if(pd->filled < pd -> capacity/2) { 
				resize_array(pd, 1);
			}
			
		/* 	imali smo brisanje, elementi su pomereni za jedno mesto u levo - na poziciji i se sada nalazi
			element koji je bio na i+1 -> trebamo i za njega da proverimo da li slucajno treba da se izbrise
			-> moramo da se ponovo vratimo na istu poziciju i zato smanjujemo i
		*/
		i--;
			
		}
    }
    
}

void destroy_array(struct dynamic_array_st *pd) {
	free(pd->parray);
	init_array(pd);
}
