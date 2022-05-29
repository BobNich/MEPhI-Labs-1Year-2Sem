#include "general.h"

void swap(Node *a, Node *b) {
    Node *k = a;
    a = b;
    b = k;
}

Vector *vectorInit(int size, Node *def) {
    Vector *vector = malloc(sizeof(Vector));
    vector->size = size;
    vector->data = calloc(size, sizeof(Node *));
    for (int i = 0; i < size; i++) vector->data[i] = def;
    return vector;
}

Vector *vectorPush(Vector *vector, Node *value) {
    if (vector == NULL) return vector;
    vectorEnlarge(vector);
    vector->data[vector->size - 1] = value;
    return vector;
}

void vectorEnlarge(Vector *vector) {
    vector->data = realloc(vector->data, (vector->size + 1) * sizeof(Node *));
    vector->data[vector->size++] = 0;
}

Vector *vectorReverse(Vector *vector) {
    if (vector == NULL) return vector;
    for (int i = 0; i < vector->size / 2; i++) swap(vector->data[i], vector->data[vector->size - i - 1]);
    return vector;
}
