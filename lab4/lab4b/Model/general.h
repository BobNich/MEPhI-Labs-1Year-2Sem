#ifndef LAB4_GENERAL_H
#define LAB4_GENERAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct Node {
    unsigned int data[3];
    unsigned int keys[3];
    int nKeys;
    struct Node *parent;
    struct Node *children[4];
    int id;
} Node;


#include "TreeLib.h"
#include "utilLib.h"
#include "../Controller/controller.h"
#include "../View/dialog.h"
#include "../View/errs.h"
#include "../View/options.h"
#include "../Model/file.h"
#include "../Model/graphvizLib.h"
#include "../Model/fastFinding.h"

#endif
