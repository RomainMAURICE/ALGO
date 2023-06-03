#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

node *create_node(int elt, node *left, node *right) {
    node *n = (node *)malloc(sizeof(node));
    assert(n != NULL);
    n->data = elt;
    n->height = 0;
    n->left = left;
    n->right = right;
    return n;
}

void free_tree(node *t) {
    if (t != NULL) {
        free_tree(t->left);
        free_tree(t->right);
        free(t);
    }
}

/* SEARCH */

node *find_avl(node *t, int elt) {
    node *ptr = t;
    while (ptr != NULL && ptr->data != elt) {
        if (ptr->data > elt)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return ptr;
}

void update_height(node *t){
    if(t->left==NULL && t->right==NULL)
        return 0;

    if(t->left->height < t->right->height)
        return t->right->height + 1;

    if(t->left->height > t->right->height)
        return t->left->height + 1;
}

node *rotate_right(node *y) {
    node *x = y->left;
    y->left = x->right;
    x->right = y;
    /* return the new root */
    update_height(y);
    return x;
}

node *rotate_left(node *y){
    node *x = y->right;
    y->right = x->left;
    x->left = y;
    /* return the new root */
    update_height(y);
    return x;
}

node *rotate_left_right(node *t){
    if(t->left == NULL && t->right == NULL)
        return NULL;

    t->left=(rotate_left(t->left));
    return rotate_right(t->right);
}

node *rotate_right_left(node *t){
    if(t->left == NULL && t->right == NULL)
        return NULL;

    t->right=(rotate_right(t->right));
    return rotate_left(t->left);
}

int compute_balance(node *t){
    
}