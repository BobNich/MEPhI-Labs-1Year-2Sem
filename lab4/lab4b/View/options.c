#include "options.h"
#include "../Model/general.h"

void optionsView(int N, const char *msgs[]) {
    printf("--------------------\n");
    for (int i = 0; i < N; i++){
        printf("%d: %s\n", i, msgs[i]);
    }
    printf("--------------------\n");
    printf("\n->");
}