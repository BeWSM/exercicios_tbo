#include "node.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    int value;
    Node* left;
    Node* right; 
};

Node* node_construct(int key, int value, Node* left, Node* right){
    Node* node = calloc(1, sizeof(Node));
    node->key = key;
    node->value = value;
    node->left = left;
    node->right = right;

    return node;
}

int node_get_key(Node* n){
    return n->key;
}
Node* node_get_left(Node* n){
    return n->left;
}
Node* node_get_right(Node* n){
    return n->right;
}
void node_set_left(Node* destiny, Node* left){
    destiny->left = left;
}
void node_set_right(Node* destiny, Node* right){
    destiny->right = right;
}

void node_destroy(Node* node){
    if( node != NULL ){
        free(node);
    }
}