#ifndef LAB3_GENERAL_H
#define LAB3_GENERAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Table{
    char * fName;
    int num_of_el;
    struct KeySpace1 *ks1;
    int max_size1;
    int cur_size1;
    struct KeySpace2 *ks2;
    int max_size2;
    int cur_size2;
} Table;

typedef struct Item {
    char *key1;
    char *key2;
    int offset;
} Item;

typedef struct KeySpace1{
    char *key;
    int release;
    Item *info;
    struct KeySpace1 *next;
} KeySpace1;

typedef struct KeySpace2 {
    int busy;
    char *key;
    struct Node2 *node;
    int max_release;
} KeySpace2;

typedef struct Node2 {
    int release;
    Item *info;
    struct Node2 *next;
} Node2;


typedef struct SearchTab {
    char * element;
    char * key1;
    char * key2;
} SearchTab;

#include "tableUtilities.h"
#include "lib.h"
#include "dialog.h"
#include "funcDialog.h"
#include "keySpacesLib.h"
#include "keySpace1.h"
#include "keySpace2.h"
#include "fTableLib.h"

#endif //LAB3_GENERAL_H
