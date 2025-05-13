#ifndef _BINARY_TREE_SEARCH_H_
#define _BINARY_TREE_SEARCH_H_
#include "node.h"

typedef struct{
    Node* root;
}BST;

BST* bst_construct();
void bst_insert(BST* bst, int key, int value);
void bst_destroy(BST* bst);


#endif

