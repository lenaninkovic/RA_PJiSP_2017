#include <stdio.h>
 
int fibonacci(int);

int main(){
    int brClanova, i;
    printf("Unesite broj clanova fibonacijevog niza: ");
    scanf("%d", &brClanova);
    
    printf("\n"); 
    for(i = 1; i <= brClanova; i++){
        printf("%d ", fibonacci(i));
    }
    printf("\n"); 
    
    return 0;
}

int fibonacci(int clan){
    if(clan < 2)
       return clan;
    return fibonacci(clan - 1) + fibonacci(clan - 2);
}
