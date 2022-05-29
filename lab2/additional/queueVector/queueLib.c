#include "general.h"

Gen *genInit(Queue **queue) {
    Gen *qGen = malloc (sizeof (Gen));
    printf("Max size of the queue-->");
    qGen->max = get_int(1);
    *queue = malloc(sizeof (Queue));
    (*queue)->q = malloc(sizeof (int) * qGen->max);
    qGen->cur = 0;
    qGen->head = 0;
    qGen->tail = 0;
    return qGen;
}

Queue *pushQ(Queue *queue, Gen **gen) {
    if ((*gen)->cur == (*gen)->max) {
        printf("Overflow!\n");
        return queue;
    }
    printf("Print item-->");
    queue->q[(*gen)->tail] = get_int(1);
    (*gen)->tail = ((*gen)->tail + 1) % (*gen)->max;
    (*gen)->cur ++;
    return queue;
}

Queue *popQ(Queue *queue, Gen **gen) {
    if ((*gen)->cur == 0) {
        return queue;
    }
    printf("%d\n", queue->q[(*gen)->head]);
    (*gen)->head ++;
    (*gen)->cur --;
    return queue;
}

void freeQ(Queue *queue, Gen *gen) {
    free(queue->q);
    free(queue);
    free(gen);
}

void printQ(Queue *queue, Gen *gen) {
    for (int i = 0; i < gen->cur; i++) {
        printf("%d ", queue->q[(gen->head + i) % gen->max]);
    }
    printf("\n");
}