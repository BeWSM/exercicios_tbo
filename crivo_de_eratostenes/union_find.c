#include "union_find.h"
#include <stdlib.h>
#include <stdio.h>

UF* UF_init(int N){
    UF* uf = malloc(sizeof(UF));
    uf->primes = vector_construct();
    for(int i = 0; i <= N; i++){
        vector_push_back(uf->primes, (data_type)i);
    }
    return uf;
}

int UF_find(int p, UF* uf){
    return vector_get(uf->primes, p);
}

bool UF_connected(int p, int q, UF* uf){
    return UF_find(p, uf) == UF_find(q, uf);
}

void UF_union(int p, int q, UF* uf){
    if(UF_connected(p, q, uf)){
        return;
    }
    vector_set(uf->primes, p, (data_type)q);

}

void UF_destroy(UF* uf){
    vector_destroy(uf->primes);
    free(uf);
}