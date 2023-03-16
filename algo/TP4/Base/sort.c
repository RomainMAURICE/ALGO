#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int nb_less = 0;
int nb_swap	= 0;

int less(int a, int b) {
	nb_less++;
	return a < b;
}

void swap(int *a, int *b) {
	nb_swap++;
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selection_sort(int t[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		int min = i;
		int j;
		for (j = i+1; j < size; j++)
		if (less(t[j], t[min]))
			min = j;
		swap(&t[i], &t[min]);
	}
}

void insertion_sort(int t[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		int j = i;
 		while (j > 0 && less(t[j], t[j-1])) {
 			swap(&t[j-1], &t[j]);
 			j--;
 		}
	}
}

int partition(int t[], int lo, int hi) {
	int i = lo+1;
	int j = hi;
	while (1) {

	while (less(t[i], t[lo]) && i < hi)
	i++;
	while (less(t[lo], t[j]) && j > lo)
	j--;
	if (i >= j) break;
	swap(&t[i], &t[j]);
	i++;
	j--;
	}
	swap(&t[lo], &t[j]);
	return j;
}

void quicksort(int t[], int lo, int hi) {
	if (lo >= hi)
	return;
	int pivot = partition(t, lo, hi);
	quicksort(t, lo, pivot-1);
	quicksort(t, pivot+1, hi);
}

void quicksort_w(int t[], int size){
	quicksort(t, 0, size);
}


int compare(const void *a,const void *b)
{
  int aint = *(int*)a;
  int bint = *(int*)b;
  if (aint == bint)
    return 0;
  else
    if (aint < bint)
      return -1;
    else
      return 1;
}

void Function_qsort(int values[]){
	int i;
  	for (i=0; i < 10; i++)
    	printf("%d ", values[i]);
  	printf("\n");
  
  	qsort (values, 10, sizeof(int), compare);
  
  	for (i=0; i < 10; i++)
    	printf ("%d ", values[i]);
  	printf("\n");
}