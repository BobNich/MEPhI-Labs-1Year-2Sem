#ifndef LAB3_KEYSPACE2_H
#define LAB3_KEYSPACE2_H
#include "general.h"

int keySpace2Init(Table *, int);
void freeKeySpace2(Table *);
int searchKey2(Table *, char *);
int hash(Table *, char *);
int searchEmptyPosKey2(Table *, int);

int ks2SearchVerKey(Table *, Table *, char *, int, int);
int ks2DeleteVerKey(Table *, char *, int, int);
#endif //LAB3_KEYSPACE2_H
