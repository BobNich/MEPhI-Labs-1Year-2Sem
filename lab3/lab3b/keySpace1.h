#ifndef LAB3_KEYSPACE1_H
#define LAB3_KEYSPACE1_H
#include "general.h"

int keySpace1Init(Table *, int, int);
void freeKeySpace1(Table *);
int releaseKey1(Table *table, char *key1);

int ks1SearchVerKey(Table *,SearchTab *,FILE *, char *, int, int);
int ks1DeleteVerKey(Table *, FILE *, char *, int, int);
#endif //LAB3_KEYSPACE1_H
