#include "../Model/general.h"

Node *fastFinding(Node **tree, FILE *file) {
    unsigned int num;
    while(fread(&num, sizeof(unsigned int), 1, file)) {
        if (!searchNode(*tree, num)) *tree = insertNode(*tree, num, ftell(file));
    }
    fclose(file);
    return *tree;
}