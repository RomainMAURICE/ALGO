#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

heap *create_heap(int max){
    heap *h = malloc(sizeof(heap));
    h->tree = malloc(max*sizeof(int));
    h->size = 0;
    h->max = max;
    return h;
}

void free_heap(heap *h){
    free(h->tree);
    free(h);
}

void insert_heap(heap *h, int elt) {
    int child = h->size - 1;
    while (child > 0 && h->tree[child] > h->tree[(child-1) / 2]) {
        int parent = (child-1)/2;
        int tmp = h->tree[child];
        h->tree[child] = h->tree[parent];
        h->tree[parent] = tmp;
        
        child = parent;
    }
}

int is_heap(heap *h){
    int i;
    for(int i = 1; i<h->size; i++){
        if(h->tree[i] > h->tree[(i-1)/2]){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    heap * h = create_heap(20);
    insert_heap(h, 2);
    insert_heap(h, 5);
    insert_heap(h, 10);
    insert_heap(h, 14);

    printf("%d ", is_heap(h));

    return 0;
}
