#ifndef SORT_H
#define SORT_H

int less(int a, int b);

void swap(int *a, int *b);

void selection_sort(int t[], int size);

void insertion_sort(int t[], int size);

void quick_sort(int t[], int lo, int hi);

int compare(const void *a,const void *b);

void Function_qsort(int values[]);


#endif /* SORT_H */