#ifndef LAB4_BINTREELIB_H
#define LAB4_BINTREELIB_H
#include "general.h"

Node *insertNode(Node *tree, int key, int data);
Node *searchNode(Node *tree, int key);
Node *specialSearch(Node *tree);
Node *randomTree(Node *tree, int n);
void traversal(Node *tree, int keyL, int keyR);
void writeTree(Node *tree);
void freeTree(Node *tree);

/*Deletion*/
Node *deleteNode(Node *tree, int key, Node *dNode);
void leafNotMinKeys(Node *dNode, int key);
void leafMinKeys(Node *dNode, int index);
void leafMinKeysLeftYes(Node *dNode, int i);
void leafMinKeysRightYes(Node *dNode, int i);
void leafMinKeysNobodyYes(Node *dNode, int i, bool flagEL, bool flagER);
void leafMinKeysNobodyYesParentNotMin(Node *dNode, int i, bool flagEL, bool flagER);
void leafMinKeysNobodyYesParentMin(Node *dNode, int i, bool flagEL, bool flagER);
void notLeaf(Node *dNode, int key);
void notLeafPrevYes(Node *dNode, int i, Node *prevNode);
void notLeafNextYes(Node *dNode, int i, Node *nextNode);
void notLeafNobodyYes(Node *dNode, int i, Node *prevNode);
//

void nullLeafs(Node *node);
void putKey(Node *node, int key, int data);
void swap(int *a, int *b);
void shuffle(int *a, int n);

int nextChildIndex(Node *node, int key);
int findKeyInNode(Node *node, int key);

Node *findPosition(Node *tree, int key);
Node *splitting(Node *node, int key, bool make);
Node *findMostRight(Node *node);
Node *findMostLeft(Node *node);

bool checkIfHasChildren(Node *node);
bool isKeyInNode(Node *node, int key);

#endif
