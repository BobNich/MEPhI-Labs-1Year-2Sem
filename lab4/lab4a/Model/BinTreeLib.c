#include "general.h"

BinTree *addNode(BinTree *tree, char *data, char *key, int freqTask) {
    BinTree *current = tree;
    BinTree *parent = NULL;

    if (tree == NULL) return newNode(data, key);

    while (current) {
        parent = current;
        if (cmpStrings(key, current->key) == 1) {
            if (current->rightThread) {
                current->right = NULL;
                current->rightThread = false;
                current = current->right;
            } else current = current->right;
        } else if (cmpStrings(key, current->key) == 2) current = current->left;
        else {
            if (freqTask) {
                char *put = calloc(sizeof(char), 10);
                sprintf(put, "%d", atoi(current->item->data) + 1);
                current->item->data = put;
                return tree;
            }
            if (current->left != NULL) {
                if (cmpStrings(current->left->key, current->key) != 3) {
                    createRepNode(parent, data, key);
                    return tree;
                } else current = current->left;
            } else {
                createRepNode(parent, data, key);
                return tree;
            }
        }
    }
    createNode(tree, parent, data, key);
    return tree;
}

void createRepNode(BinTree *parent, char *data, char *key) {
    BinTree *current = newNode(data, key);
    current->parent = parent;
    current->left = parent->left;
    current->right = parent;
    current->rightThread = true;
    current->item->graphVer = current->parent->item->graphVer + 1;
    parent->left = current;
    if (current->left != NULL) {
        if (current->left->rightThread) {
            current->left->right = current;
        }
    }
}

void createNode(BinTree *tree, BinTree *parent, char *data, char *key) {
    BinTree *current = newNode(data, key);
    current->parent = parent;

    if (cmpStrings(key, parent->key) == 1) parent->right = current;
    else parent->left = current;

    current->right = findSuc(tree, key);
    if (current->right) current->rightThread = true;
}

BinTree *newNode(char *data, char *key) {
    BinTree *new = malloc(sizeof(BinTree));
    new->item = malloc(sizeof(Item));
    new->item->data = data;
    new->key = key;
    new->left = new->right = NULL;
    new->parent = NULL;
    new->rightThread = false;
    new->item->graphVer = 0;
    return new;
}

void printTree(BinTree *tree) {
    BinTree *current = minNode(tree);
    while (current) {
        printNode(current);
        if (current->rightThread) current = current->right;
        else current = minNode(current->right);
    }
}

void freeTree(BinTree *tree) {
    BinTree *current = minNode(tree);
    while (current) {
        BinTree *tmp = current;
        if (current->rightThread) current = current->right;
        else current = minNode(current->right);
        freeNode(tmp);
    }
}

BinTree *searchNode(BinTree *tree, char *key, int *version) {
    if (!tree) return NULL;
    if (cmpStrings(tree->key, key) == 3) {
        (*version)--;
        if (*version == 0) return tree;
        else return searchNode(tree->left, key, version);
    }
    if (cmpStrings(key, tree->key) == 2)
        return searchNode(tree->left, key, version);
    else {
        if (tree->right) {
            if (cmpStrings(tree->right->key, key) == 3) return tree->right;
        }
        return searchNode(tree->right, key, version);
    }
}

void traversalTree(BinTree *tree, char *first, char *second) {
    BinTree *current = minNode(tree);
    while (current) {
        if (cmpStrings(current->key, first) == 2 || cmpStrings(current->key, second) == 1)
            printNode(current);
        if (current->rightThread) current = current->right;
        else current = minNode(current->right);
    }
    free(first);
    free(second);
}

BinTree *maxNode(BinTree *tree, int *version) {
    if (tree == NULL) return NULL;
    if (tree->rightThread == true || tree->right == NULL) {
        while (*version != 1) {
            (*version)--;
            tree = tree->left;
        }
        return tree;
    }
    return maxNode(tree->right, version);
}

BinTree *minNode(BinTree *tree) {
    if (tree == NULL) return NULL;
    if (tree->left == NULL) return tree;
    return minNode(tree->left);
}

