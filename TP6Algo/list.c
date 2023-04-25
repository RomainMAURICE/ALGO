#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * Create a link representing 1 occurence of the string 'word'.
 * The string is copied and must be freed when the link is freed.
 */
link *create_link(char word[], link *next, int pos) {
    olink *firstTime = malloc(sizeof(olink));
    firstTime->next = NULL;
    firstTime->pos = pos;

    link *lnk = malloc(sizeof(link));
    lnk->word = malloc(strlen(word)+1);
    strcpy(lnk->word, word);
    lnk->occurrences = firstTime;
    lnk->next = next;
    return lnk;
}

void free_olink(olink *lnk) {
    while(lnk){
        olink *tmp = lnk;
        lnk = lnk->next;
        free(tmp);
    }
}
void free_link(link *lnk) {
    free(lnk->word);
    free_olink(lnk->occurrences);
    free(lnk);
}

void free_list(link *lst) {
    while (lst) {
        link *tmp = lst;
        lst = lst->next;
        free_link(tmp);
    }
}

void display_list(link *lst) {
    while (lst) {
        printf("%s : ", lst->word);
        olink *occ = lst->occurrences;
        while (occ) {
            printf("%d ", occ->pos);
            occ = occ->next;
        }
        printf("\n");
        lst = lst->next;
    }
}

int equal(char* w1, char* w2) {
    return strcmp(w1, w2) == 0;
}

link *find_list(link* lst, char word[]) {
    link *ptr = lst;
    while (ptr != NULL && !equal(ptr->word, word))
        ptr = ptr->next;
    return ptr;
}

link *insert_first_list(link *lst, char word[], int pos) {
    return create_link(word, lst, pos);
}

void add_occurrence(link *lnk, int pos){
    olink *link = (olink*) malloc(sizeof(olink));
    link->pos = pos;
    link->next = lnk->occurrences;
    lnk->occurrences = link;
}





table *create_table(int M){
    table *table = malloc(sizeof(table));
    table->buckets = NULL;
    table->M = M;
    table->size = 0;
    return table;
}

unsigned hash(char *str) {
    unsigned h = 0;
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        h = 31*h + str[i];
    }
    return h;
}

link *find(table *tab, char *elt){
    int index = hash(elt)%tab->M;
    return find_list(tab->buckets[index], elt);
}

/*void insert(table *tab, char *elt, int pos){
    link *lnk = find(tab, elt);
    if (lnk != NULL) {
        add_occurrence(lnk, pos);
    } else {
        create_link(elt, lnk, pos);
    }
}*/
