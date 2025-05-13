#include "bst.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 0;

    scanf("%d", &n);
    srand(time(NULL));
    BST* bst = bst_construct();
    for(int i = 0; i < n; i++) {
        int r  = rand();
        printf("%d\n", r);

        bst_insert(bst, r, r);
    }

    bst_destroy(bst);


    return 0;
}