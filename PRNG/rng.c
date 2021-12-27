#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


uint64_t init_rand_digits(int n){
    uint64_t value = 0;
    srand ( time(NULL) );

    while(n > 1){
        int aux  = rand() % 2;
        value = value | aux;
        value = value << 1;
        n = n - 1;
    }
    return value;
}

int main(){
    int i = 0;
    
    uint64_t x = 0;
    uint64_t w = 0;
    //uint64_t s = init_rand_digits(60);
    uint64_t s = 0xb5ad4eceda1ce2a9;
    
    while(i != 1){
        x *= x; 
        x += (w += s); 
        x = (x>>32) | (x<<32);

        printf( "u64 = %lu\n", x );
        
        scanf("%i", &i);
    }

}