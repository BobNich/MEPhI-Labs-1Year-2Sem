#include "Model/general.h"

void (*func[])(Node **tree) ={
        NULL,
        dInsertNode,
        dDeleteNode,
        dSearchNode,
        dTraversal,
        dSpecialSearch,
        dWriteTree,
        dImportFile,
        dRandomTree,
        dGraphviz,
        dProfiling,
        dFinding
};

int main() {
    Node *tree = NULL;
    int choice = controller();
    while (choice) {
        func[choice](&tree);
        choice = controller();
    }
    freeTree(tree);
    free(tree);
    return 0;
}