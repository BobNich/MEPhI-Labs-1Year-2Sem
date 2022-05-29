#include "../Model/general.h"

BinTree *addFromFile(BinTree *tree, FILE *file) {
    char *key;
    char *data;
    while ((key = get_str_file(file)) != NULL) {
        data = get_str_file(file);
        tree = addNode(tree, data, key, 0);
    }
    return tree;
}

void addToFile(BinTree *tree, FILE *file) {
    BinTree *current = tree;
    fprintf(file, "%s", current->key);
    fprintf(file, "\n");
    fprintf(file, "%s", current->item->data);
    fprintf(file, "\n");
    if (tree->left != NULL) {
        addToFile(tree->left, file);
    }
    if (tree->right != NULL) {
        if (tree->rightThread == false) {
            addToFile(tree->right, file);
        }
    }
}