typedef struct{
    int *tree;
    int size;
    int max;
} heap;

heap *create_heap(int max);

void free_heap(heap *h);

void insert_heap(heap *h, int elt);

int is_heap(heap *h);