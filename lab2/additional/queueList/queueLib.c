#include "general.h"

Gen *genInit() {
    Gen *qGen = malloc (sizeof (Gen));
    printf("Max size of the queue-->");
    qGen->max = get_int(1);
    qGen->cur = 0;
    return qGen;
}

Queue *pushQ(Queue *queue, Gen **gen) {
    if ((*gen)->cur == (*gen)->max){
        printf("Overflow!\n");
        return queue;
    }
    printf("Item-->");
    int item = get_int(1);
    if ((*gen)->cur == 0) {
        queue = malloc(sizeof (Queue));
        queue->item = item;
        queue->next = NULL;
        (*gen)->tail = queue;
    }
    else {
        (*gen)->tail->next = malloc(sizeof (Queue));
        (*gen)->tail->next->item = item;
        (*gen)->tail = (*gen)->tail->next;
        (*gen)->tail->next = NULL;
    }
    (*gen)->cur ++;
    return queue;
}

Queue *popQ(Queue *queue, Gen **gen) {
    if ((*gen)->cur == 0) {
        printf("No elements!\n");
        return queue;
    }
    printf("Your item --> %d\n", queue->item);
    Queue *tmp = queue;
    queue = queue->next;
    (*gen)->cur --;
    free(tmp);
    return queue;
}

void freeQ(Queue *queue, Gen *gen) {
    while (queue) {
        Queue *tmp = queue;
        queue = queue->next;
        free(tmp);
    }
    free(gen);
}

void printQ(Queue *queue) {
    Queue *tmp = queue;
    printf("Your queue:\n");
    while (tmp) {
        printf("%d ",tmp->item);
        tmp = tmp->next;
    }
    printf("\n");
}
