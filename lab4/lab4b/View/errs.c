#include "errs.h"
#include "../Model/general.h"

void errors(int erNum) {
    if (erNum == 1) printf("---Error: Incorrect input---\n->");
    else if (erNum == 2) printf("---Error: No element(s)---\n");
    else if (erNum == 3) printf("---Error: Repeated key---\n");
}