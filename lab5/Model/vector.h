#ifndef LAB5_VECTOR_H
#define LAB5_VECTOR_H
#include "general.h"

typedef struct Vector {
    int size;
    Node **data;
} Vector;

Vector *vectorInit(int size, Node *fill);

Vector *vectorPush(Vector *vector, Node *value);

void vectorEnlarge(Vector *vector);

Vector *vectorReverse(Vector *vector);

#endif