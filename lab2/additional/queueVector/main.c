#include "general.h"

int main() {
    Queue *queue = NULL;
    Gen *qGen = genInit(&queue);
    int d = 1;
    while (d) {
        printf("1 - push, 2 - pop, 3 - print\n");
        int ch = get_int(1);
        if (ch == 0) {
            d = 0;
        }
        switch (ch) {
            case 1:
                queue = pushQ(queue, &qGen);
                break;
            case 2:
                queue = popQ(queue, &qGen);
                break;
            case 3:
                printQ(queue, qGen);
                break;
            default:
                break;
        }
    }
    freeQ(queue, qGen);
    return 0;
}