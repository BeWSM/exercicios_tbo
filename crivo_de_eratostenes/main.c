#include <stdio.h>
#include <stdlib.h>
#include "union_find.h"
int main(){
    int n = 0;

    scanf("%d",&n);
    UF* uf = UF_init(n);
    Vector* v = vector_construct();
    for(int i = 2; i <= n; i++){
        for(int j = i + 1; j < n; j++){
            if(uf->primes->data[j] % i == 0){
                UF_union(j, i, uf);
                
            }
        }

    }

    for(int i = 2; i < n; i++){
        if(uf->primes->data[i] == i){
            printf("%d ", uf->primes->data[i]);
        }
       
    }

    UF_destroy(uf);


    return 0;
}