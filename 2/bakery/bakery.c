#include <stdio.h>
#include "event.h"
#include "customer.h"
#include "queue.h"
#include "prioqueue.h"

#define N_VENDORS 3
#define current_time 0

prioqueue*  event_queue;
queue*      customer_queue;
customer*   vendor[N_VENDORS];

void process_arrival(event *e) {
    insert_pq(event_queue ,e);
}

void process_departure(event *e) {
    remove_min_pq(event_queue);
}

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

void process_arrival(event *e){
    create_customer(e->etime);
    add_customer(e);
    insert_pq(event_queue, create_arrival(e->etime+60));
}

int main() {

    event_queue = create_pq();
    customer_queue = create_q();

    event *test;
    test->etime=60;
    test->type=EVENT_ARRIVAL;

    insert_pq(event_queue, test);

    int i;
    for(i = 0; i < N_VENDORS; i++){
        vendor[i] = NULL;
    }

    /*enqueue_q(customer_queue, create_customer(42));
    printf("Le client est arrivé à l'heure suivante: %d\n", dequeue_q(customer_queue)->atime);*/

    while(size_pq(event_queue)>0 /*&& current_time < closure_time*/){
        event *e1 = remove_min_pq(event_queue);
        //current_time = e->time;
        printf("%d", e1->etime);
        if(e1->type==EVENT_ARRIVAL){
            process_arrival(e1);
        }
        else{
            process_departure(e1);
        }
        free_event(e1);
        //print_state();
    }

    return 0;
}
