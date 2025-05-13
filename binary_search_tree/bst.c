#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

BST* bst_construct(){
    BST* bst = calloc(1, sizeof(BST));
    return bst;
}
void bst_insert(BST* bst, int key, int value){
    if(bst->root == NULL){
        bst->root = node_construct(key, value, NULL, NULL);
        return;
    }
    Node* node = bst->root;
    while(node != NULL){
        if(key > node_get_key(node)) {
            if (node_get_right(node) == NULL) {
                Node* n = node_construct(key, value, NULL, NULL);
                node_set_right(node, n);
                return;
            } else {
                node = node_get_right(node);
            }
        }else if(key < node_get_key(node)){
            if (node_get_left(node) == NULL) {
                Node* n = node_construct(key, value, NULL, NULL);
                node_set_left(node, n);
                return;
            } else {
                node = node_get_left(node);
            }
        
        }else{
            return;
        }

    }
}
void node_destroy_recursive(BST* bst, Node* n){
    if (n == NULL)
        return;
    
    node_destroy_recursive(bst, node_get_left(n));
    node_destroy_recursive(bst, node_get_right(n));

    node_destroy(n);
}
void bst_destroy(BST* bst){
    if(bst != NULL){
        node_destroy_recursive(bst, bst->root);
        free(bst);
    }

}