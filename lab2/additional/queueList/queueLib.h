#ifndef TMP_QUEUELIB_H
#define TMP_QUEUELIB_H

typedef struct Queue {
    int item;
    struct Queue *next;
} Queue;

typedef struct Gen {
    int max;
    int cur;
    Queue *tail;
} Gen;

Queue *pushQ(Queue *queue, Gen **gen);
Queue *popQ(Queue *queue, Gen **gen);
void freeQ(Queue *queue, Gen *gen);
void printQ(Queue *queue);

Gen *genInit();

#endif
