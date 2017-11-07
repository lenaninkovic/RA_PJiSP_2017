#include<stdio.h>

int prost(int);
void goldbah(int);

int main(){
	int broj;
	
	do{
		printf("Unesite paran broj veci od 2: ");
		scanf("%d", &broj);
	}while(broj % 2 != 0 || broj <= 2);

	goldbah(broj);

	return 0;
}

int prost(int n){
	int i;
	
	if(n == 2) {
	    return 1;
	}
	
	for(i = 2;i< n - 1;i++){
		if(n % i == 0){
			return 0;		//nije prost
		}
	}
	
	return 1;		//broj je prost
}

void goldbah(int paran_broj){
	int i;
	
	for(i = 2;i < paran_broj - 1;i++){
		if(prost(i) && prost(paran_broj - i)){
			printf("Broj %d moze se predstaviti kao zbir sledeca dva prosta broja: %d i %d\n", paran_broj, i, paran_broj - i);
			break;
		}
	}
}
