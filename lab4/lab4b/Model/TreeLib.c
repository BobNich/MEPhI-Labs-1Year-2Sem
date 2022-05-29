#include "general.h"

/*Insert Node functions*/
Node *insertNode(Node *tree, int key, int data) {

    if (!tree) {
        tree = malloc(sizeof(Node));
        tree->parent = NULL;
        tree->keys[0] = key;
        tree->data[0] = data;
        tree->nKeys = 1;
        nullLeafs(tree);
        return tree;
    }

    tree = splitting(tree, key, true);

    Node *insertNode = findPosition(tree, key);
    putKey(insertNode, key, data);
    insertNode->nKeys++;

    return tree;
}

Node *splitting(Node *tree, int key, bool makeSplit) {
    Node *cNode = tree;
    Node *cParent = cNode->parent;
    if (makeSplit) {
        if (cNode->nKeys == 3) {
            if (!cNode->parent) {
                Node *root = malloc(sizeof(Node));
                nullLeafs(root);
                Node *newR = malloc(sizeof(Node));
                nullLeafs(newR);
                root->nKeys = 1;
                newR->nKeys = 1;
                cNode->nKeys = 1;
                root->keys[0] = cNode->keys[1];
                root->data[0] = cNode->data[1];
                newR->keys[0] = cNode->keys[2];
                newR->data[0] = cNode->data[2];
                root->parent = NULL;
                newR->parent = root;
                cNode->parent = root;
                root->children[0] = cNode;
                root->children[1] = newR;
                newR->children[0] = cNode->children[2];
                newR->children[1] = cNode->children[3];
                cNode->children[2] = NULL;
                cNode->children[3] = NULL;
                if (newR->children[0]) newR->children[0]->parent = newR;
                if (newR->children[1]) newR->children[1]->parent = newR;
                tree = root;
                splitting(root, key, false);
            } else {
                int i = nextChildIndex(cParent, key);
                for (int j = cParent->nKeys; j > i; j--) {
                    cParent->keys[j] = cParent->keys[j - 1];
                    cParent->data[j] = cParent->data[j - 1];
                    cParent->children[j + 1] = cParent->children[j];
                }
                cParent->data[i] = cNode->data[1];
                cParent->keys[i] = cNode->keys[1];
                Node *newR = malloc(sizeof(Node));
                nullLeafs(newR);
                newR->keys[0] = cNode->keys[2];
                cParent->children[i + 1] = newR;
                cParent->nKeys++;
                cNode->nKeys = 1;
                newR->nKeys = 1;
                newR->children[0] = cNode->children[2];
                newR->children[1] = cNode->children[3];
                cNode->children[2] = NULL;
                cNode->children[3] = NULL;
                if (newR->children[0]) newR->children[0]->parent = newR;
                if (newR->children[1]) newR->children[1]->parent = newR;
                newR->data[0] = cNode->data[2];
                newR->parent = cParent;
                splitting(cParent, key, false);
            }
        } else {
            if (!checkIfHasChildren(cNode)) return tree;
            else splitting(cNode->children[nextChildIndex(cNode, key)], key, true);
        }
    } else {
        if (!cParent) splitting(tree->children[nextChildIndex(tree, key)], key, true);
        else if (!checkIfHasChildren(cNode)) return tree;
        else splitting(cNode->children[nextChildIndex(cNode, key)], key, true);
    }
    return tree;
}

/*Delete Node functions*/
Node *deleteNode(Node *tree, int key, Node *dNode) {
    if (!checkIfHasChildren(dNode) && dNode->nKeys > 1) {
        leafNotMinKeys(dNode, key);
        return tree;
    }
    if (!checkIfHasChildren(dNode) && dNode->nKeys == 1) {
        if (!dNode->parent) {free(tree); return NULL;}
        leafMinKeys(dNode, key);
        return tree;
    }
    notLeaf(dNode, key);
    return tree;
}

void leafNotMinKeys(Node *dNode, int key) {
    int index = findKeyInNode(dNode, key);
    for (int i = index; i < dNode->nKeys - 1; i++) {
        dNode->keys[i] = dNode->keys[i + 1];
        dNode->data[i] = dNode->data[i + 1];
    }
    dNode->nKeys--;
}