BinTree *findSuc(BinTree *tree, char *key) {
    BinTree *current = tree;
    BinTree *successor = NULL;
    while (current) {
        if (cmpStrings(current->key, key) == 1) {
            successor = current;
            current = current->left;
        } else current = current->right;
    }
    return successor;
}

BinTree *findPred(BinTree *tree, char *key) {
    BinTree *current = tree;
    BinTree *pred = NULL;
    while (current) {
        if (cmpStrings(current->key, key) == 2) {
            pred = current;
            if (current->right) {
                if (current->rightThread == true) {
                    return pred;
                }
            }
            current = current->right;
        } else current = current->left;
    }
    return pred;
}

void freeNode(BinTree *forFree) {
    free(forFree->item->data);
    free(forFree->item);
    free(forFree->key);
    free(forFree);
}

BinTree *deleteNode(BinTree *tree, char *key) {
    int version = 1;
    BinTree *forDelete = searchNode(tree, key, &version);
    if (!forDelete) {
        errors(2);
        return tree;
    }
    if (forDelete->left != NULL && (forDelete->right != NULL && forDelete->rightThread == false))
        tree = deleteFirstCase(tree, forDelete);
    else if (forDelete->left == NULL && (forDelete->right == NULL || forDelete->rightThread == true))
        tree = deleteThirdCase(tree, forDelete);
    else tree = deleteSecondCase(tree, forDelete);
    return tree;
}

BinTree *deleteThirdCase(BinTree *tree, BinTree *forDelete) {
    if (forDelete->parent == NULL) {
        freeNode(forDelete);
        return NULL;
    } else if (forDelete == forDelete->parent->left)
        forDelete->parent->left = NULL;
    else {
        forDelete->parent->right = forDelete->right;
        forDelete->parent->rightThread = true;
        if (forDelete->right == NULL) {
            forDelete->parent->rightThread = false;
        }
    }
    freeNode(forDelete);
    return tree;
}

BinTree *deleteSecondCase(BinTree *tree, BinTree *forDelete) {
    BinTree *child;
    if (forDelete->left != NULL) {
        child = forDelete->left;
    } else {
        child = forDelete->right;
    }
    child->parent = forDelete->parent;
    if (forDelete->parent == NULL) {
        freeNode(forDelete);
        child->parent = NULL;
        tree = child;
        if (tree->rightThread == true) {
            tree->right = NULL;
        }
        tree->rightThread = false;
        return tree;
    } else if (forDelete == forDelete->parent->left) {
        forDelete->parent->left = child;
    } else {
        forDelete->parent->right = child;
    }
    BinTree *pred = findPred(tree, forDelete->key);
    if (forDelete->left != NULL) {
        pred->right = forDelete->right;
        if (pred->right == NULL) {
            pred->rightThread = false;
        }
    }
    freeNode(forDelete);
    return tree;
}

BinTree *deleteFirstCase(BinTree *tree, BinTree *forDelete) {
    BinTree *suc = findSuc(tree, forDelete->key);

    free(forDelete->key);
    forDelete->key = malloc(sizeof(char) * (strlen(suc->key) + 1));
    memcpy(forDelete->key, suc->key, (strlen(suc->key) + 1));
    free(forDelete->item->data);
    forDelete->item->data = malloc(sizeof(char) * (strlen(suc->item->data) + 1));
    memcpy(forDelete->item->data, suc->item->data, (strlen(suc->item->data) + 1));

    deleteNode(suc, suc->key);
    return tree;
}

void randomTreeGeneration(BinTree **tree, int m) {
    for (int j = 0; j < m; j++) {
        char *dataR = randomString();
        char *keyR = randomString();
        *tree = addNode(*tree, dataR, keyR, 0);
    }
}

char *randomString() {
    int n = rand() % 20;
    char *buffer = calloc(n + 1, sizeof(char));
    for (int i = 0; i < n; i++) {
        char ch = (char) ((rand() % 58) + 65);
        buffer[i] = ch;
    }
    return buffer;
}