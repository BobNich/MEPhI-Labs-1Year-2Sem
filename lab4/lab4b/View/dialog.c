#include "../Model/general.h"


void dInsertNode(Node **tree) {
    printf("Key:\n");
    int key = getInt(1);
    printf("Data:\n");
    int data = getInt(1);
    if (!searchNode(*tree, key))
        *tree = insertNode(*tree, key, data);
    else errors(3);
}

void dDeleteNode(Node **tree) {
    printf("Key:\n");
    int key = getInt(1);
    Node *dNode = searchNode(*tree, key);
    if (dNode) *tree = deleteNode(*tree, key, dNode);
    else errors(2);
}

void dSearchNode(Node **tree) {
    printf("Key:\n");
    int key = getInt(1);
    Node *sNode = searchNode(*tree, key);
    if (!sNode) errors(2);
    else printf("Key: %d, Data: %d\n", sNode->keys[findKeyInNode(sNode, key)], sNode->data[findKeyInNode(sNode, key)]);
}

void dTraversal(Node **tree) {
    if (!*tree) {
        errors(2);
        return;
    }
    printf("Key (Left bound):\n");
    int keyL = getInt(1);
    printf("Key (Right bound):\n");
    int keyR = getInt(1);
    traversal(*tree, keyL, keyR);
}

void dSpecialSearch(Node **tree) {
    Node *sNode = specialSearch(*tree);
    if (!sNode) errors(2);
    else printf("Key: %d, Data: %d\n", sNode->keys[sNode->nKeys - 1], sNode->data[sNode->nKeys - 1]);
}

void dWriteTree(Node **tree) {
    if (!*tree) {
        errors(2);
        return;
    }
    writeTree(*tree);
}

void dImportFile(Node **tree) {
    freeTree(*tree);
    free(*tree);
    *tree = NULL;

    FILE *file;
    printf("FileName:\n");
    char *fileName = get_str();
    if (!(file = fopen(fileName, "r"))) {
        printf("File's not accessible.\n");
        free(fileName);
        return;
    }
    *tree = importTree(*tree, file);
    fclose(file);
    free(fileName);
}

void dRandomTree(Node **tree) {
    freeTree(*tree);
    free(*tree);
    *tree = NULL;

    printf("Number of elements:\n");
    int n = getInt(1);
    *tree = randomTree(*tree, n);
}

void dGraphviz(Node **tree) {
    graphviz(*tree);
}

void dProfiling(Node **tree) {
    freeTree(*tree);
    free(*tree);
    *tree = NULL;

    FILE *file = fopen("profile.txt", "w");
    fprintf(file, "ListPlot[{");
    for (int i = 100000; i <= 5000000; i += 100000) {
        *tree = randomTree(*tree, i);

        srand(clock());
        clock_t begin = clock();
        for (int j = 0; j < 1000000; j++) searchNode(*tree, rand());
        clock_t time = clock() - begin;
        printf("%d, %ld\n", i, time);
        fprintf(file, "{%d, %ld}, ", i, time);

        freeTree(*tree);
        free(*tree);
        *tree = NULL;
    }
    fprintf(file, "}]");
    fclose(file);
}

void dFinding(Node **tree) {
    FILE *file;
    printf("FileName:\n");
    char *fileName = get_str();
    if (!(file = fopen(fileName, "rb"))) {
        printf("File's not accessible.\n");
        free(fileName);
        return;
    }
    freeTree(*tree);
    free(*tree);
    *tree = NULL;

    fastFinding(tree, file);
}