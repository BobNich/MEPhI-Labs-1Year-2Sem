#ifndef LAB4_DIALOGTREE_H
#define LAB4_DIALOGTREE_H
#include "../Model/general.h"

int d_addNode(BinTree **);
int d_printTree(BinTree **);
int d_searchNode(BinTree **);
int d_deleteNode(BinTree **);
int d_traversal(BinTree **);
int d_maxNode(BinTree **);
void printNode(BinTree *current);
int d_addFromFile(BinTree **);
int d_addToFile(BinTree **tree);
int d_printTreeLike(BinTree **tree);
int d_timing(BinTree **tree);
int d_freqWords(BinTree **tree);
int d_randomTree(BinTree **tree);
int d_graphView(BinTree **tree);

int areYouSure(BinTree *tree);
#endif