void leafMinKeys(Node *dNode, int key) {
    bool flagL = false, flagEL = false, flagR = false, flagER = false;
    Node *dParent = dNode->parent;
    int i = nextChildIndex(dNode->parent, key);

    if (i == 0) {
        if (dParent->children[i + 1]->nKeys > 1) flagR = true;
        flagER = true;
    } else if (i == dParent->nKeys) {
        if (dParent->children[i - 1]->nKeys > 1) flagL = true;
        flagEL = true;
    } else {
        flagEL = flagER = true;
        if (dParent->children[i + 1]->nKeys > 1) flagR = true;
        if (dParent->children[i - 1]->nKeys > 1) flagL = true;
    }

    if (flagL) {
        leafMinKeysLeftYes(dNode, i);
        return;
    }

    if (flagR) {
        leafMinKeysRightYes(dNode, i);
        return;
    }

    leafMinKeysNobodyYes(dNode, i, flagEL, flagER);
    return;
}

void leafMinKeysLeftYes(Node *dNode, int i) {
    Node *dParent = dNode->parent;

    dNode->keys[0] = dParent->keys[i - 1];
    dNode->data[0] = dParent->data[i - 1];
    dParent->keys[i - 1] = dParent->children[i - 1]->keys[dParent->children[i - 1]->nKeys - 1];
    dParent->data[i - 1] = dParent->children[i - 1]->data[dParent->children[i - 1]->nKeys - 1];
    dParent->children[i - 1]->nKeys--;
}

void leafMinKeysRightYes(Node *dNode, int i) {
    Node *dParent = dNode->parent;

    dNode->keys[0] = dParent->keys[i];
    dNode->data[0] = dParent->data[i];
    dParent->keys[i] = dParent->children[i + 1]->keys[0];
    dParent->data[i] = dParent->children[i + 1]->data[0];
    dParent->children[i + 1]->nKeys--;
    for (int j = 0; j < dParent->children[i + 1]->nKeys; j++) {
        dParent->children[i + 1]->keys[j] = dParent->children[i + 1]->keys[j + 1];
        dParent->children[i + 1]->data[j] = dParent->children[i + 1]->data[j + 1];
    }
}

void leafMinKeysNobodyYes(Node *dNode, int i, bool flagEL, bool flagER) {
    if (dNode->parent->nKeys != 1) {
        leafMinKeysNobodyYesParentNotMin(dNode, i, flagEL, flagER);
        return;
    } else {
        leafMinKeysNobodyYesParentMin(dNode, i, flagEL, flagER);
        return;
    }
}

void leafMinKeysNobodyYesParentNotMin(Node *dNode, int i, bool flagEL, bool flagER) {
    Node *dParent = dNode->parent;
    if (flagEL) {
        dParent->children[i - 1]->keys[1] = dParent->keys[i - 1];
        dParent->children[i - 1]->data[1] = dParent->data[i - 1];
        dParent->children[i - 1]->nKeys++;
        dParent->nKeys--;
        for (int j = i - 1; j < dParent->nKeys; j++) {
            dParent->keys[j] = dParent->keys[j + 1];
            dParent->data[j] = dParent->data[j + 1];
            dParent->children[j + 1] = dParent->children[j + 2];
        }
        dParent->children[dParent->nKeys + 1] = NULL;
        return;
    }

    if (flagER) {
        dNode->keys[0] = dParent->keys[0];
        dNode->data[0] = dParent->data[0];
        dNode->keys[1] = dParent->children[1]->keys[0];
        dNode->data[1] = dParent->children[1]->data[1];
        dNode->nKeys++;
        dParent->nKeys--;
        for (int j = 0; j < dParent->nKeys; j++) {
            dParent->keys[j] = dParent->keys[j + 1];
            dParent->data[j] = dParent->data[j + 1];
            dParent->children[j + 1] = dParent->children[j + 2];
        }
        dParent->children[dParent->nKeys + 1] = NULL;
        return;
    }
}

void leafMinKeysNobodyYesParentMin(Node *dNode, int i, bool flagEL, bool flagER) {
    if (flagEL) {
        
    }
    else {

    }
}

void notLeaf(Node *dNode, int key) {
    int i = findKeyInNode(dNode, key);
    Node *nextNode = findMostLeft(dNode->children[i + 1]);
    Node *prevNode = findMostRight(dNode->children[i]);

    if (prevNode->nKeys > 1) {
        notLeafPrevYes(dNode, i, prevNode);
        return;
    }
    if (nextNode->nKeys > 1) {
        notLeafNextYes(dNode, i, nextNode);
        return;
    }
    notLeafNobodyYes(dNode, i, prevNode);
    return;
}

void notLeafPrevYes(Node *dNode, int i, Node *prevNode) {
    dNode->keys[i] = prevNode->keys[prevNode->nKeys - 1];
    dNode->data[i] = prevNode->data[prevNode->nKeys - 1];
    prevNode->nKeys--;
}

void notLeafNextYes(Node *dNode, int i, Node *nextNode) {
    dNode->keys[i] = nextNode->keys[0];
    dNode->data[i] = nextNode->data[0];
    nextNode->nKeys--;
    for (int j = 0; j < nextNode->nKeys; j++) {
        nextNode->keys[j] = nextNode->keys[j + 1];
        nextNode->data[j] = nextNode->data[j + 1];
    }
}

