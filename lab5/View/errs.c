#include "errs.h"
#include "../Model/general.h"

const char *errMsg[] = {
        "<Ok>",
        "<Error: Incorrect input>\n->",
        "<Error: No elements>",
        "<Error: Repeated element>",
        "<Error: No path>",
        "<Error: File's not accessible>"
};

void errors(int erNum) {
    printf("%s\n", errMsg[erNum]);
}