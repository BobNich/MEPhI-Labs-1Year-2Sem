#ifndef LAB4B_GRAPHVIZLIB_H
#define LAB4B_GRAPHVIZLIB_H
#include "../Model/general.h"

void graphviz(Node *tree);
void selectNode(Node *tree);
void graphWrite(Node *node);
void addIDsTree(Node *tree, int *id);

#endif