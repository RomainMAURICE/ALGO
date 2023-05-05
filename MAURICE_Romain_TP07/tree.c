#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

node *create_node(int data, node *left, node *right) {
  node *n = (node *)malloc(sizeof(node));
  assert(n != NULL);
  n->data = data;
  n->left = left;
  n->right = right;
  return n;
}

void display_prefix(node *t){
  if(t==NULL){
    return;
  }
  printf("%d ", t->data);
  display_prefix(t->left);
  display_prefix(t->right);
}

void display_infix(node *t){
  if(t==NULL){
    return;
  }
  display_prefix(t->left);
  printf("%d ", t->data);
  display_prefix(t->right);
}

void display_suffix(node *t){
  if(t==NULL){
    return;
  }
  display_prefix(t->left);
  display_prefix(t->right);
  printf("%d ", t->data);

}