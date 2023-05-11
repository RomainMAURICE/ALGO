#include "tree.h"
#include "visualtree.h"
#include <stdio.h>

int main() {

  node *t = scan_tree();
  //write_tree(t);
  printf("%d\n", count_nodes(t));
  printf("%d\n", count_leaves(t));
  printf("%d\n", count_only_children(t));
  printf("%d\n", height(t));
  free_tree(t);




  return 0;
}