#include <stdio.h>
#include "event.h"
#include "customer.h"
#include "queue.h"
#include "prioqueue.h"

#define N_VENDORS 3

int current_time = 0;
int closure_time = 500;

prioqueue*  event_queue;
queue*      customer_queue;
customer*   vendor[N_VENDORS];

void add_customer(customer *c){
    int i;
    for(i=0;i<N_VENDORS;i++){
        if(vendor[i]==NULL){
            vendor[i]=c;
            insert_pq(event_queue, create_departure(current_time+150, c));
            return;
        }
    }
    enqueue_q(customer_queue, c);
}


void process_arrival(event *e) {
    e->c = create_customer(e->etime);
    add_customer(e->c);
    insert_pq(event_queue, create_arrival(e->etime+60));
}

void process_departure(event *e) {
    //remove_min_pq(event_queue);
    create_departure(e->etime, e->c);
}


void current_state(event *e){
    if(e->etime<10)
        printf(" ");
    if(e->etime<100)
        printf(" ");

    printf("%d ", e->etime);
    printf("| ");

    int i;
    for(i=0;i<N_VENDORS;i++){
        if(vendor[i]==NULL){
            printf("_ ");
        }
        else{
            printf("X ");
        }
    }
    printf("| ");
    
    for(i=0; i<size_q(customer_queue); i++){
        printf("X ");
    }

    printf("\n");
}

void remove_customer(customer *c){
    
}

int main() {

    event_queue = create_pq();
    customer_queue = create_q();
    int i;
    for(i=0;i<N_VENDORS;i++){
        vendor[i]=NULL;
    }

    event *e = create_arrival(0);
    insert_pq(event_queue, e);

    /*event *e2 = create_arrival(170);
        insert_pq(event_queue, e2);*/

    while(size_pq(event_queue)>0 && current_time < closure_time){
        event *e1 = remove_min_pq(event_queue);
        current_time = e1->etime;

        if(e1->type==EVENT_ARRIVAL){
            process_arrival(e1);
        }
        else{
            process_departure(e1);
        }
        current_state(e1);
        free_event(e1);
    }

    return 0;
}
