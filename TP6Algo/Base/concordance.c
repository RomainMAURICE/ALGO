#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define MAX_WORD_LENGTH 80

link *read_text(FILE *infile) {
    link *lst = NULL;
    char *word = (char *)malloc(MAX_WORD_LENGTH*sizeof(char));
    while (fscanf(infile, "%s ", word) != -1) {

        if(find_list(lst, word)!=NULL){
            find_list(lst, word)->occurrences++;
        }else{
            lst = insert_first_list(lst, word);
        }

    }
    free(word);
    return lst;
}

int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "Usage: concordance <in_file>\n");
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL) {
        fprintf(stderr, "Error opening file for reading: %s\n", argv[1]);
        return 1;
    }

    link *lst = read_text(fin);
    fclose(fin);

    display_list(lst);
    
    int words = 0;
    int total = nb_total_mot(fin);

    link *ptr;
    for (ptr = lst; ptr != NULL; ptr = ptr->next) {
        words++;
    }

    printf("total number of words = %d\n", total);
    printf("total number of distinct words = %d\n", words);

    free_list(lst);

    return 0;
}
