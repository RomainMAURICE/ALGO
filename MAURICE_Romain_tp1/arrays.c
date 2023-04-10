#include "arrays.h"
#include <stdlib.h>

int *create_array(int max_size) {
    int *ptr = (int*)malloc(max_size*sizeof(int));
    return ptr;
}

void free_array(int t[]) {
    free(t);
}

/*
 * Write this function!
 */
void insert_unsorted(int t[], int *size, int elt) {
    t[*size]=elt;
    *size = *size+1;
}

/*
 * Write this function!
 */
int find_unsorted(int t[], int size, int elt) {
    int i;
    for (i=0; i<size; i++){
        if (elt==t[i])
        {
            return 1;
        }
    }
    return 0;

}

/*
 * Write this function!
 */
void insert_sorted(int t[], int *size, int elt) {
    /* int i;
    * int j;
    * for (i=0; t[i]!=elt; i++){}
    * *size = *size+1;
    * for (j=i; j<*size; j++){
    *     t[*size]=t[*size-1];
    * }
    * t[i]=elt;
    */

    int j=(*size)-1;
    while (j>=0 && t[j]>elt)
    {
        t[j+1]=t[j];
        j--;
    }
    t[j+1]=elt;
    (*size)++;
    
}

/*
 * Write this function!
 */
int find_sorted(int t[], int size, int elt) {
    int lo = 0, hi = size - 1;
    while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (t[mid] == elt)
        return 1;
    else if (t[mid] < elt)
        lo = mid + 1;
    else
        hi = mid - 1;
    }
    return 0;
}
