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
            if(uf->parent->data[j] % (data_type)i == 0){
                UF_union(i, uf->parent->data[j], uf);
                
            }
        }

    }

    for(int i = 2; i < n; i++){
        if(uf->parent->data[i] == i){
            printf("%d ", uf->parent->data[i]);
        }
       
    }

    UF_destroy(uf);


    return 0;
}