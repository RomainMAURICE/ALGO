#include "avl.h"
#include "visualtree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    node *t = create_node(10, NULL, NULL);
    write_tree(t);
    free_tree(t);

    return 0;
}
