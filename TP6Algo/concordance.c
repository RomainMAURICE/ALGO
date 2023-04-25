#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define MAX_WORD_LENGTH 80

link *read_text(FILE *infile) {
    link *lst = NULL;
    char *word = (char *)malloc(MAX_WORD_LENGTH*sizeof(char));
    int position=0;
    while (fscanf(infile, "%s ", word) != -1) {

        position++;
        if(find_list(lst, word)!=NULL){
            add_occurrence(find_list(lst, word), position);
        }else{
            lst = insert_first_list(lst, word, position);
        }

    }
    free(word);
    return lst;
}

/*link *read_text(FILE *infile) {
    table *tab = create_table(10);
    link *lst = NULL;
    char *word = (char *)malloc(MAX_WORD_LENGTH*sizeof(char));
    int position=0;
    while (fscanf(infile, "%s ", word) != -1) {

        position++;
        if (find(tab, word) != NULL) {
            add_occurrence(find(tab, word), position);
        } else {
            lst = insert_first_list(find(tab, word), word, position);
        }

    }
    free(word);
    return lst;
}*/

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
    int total = 0;

    link *ptr;
    olink *ptr2;
    for (ptr = lst; ptr != NULL; ptr = ptr->next) {
        words++;    
        
        ptr2=ptr->occurrences;
        while(ptr2){
            total+=1;
            ptr2 = ptr2->next;
        } 
    }
    printf("total number of words = %d\n", total);
    printf("total number of distinct words = %d\n", words);

    free_list(lst);

    return 0;
}
