#ifndef LAB4_GENERAL_H
#define LAB4_GENERAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef struct Graph {
    int size;
    struct Node** node;
} Graph;

typedef struct Node {
    int size;
    struct Vertex *vertex;
    struct Edge **edges;
} Node;

typedef struct Edge {
    double weight;
    Node *nodePtr;
} Edge;

typedef struct Vertex {
    char *id;
    int x, y;
    bool visited;
} Vertex;

#include "../Model/vector.h"
#include "GraphLib.h"
#include "utilLib.h"
#include "../Controller/controller.h"
#include "../View/dialog.h"
#include "../View/errs.h"
#include "../Model/canada.h"
#include "../Model/graphvizLib.h"

#endif
