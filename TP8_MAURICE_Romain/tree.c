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
  display_infix(t->left);
  printf("%d ", t->data);
  display_infix(t->right);
}

void display_suffix(node *t){
  if(t==NULL){
    return;
  }
  display_suffix(t->left);
  display_suffix(t->right);
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
      else{
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


node *find_bst(node *t, int elt){
  if(t == NULL){
    return NULL;
  }
  if(t->data == elt){
    return t;
  }

  if(t->data < elt){
    return find_bst(t->right, elt);
  }
  else{
    return find_bst(t->left, elt);
  }
}

node *insert_bst(node *t, int elt){
  if(t == NULL){
    return create_node(elt, NULL, NULL);
  }

  if(elt > t->data){
    t->right = insert_bst(t->right, elt);
  }
  else if(elt < t->data){
    t->left = insert_bst(t->left, elt);
  }

  return t;

}

node *random_tree(int max){

  node* tree = NULL;
  int i;
  for(i=0; i<max; i++){
    int random = (rand()%max)*2;
    tree = insert_bst(tree, random);
  }

  return tree;
}

node *random_tree_ordered(int max){

  node* tree = NULL;
  int i;
  for(i=0; i<max; i++){
    tree = insert_bst(tree, i);
  }

  return tree;
}

node *extract_min_bst(node *t, node **min){
  if(t==NULL){
    return NULL;
  }
  if(t->left==NULL){
    *min = t;
  }

  t->left = extract_min_bst(t->left, min);
  
  return t;
}
