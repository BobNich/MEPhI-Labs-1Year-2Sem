#include "../Model/general.h"

Node * importTree(Node *tree, FILE *file) {
    char *key;
    char *data;
    while ((key = getStrFile(file)) != NULL) {
        data = getStrFile(file);
        tree = insertNode(tree, atoi(key), atoi(data));
        free(key);
        free(data);
    }
    return tree;
}