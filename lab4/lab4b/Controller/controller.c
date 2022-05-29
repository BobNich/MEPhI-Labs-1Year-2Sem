#include "../Model/general.h"

const char *msgs[] = {"Exit", "Add element", "Delete", "Search by key", "Tree traversal",
                      "Special Search", "Tree Output", "Add from file", "Random tree", "Draw Graph", "Profiling", "Fast finding"};

const int N = sizeof(msgs) / sizeof(msgs[0]);

int controller() {
    int choice;
    optionsView(N, msgs);
    do {
        choice = getInt(0);
        if (choice < 0 || choice >= N) {
            errors(1);
        }
    } while (choice < 0 || choice >= N);
    return choice;
}

