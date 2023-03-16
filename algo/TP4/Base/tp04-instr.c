#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "array.h"
#include "sort.h"

#define MAX_VALUE 10000

extern int nb_less;
extern int nb_swap;

int main(int argc, char *argv[]) {


	srand(time(NULL));

	int size = 0;
	int max_value = MAX_VALUE;

    while (size <10000){

    int nb_less2;
    int nb_swap2;
    int nb_less3;
    int nb_swap3;

	/* tableau de travail */
	int* tab = NULL;
   	int* tab2 = NULL;
    int* tab3 = NULL;

	/* allocation et initialisation du tableau avec des valeurs aléatoires */
	tab = create_array(size);
	fill_random_array(tab, size, max_value);

    tab2=tab;
    tab3=tab;

    nb_less = 0;
    nb_swap = 0;
    insertion_sort(tab, size);
    printf("%d comparaisons\n", nb_less);
    printf("%d échanges\n", nb_swap);

    nb_less2 = nb_less;
    nb_swap2 = nb_swap;

    nb_less = 0;
    nb_swap = 0;
    selection_sort(tab2, size);
    printf("%d comparaisons\n", nb_less);
    printf("%d échanges\n", nb_swap);

    nb_less3 = nb_less;
    nb_swap3 = nb_swap;

    nb_less = 0;
    nb_swap = 0;
    quicksort_w(tab3, size);
    printf("%d comparaisons\n", nb_less);
    printf("%d échanges\n", nb_swap); 

    FILE *f = fopen("sort.dat", "a");
    fprintf(f, "%d %d %d %d\n", size, nb_swap3, nb_swap2, nb_swap);
    fclose(f);

	/* libération du tableau */
	free(tab);
	tab = NULL;

    size = size + 100;

    }

	return EXIT_SUCCESS;




}