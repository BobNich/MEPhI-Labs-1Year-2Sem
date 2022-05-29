#include "options.h"
#include "../Model/general.h"

void optionsView(int N, const char *msgs[]) {
    for (int i = 0; i < N; i++){
        printf("%d: %s\n", i, msgs[i]);
    }
    printf("\nYour choice -->");
}