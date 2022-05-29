#ifndef LAB4_DIALOGTREE_H
#define LAB4_DIALOGTREE_H
#include "../Model/general.h"

void dInsertNode(Node **tree);
void dDeleteNode(Node **tree);
void dSearchNode(Node **tree);
void dTraversal(Node **tree);
void dSpecialSearch(Node **tree);
void dWriteTree(Node **tree);
void dImportFile(Node **tree);
void dRandomTree(Node **tree);
void dGraphviz(Node **tree);
void dProfiling(Node **tree);
void dFinding(Node **tree);

#endif