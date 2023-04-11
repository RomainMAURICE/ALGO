#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "event.h"
#include "customer.h"
#include "queue.h"
#include "prioqueue.h"

#define N_VENDORS 5
#define ARRIVAL_RATE (1.0/60)
#define MEAN_SERVICE_TIME 150

int current_time = 0;
int closure_time = 35000; //en secondes

prioqueue*  event_queue;
queue*      customer_queue;
customer*   vendor[N_VENDORS];


double normal_delay(double mean) {
    return -mean*log(1-((double)rand()/RAND_MAX));
}

void add_customer(customer *c){
    int i;
    for(i=0;i<N_VENDORS;i++){
        if(vendor[i]==NULL){
            vendor[i]=c;
            insert_pq(event_queue, create_departure(current_time+normal_delay(MEAN_SERVICE_TIME), c));
            return;
        }
    }
    enqueue_q(customer_queue, c);
}

void remove_customer(customer *c){
    int i;
    for(i=0;i<N_VENDORS;i++){
        if(vendor[i]==c){
            vendor[i] = NULL;
            free_customer(c);

            if(size_q(customer_queue)>0){
                customer *c2 = dequeue_q(customer_queue);
                vendor[i] = c2;     

                event *e = create_departure(current_time+normal_delay(MEAN_SERVICE_TIME), c2);
                insert_pq(event_queue, e);
            }
            return;
        }
    }
}

void process_arrival(event *e) {
    e->c = create_customer(e->etime);
    add_customer(e->c);
    insert_pq(event_queue, create_arrival(e->etime+normal_delay(1.0/ARRIVAL_RATE)));
}

void process_departure(event *e) {
    //remove_min_pq(event_queue);
    remove_customer(e->c);
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

int main() {

    event_queue = create_pq();
    customer_queue = create_q();
    int i;
    for(i=0;i<N_VENDORS;i++){
        vendor[i]=NULL;
    }

    event *e = create_arrival(0);
    insert_pq(event_queue, e);

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
