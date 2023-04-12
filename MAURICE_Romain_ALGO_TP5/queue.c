#include <stdlib.h>
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
    while(size_q(q)>1){
        free(dequeue_q(q));
    }
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
        q->last->next = l;
        q->last = l;
    }

    q->size++;
}

customer *dequeue_q(queue *q){
    customer *c = q->first->c;
    link *l = q->first;
    q->first = q->first->next;
    free(l);
    q->size--;
    return c;
}

void display_q(queue *q){

}