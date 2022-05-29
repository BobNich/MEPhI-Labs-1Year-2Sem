#include "errorsLib.h"
#include "../Model/general.h"

void errors(int erNum) {
    switch (erNum) {
        case 1:
            printf("---------------------------\n");
            printf("[Error: INCORRECT INPUT]\n");
            printf("Repeat -->");
            break;
        case 2:
            printf("---------------------------\n");
            printf("[Error: NO ELEMENT(S)]\n");
            break;
        default:
            break;
    }
}