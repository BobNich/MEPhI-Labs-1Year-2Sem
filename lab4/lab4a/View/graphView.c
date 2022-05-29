#include "../Model/general.h"

void graphView(BinTree *tree) {
    if (tree) {
        int count = 0;
        FILE *file = fopen("binTree.dot", "w");
        fprintf(file, "digraph {\n");
        fclose(file);
        selectNode(tree, &count);
        file = fopen("binTree.dot", "a+");
        fprintf(file, "}");
        fclose(file);
        system("D:\\Graphviz\\bin\\dot.exe binTree.dot -Tpng -o binTree.png");
    }
}

void selectNode(BinTree *tree, int *count) {

    if (!tree->parent && tree->left == NULL && tree->right == NULL) {
        printf("%s\n", tree->key);
    }

    graphWrite(tree, count);
    if (tree->left != NULL) {
        selectNode(tree->left, count);
    }
    if (tree->right != NULL) {
        if (tree->rightThread == false) {
            selectNode(tree->right, count);
        }
    }
}

void graphWrite(BinTree *node, int *count) {
    FILE *file = fopen("binTree.dot", "a+");
    if (node->left != NULL) {
        fprintf(file, "\"%s_%d\" -> ", node->key, node->item->graphVer);
        fprintf(file, "\"%s_%d\";\n", node->left->key, node->left->item->graphVer);
    } else {
        fprintf(file, "null%d [shape=point];\n", *count);
        fprintf(file, "\"%s_%d\" -> null%d;\n", node->key, node->item->graphVer, *count);
        (*count)++;
    }

    if (node->right != NULL) {
        fprintf(file, "\"%s_%d\" -> ", node->key, node->item->graphVer);
        fprintf(file, "\"%s_%d\";\n", node->right->key, node->right->item->graphVer);
    } else {
        fprintf(file, "null%d [shape=point];\n", *count);
        fprintf(file, "\"%s_%d\" -> null%d;\n", node->key, node->item->graphVer, *count);
        (*count)++;
    }
    fclose(file);
}
