#include "tree.h"
#include <stdio.h>

int main() {

  node *t3;
  node *t5;
  node *t12;
  node *t1;
  node *t4;
  node *t2;
  node *t7;
  
  t7 = create_node(7, NULL, NULL);
  t12 = create_node(12, NULL, NULL);
  t4 = create_node(4, NULL, NULL);
  t1 = create_node(1, t4, NULL);
  t2 = create_node(2, t7, NULL);
  t5 = create_node(5, t12, t1);
  t3 = create_node(3, t2, t5);

  display_prefix(t3);
  printf("\n");
  display_infix(t3);
  printf("\n");
  display_suffix(t3);
  printf("\n");

  return 0;
}