void notLeafNobodyYes(Node *dNode, int i, Node *prevNode) {
    dNode->keys[i] = prevNode->keys[0];
    dNode->data[i] = prevNode->data[0];
    leafMinKeys(prevNode, prevNode->keys[0]);
    return;
}

void mergeNodes(Node *fNode, Node *sNode) {

}

/*Search Node functions*/
Node *searchNode(Node *tree, int key) {
    if (!tree) return NULL;
    Node *sNode = tree;
    while (sNode) {
        if (isKeyInNode(sNode, key)) return sNode;
        else sNode = sNode->children[nextChildIndex(sNode, key)];
    }
    return NULL;
}

/*Traversal*/
void traversal(Node *tree, int keyL, int keyR) {
    if (!tree) return;
    traversal(tree->children[0], keyL, keyR);
    for (int i = 0; i < tree->nKeys; i++) {
        if (tree->keys[i] > keyL && tree->keys[i] < keyR)
            printf("Key: %d, Data: %d\n", tree->keys[i], tree->data[i]);
        traversal(tree->children[i + 1], keyL, keyR);
    }
}

/*Special Search (max element)*/
Node *specialSearch(Node *tree) {
    Node *sNode = tree;
    while (sNode) {
        if (sNode->children[sNode->nKeys] == NULL) return sNode;
        else sNode = sNode->children[sNode->nKeys];
    }
    return NULL;
}

/*Free 2-4 tree*/
void freeTree(Node *tree) {
    if (!tree) return;
    freeTree(tree->children[0]);
    free(tree->children[0]);
    for (int i = 0; i < tree->nKeys; i++) {
        freeTree(tree->children[i + 1]);
        free(tree->children[i + 1]);
    }
}

/*Write 2-3-4 tree*/
void writeTree(Node *tree) {
    if (!tree) return;

    for (int i = 0; i < tree->nKeys; i++) {
        printf("Key: %d, Data: %d\n", tree->keys[i], tree->data[i]);
    }

    int i = 0;
    while (i < tree->nKeys + 1) {
        if (tree->children[i]) writeTree(tree->children[i]);
        i++;
    }
}


/*Help-Functions*/
Node *randomTree(Node *tree, int n) {
    int *a = malloc(sizeof(unsigned int) * n * 2);
    for (int i = 0; i < 2 * n; i++) a[i] = i;
    shuffle(a, 2 * n);
    for (int i = 0; i < n; i++) tree = insertNode(tree, a[i], a[i]);
    free(a);
    return tree;
}

void shuffle(int *a, int n) {
    srand(time(NULL));
    int i;
    for (i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&a[i], &a[j]);
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

bool checkIfHasChildren(Node *node) {
    for (int i = 0; i < 4; i++) if (node->children[i] != NULL) return true;
    return false;
}

void nullLeafs(Node *node) {
    for (int i = 0; i < 4; i++) node->children[i] = NULL;
}

void putKey(Node *node, int key, int data) {
    int j = nextChildIndex(node, key);
    for (int i = node->nKeys; i > j; i--) {
        node->keys[i] = node->keys[i - 1];
        node->data[i] = node->data[i - 1];
    }
    node->keys[j] = key;
    node->data[j] = data;
}

bool isKeyInNode(Node *node, int key) {
    for (int i = 0; i < node->nKeys; i++) if (node->keys[i] == key) return true;
    return false;
}

int findKeyInNode(Node *node, int key) {
    for (int i = 0; i < node->nKeys; i++) if (node->keys[i] == key) return i;
    return -1;
}

int nextChildIndex(Node *node, int key) {
    for (int i = 0; i < node->nKeys; ++i) {
        if (node->keys[i] >= key) return i;
    }
    return node->nKeys;
}

Node *findPosition(Node *tree, int key) {
    Node *sNode = tree;
    Node *insertNode = NULL;
    while (sNode) {
        insertNode = sNode;
        sNode = sNode->children[nextChildIndex(sNode, key)];
    }
    return insertNode;
}

/*Functions for finding predecessor and successor*/
Node *findMostRight(Node *node) {
    Node *mrNode = node;
    Node *tmp = NULL;
    while (mrNode) {
        tmp = mrNode;
        mrNode = mrNode->children[mrNode->nKeys];
    }
    return tmp;
}

Node *findMostLeft(Node *node) {
    Node *mlNode = node;
    Node *tmp = NULL;
    while (mlNode) {
        tmp = mlNode;
        mlNode = mlNode->children[0];
    }
    return tmp;
}