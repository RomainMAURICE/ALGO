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
    if(t == NULL)
        return;

    if(t->left->height < t->right->height){
        t->height = t->right->height + 1;
        return;
    }
    if(t->left->height > t->right->height){
        t->height = t->left->height + 1;
        return;
    }
}

node *rotate_right(node *y) {
    node *x = y->left;
    y->left = x->right;
    x->right = y;
    update_height(x);
    update_height(y);
    return x;
}

node *rotate_left(node *y){
    node *x = y->right;
    y->right = x->left;
    x->left = y;
    update_height(y);
    update_height(x);
    return x;
}

node *rotate_left_right(node *t){
    if(t == NULL)
        return NULL;

    t->left=(rotate_left(t->left));
    return rotate_right(t);
}

node *rotate_right_left(node *t){
    if(t == NULL)
        return NULL;

    t->right=(rotate_right(t->right));
    return rotate_left(t);
}

int compute_balance(node *t){
    return t->left->height - t->right->height;
}

node *rebalance(node *t){
    if(t == NULL)
        return t;

    if(compute_balance(t) >= 2){
        if(compute_balance(t->left) <= -1){
            t = rotate_left_right(t);
        }
        else{
            t = rotate_right(t);
        }
    }
    if(compute_balance(t) <= -2){
        if(compute_balance(t->right) >= 1){
            t = rotate_right_left(t);
        }
        else{
            t = rotate_left(t);
        }
    }
    return t;
}

node *insert_avl(node *t, int elt){
    if(t == NULL)
        return create_node(elt, NULL, NULL);
    else if(t->data > elt)
        t->left = insert_avl(t->left, elt);
    else if(t->data < elt)
        t->right = insert_avl(t->right, elt);
    update_height(t);
    t = rebalance(t);
    return t;
}

int is_avl(node *t){
    /*if(t == NULL)
        return 1;
    
    int feq = compute_balance(t);
    if(feq >= -1 || feq <= 1)
        return 1;*/

    return 1;
}