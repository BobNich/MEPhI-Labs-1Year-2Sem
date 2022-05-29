#ifndef LAB4_BINTREELIB_H
#define LAB4_BINTREELIB_H
#include "general.h"

BinTree *addNode(BinTree *tree, char * data, char *key, int freqTask);
BinTree *newNode(char *data, char *key);
void createNode(BinTree * tree, BinTree *parent, char *data, char *key);
void createRepNode(BinTree *parent, char *data, char *key);
BinTree *deleteNode(BinTree *tree, char *key);
BinTree *deleteFirstCase(BinTree *tree, BinTree *forDelete);
BinTree *deleteSecondCase(BinTree *tree, BinTree *forDelete);
BinTree *deleteThirdCase(BinTree *tree, BinTree *forDelete);
void freeNode(BinTree *forDelete);
BinTree *searchNode(BinTree *tree, char *key, int *version);

BinTree *maxNode(BinTree *tree, int *version);
BinTree *minNode(BinTree *tree);

BinTree *findPred(BinTree *tree, char *key);
BinTree *findSuc(BinTree *tree, char *key);

void printTree(BinTree *tree);
int printTreeLike(BinTree *tree, int space);
void traversalTree(BinTree *tree, char *first, char *second);
void freeTree(BinTree *tree);

void randomTreeGeneration(BinTree **tree, int n);
char * randomString();
#endif
