#ifndef LAB4_GENERAL_H
#define LAB4_GENERAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct BinTree {
    char *key;
    struct Item *item;
    struct BinTree *parent;
    struct BinTree *left;
    struct BinTree *right;
    bool rightThread;
} BinTree;

typedef struct Item {
    char *data;
    int graphVer;
} Item;

#include "BinTreeLib.h"
#include "utilLib.h"
#include "../Controller/dialog.h"
#include "../View/dialogTree.h"
#include "../View/errorsLib.h"
#include "../View/options.h"
#include "../Model/fileTree.h"
#include "../Model/freqWords.h"
#include "../View/graphView.h"
#endif
