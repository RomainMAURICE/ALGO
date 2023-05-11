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

node *scan_tree(){
    int x;
    scanf("%d", &x);
    if (x == 0) {
        return NULL;
    }
    node *n = create_node(x, NULL, NULL);
    n->left = scan_tree();
    n->right = scan_tree();
    return n;
}

int count_nodes(node *t){
  if (t == NULL) {
      return 0;
  }

  return 1 + count_nodes(t->left) + count_nodes(t->right);
  
}

int count_leaves(node *t){
  if (t == NULL) {
    return 0;
  }  
  
  if (t->left == NULL && t->right == NULL) {
    return 1;
  }else {
    return count_leaves(t->left) + count_leaves(t->right);
  }
}

int count_only_children(node *t){
  if (t == NULL) {
    return 0;
  }  
  
  if ((t->left == NULL && t->right != NULL) || (t->left != NULL && t->right == NULL)) {
    return 1;
  }else {
    return count_only_children(t->left) + count_only_children(t->right);
  }
}

int height(node *t){
  if (t == NULL) {
      return 0;
  } else {
      int left_height = height(t->left);
      int right_height = height(t->right);

      if (left_height > right_height) {
          return left_height + 1;
      } 
      if (left_height == right_height || right_height > left_height) {
          return right_height + 1;
      }
  }
}

void free_tree(node *t){
  if (t == NULL) {
    return;
  }
  free_tree(t->left);
  free_tree(t->right);
  free(t);
}