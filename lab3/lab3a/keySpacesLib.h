#ifndef LAB3_KEYSPACESLIB_H
#define LAB3_KEYSPACESLIB_H

int keysExistence(Table *, int, char *);
int addKeys(Table *, char *, char *, int);
int keyspaceAdd(Table *, Item *);
void *searchKeys(Table *, char *, char *);
#endif //LAB3_KEYSPACESLIB_H
