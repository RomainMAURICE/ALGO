#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "array.h"
#include "sort.h"

#define MAX_VALUE 10000
#define MAX_SIZE 10


int main(int argc, char *argv[]) {

	srand(time(NULL));

	int size = MAX_SIZE;
	int max_value = MAX_VALUE;

	/* tableau de travail */
	int* tab = NULL;
	int* tab2 = NULL;
	int* tab3 = NULL;
	//int* tab4 = NULL;

	/* allocation et initialisation du tableau avec des valeurs aléatoires */
	tab = create_array(size);
	fill_random_array(tab, size, max_value);

	tab2=tab;
	tab3=tab2;
	//tab4=tab3;

	print_array(tab, size);
	print_array(tab2, size);
	print_array(tab3, size);
	//print_array(tab4, size);

	/* affiche le tableau */

	qsort(tab, size, sizeof(int), compare);
	print_array(tab, size);

	selection_sort(tab2, size);
	print_array(tab2, size);

	insertion_sort(tab3, size);
	print_array(tab3, size);

	//quicksort_w(tab4, size);
	//print_array(tab4, size);

	/* libération du tableau */
	free(tab);
	tab = NULL;

	return EXIT_SUCCESS;
}
