#include "../Model/general.h"

const char *msgs[] = {"Exit", "Add element", "Delete", "Tree traversal", "Search by key",
                      "Special Search", "Tree Output", "Add from file",
                      "Add to file", "Timing", "Freq.", "Create Random Tree", "Draw Graph"};

const int N = sizeof(msgs) / sizeof(msgs[0]);

int dialog() {
    int choice;
    printf("---------------------------\n");
    optionsView(N, msgs);
    do {
        choice = getInt(0);
        printf("\n");
        if (choice < 0 || choice >= N) {
            errors(1);
        }
    } while (choice < 0 || choice >= N);
    return choice;
}

