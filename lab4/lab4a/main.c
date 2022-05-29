#include "Model/general.h"

int (*func[])(BinTree **tree) = {NULL, d_addNode, d_deleteNode, d_traversal, d_searchNode, d_maxNode, d_printTree, d_addFromFile, d_addToFile, d_timing, d_freqWords, d_randomTree, d_graphView};

int main() {
    BinTree *tree = NULL;
    int choice = dialog();
    while (choice) {
        func[choice](&tree);
        choice = dialog();
    }
    graphView(tree);
    freeTree(tree);
    return 0;
}