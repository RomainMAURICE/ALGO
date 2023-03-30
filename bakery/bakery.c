#include <stdio.h>
#include "event.h"
#include "customer.h"
#include "queue.h"
#include "prioqueue.h"

#define N_VENDORS 3

prioqueue*  event_queue;
queue*      customer_queue;
customer*   vendor[N_VENDORS];

void process_arrival(event *e) {
    insert_pq(event_queue ,e);
}

void process_departure(event *e) {
    remove_min_pq(event_queue);
}

int main() {

    event_queue = create_pq();
    customer_queue = create_q();
    int i;
    for(i = 0; i < N_VENDORS; i++){
        vendor[i] = NULL;
    }

    enqueue_q(customer_queue, create_customer(42));
    printf("Le bougre est arrivé à l'heure suivante: %d\n", dequeue_q(customer_queue)->atime);

    while (size_q(enqueue_q)<1)
    {
        /* code */
    }

    return 0;
}