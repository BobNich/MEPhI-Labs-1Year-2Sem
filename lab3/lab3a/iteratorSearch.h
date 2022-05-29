#ifndef LAB3A_ITERATORSEARCH_H
#define LAB3A_ITERATORSEARCH_H

void *iteratorSearch(void *, void *(f)(void *));
void *nextKey1(void *);
void *nextKey2(void *);
void *nextKeys(void *);
int iterateKey2(Table *);
int iterateKey1(Table *);
int iterateTable(Table *, int);
int iterateKeys(Table *);
#endif //LAB3A_ITERATORSEARCH_H
