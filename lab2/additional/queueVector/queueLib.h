#ifndef TMP_QUEUELIB_H
#define TMP_QUEUELIB_H

typedef struct Queue {
    int *q;
} Queue;

typedef struct Gen {
    int max;
    int cur;
    int tail;
    int head;
} Gen;

Queue *pushQ(Queue *queue, Gen **gen);
Queue *popQ(Queue *queue, Gen **gen);
void freeQ(Queue *queue, Gen *gen);
void printQ(Queue *queue, Gen *gen);

Gen *genInit(Queue **queue);

#endif
