#ifndef _NODE_H_
#define _NODE_H_

typedef struct Node Node;

Node* node_construct(int key, int value, Node* left, Node* right);
int node_get_key(Node* n);
Node* node_get_left(Node* n);
Node* node_get_right(Node* n);
void node_set_left(Node* destiny, Node* left);
void node_set_right(Node* destiny, Node* right);
void node_destroy(Node* node);



#endif