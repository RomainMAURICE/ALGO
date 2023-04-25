#ifndef __LIST_H__
#define __LIST_H__

/*typedef struct _link {
    char *word;
    int occurrences;
    struct _link *next;
} link;*/

typedef struct _olink {
    int pos;
    struct _olink *next;
} olink;

typedef struct _link {
    char *word;
    olink *occurrences;  /*liste des occurrences */
    struct _link *next;
} link;

typedef struct _table {
link **buckets;
int M; /* nombre de seaux */
int size; /* nombre de mots dans la table */
} table;


void free_list(link *lst);

link *find_list(link *lst, char word[]);
link *insert_first_list(link *lst, char word[], int pos);

void display_list(link *lst);

void add_occurrence(link *lnk, int pos);

table *create_table(int M);

link *find(table *tab, char *elt);

void insert(table *tab, char *elt, int pos);

#endif
