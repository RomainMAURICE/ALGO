/*#include <stdlib.h>
#include "queue.h"

typedef struct _link {
    customer*       c;
    struct _link*   next;
} link;

struct _queue {
    link*   first;
    link*   last;
    int     size;
};

queue *create_q() {
    queue *q = (queue*)malloc(sizeof(queue));
    q->first = NULL;
    q->last = NULL;
    q->size = 0;
    return q;
}

void free_q(queue *q) {
    free(q);
}

int size_q(queue *q) {
    return q->size;
}

void enqueue_q(queue *q, customer *c){
    link *l = (link*)malloc(sizeof(link));
    l->c=c;
    l->next=NULL;

    if(q->first==NULL){
        q->first = l;
        q->last = l;        
    }
    else{
        q->last->next = l;  //inséré après le dernier lien de la file d'attente
        q->last = l;        //puis devient le nouveau dernier lien de la file d'attente.
    }

    q->size++;
}

void display_q(queue *q){

}

int main(int argc, char const *argv[])
{
    return 0;
}
*/




#include <stdlib.h>
#include <assert.h>
#include "queue.h"
#include "customer.h"

#define MAX_QUEUE_SIZE 100

struct _queue {
    customer* tab[MAX_QUEUE_SIZE];
    int       first;
    int       size;
};

queue *create_q() {
    queue *q = (queue*)malloc(sizeof(queue));
    q->first = 0;
    q->size = 0;
    return q;
}

void free_q(queue *q) {
    while (q->size != 0) {
        customer* c = dequeue_q(q);
        free_customer(c);
    }
    free(q);
}

int size_q(queue *q) {
    return q->size;
}

void enqueue_q(queue *q, customer *c) {
    assert(q->size < MAX_QUEUE_SIZE);
    q->tab[(q->first+q->size) % MAX_QUEUE_SIZE] = c;
    q->size++;
}

customer *dequeue_q(queue *q) {
    assert(q->size > 0);
    customer *c = q->tab[q->first];
    q->first = (q->first+1) % MAX_QUEUE_SIZE;
    q->size--;
    return c;
}
