#include "../Model/general.h"

int d_graphView(BinTree **tree) {
    graphView(*tree);
    return 0;
}

int d_freqWords(BinTree **tree) {
    if (!areYouSure(*tree)) return 1;
    freeTree(*tree);
    *tree = NULL;
    printf("Print name of file:\n");
    char *fileName = get_str();
    if (freqWords(fileName, tree) == 1) return 1;
    printf("Operation ended. Your file's name is freqRes.txt\n");
    return 0;
}


int d_addToFile(BinTree **tree) {
    FILE *file;
    printf("Print name of file:\n");
    char *fileName = get_str();
    if (!(file = fopen(fileName, "w"))) {
        printf("File's not accessible for writing...\n");
        free(fileName);
        return d_addToFile(tree);
    }
    addToFile(*tree, file);
    fclose(file);
    free(fileName);
    return 0;
}

int d_timing(BinTree **tree) {
    if (!areYouSure(*tree)) return 1;
    freeTree(*tree);
    *tree = NULL;
    printf("Print start num:\n");
    int m = getInt(1);
    printf("Print final num:\n");
    int mL = getInt(1);
    printf("Print interval:\n");
    int d = getInt(1);
    randomTreeGeneration(tree, m);
    char *dataR;
    char *keyR;
    FILE *file = fopen("timingTBT.txt", "w");
    fprintf(file, "ListPlot[{");
    while (m <= mL) {
        int version = 1;
        for (int i = 0; i < d; i++) {
            dataR = randomString();
            keyR = randomString();
            *tree = addNode(*tree, dataR, keyR, 0);
        }
        clock_t start = clock();
        searchNode(*tree, keyR, &version);
        double time = ((double) (clock() - start));
        if (m + d < mL) fprintf(file, "{%d, %lf}, ", m, time);
        else fprintf(file, "{%d, %lf}", m, time);
        m += d;
    }
    fprintf(file, "}, Joined -> True]");
    fclose(file);
    return 0;
}

int d_randomTree(BinTree **tree) {
    if (!areYouSure(*tree)) return 1;
    freeTree(*tree);
    *tree = NULL;
    printf("Print num of elements:\n");
    int m = getInt(1);
    randomTreeGeneration(tree, m);
    return 0;
}

int d_addFromFile(BinTree **tree) {
    if (!areYouSure(*tree)) return 0;
    freeTree(*tree);
    *tree = NULL;
    FILE *file;
    printf("Print name of file:\n");
    char *fileName = get_str();
    if (!(file = fopen(fileName, "r"))) {
        printf("No file!\n");
        free(fileName);
        return d_addFromFile(tree);
    }
    *tree = addFromFile(*tree, file);
    fclose(file);
    free(fileName);
    return 0;
}

int areYouSure(BinTree *tree) {
    if (tree) {
        printf("Are you sure? You'll lose your current tree. y/n\n");
        char *ans = get_str();
        if (strlen(ans) == 1) {
            if (!getAnswer(ans)) return 0;
        }
    }
    return 1;
}

int d_addNode(BinTree **tree) {
    printf("Print data:\n");
    char *data = get_str();
    printf("Print key:\n");
    char *key = get_str();
    *tree = addNode(*tree, data, key, 0);
    return 0;
}

int d_searchNode(BinTree **tree) {
    printf("Print key:\n");
    char *key = get_str();
    printf("Print version:\n");
    int version = getInt(1);
    BinTree *searched = searchNode(*tree, key, &version);
    free(key);
    if (!searched) {
        errors(2);
        return 1;
    }
    printf("Item - %s\n", searched->item->data);
    return 0;
}

int d_deleteNode(BinTree **tree) {
    printf("Print key:\n");
    char *key = get_str();
    *tree = deleteNode(*tree, key);
    free(key);
    return 0;
}

int d_printTree(BinTree **tree) {
    if (*tree == NULL) {
        errors(2);
        return 1;
    }
    printTree(*tree);
    return 0;
}

int d_traversal(BinTree **tree) {
    printf("Print left border:\n");
    char *first = get_str();
    printf("Print right border:\n");
    char *second = get_str();
    traversalTree(*tree, first, second);
    return 0;
}

int d_maxNode(BinTree **tree) {
    printf("Print version:\n");
    int version = getInt(1);
    BinTree *maximum = maxNode(*tree, &version);
    if (!maximum) {
        errors(2);
        return 1;
    }
    printf("Maximum = %s, Data - %s\n", maximum->key, maximum->item->data);
    return 0;
}

void printNode(BinTree *current) {
    printf("Key - %s\n", current->key);
    printf("Data - %s\n", current->item->data);
    printf("\n");
}
