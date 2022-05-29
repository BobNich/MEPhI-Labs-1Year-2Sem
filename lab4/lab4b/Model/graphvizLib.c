#include "graphvizLib.h"

void graphviz(Node *tree) {
    int id = 0;
    addIDsTree(tree, &id);
    if (tree) {
        FILE *file = fopen("BTree.dot", "w");
        fprintf(file, "digraph {\nnode [shape = record,height=.1];\n");
        fclose(file);
        selectNode(tree);
        file = fopen("BTree.dot", "a+");
        fprintf(file, "}");
        fclose(file);
        system("D:\\Graphviz\\bin\\dot.exe BTree.dot -Tpng -o BTree.png");
    }
}

void addIDsTree(Node *tree, int *id) {
    if (!tree) return;

    tree->id = *id;
    *id = *id + 1;

    int i = 0;
    while (i < tree->nKeys + 1) {
        if (tree->children[i]) addIDsTree(tree->children[i], id);
        i++;
    }
}

void selectNode(Node *tree) {
    if (!tree) return;

    graphWrite(tree);

    int i = 0;
    while (i < tree->nKeys + 1) {
        if (tree->children[i]) selectNode(tree->children[i]);
        i++;
    }
}

void graphWrite(Node *node) {
    FILE *file = fopen("BTree.dot", "a+");
    if (node->nKeys == 1) {
        fprintf(file, "node%d[label = \"<0>|%d|<1>\"];\n", node->id, node->keys[0]);
    }
    else if (node->nKeys == 2) {
        fprintf(file, "node%d[label = \"<0>|%d|<1>|%d|<2>\"];\n", node->id, node->keys[0], node->keys[1]);
    }
    else {
        fprintf(file, "node%d[label = \"<0>|%d|<1>|%d|<2>|%d|<3>\"];\n", node->id, node->keys[0], node->keys[1], node->keys[2]);
    }
    int i = 0;
    while (i < node->nKeys + 1) {
        if (node->children[i]) fprintf(file, "\"node%d\":%d -> \"node%d\"\n", node->id, i, node->children[i]->id);
        i++;
    }
    fclose(file);
}