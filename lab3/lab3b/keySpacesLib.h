#ifndef LAB3_KEYSPACESLIB_H
#define LAB3_KEYSPACESLIB_H

int keysExistence(Table *, int, char *);
int addKeys(Table *, char *, char *, int);
int keyspaceAdd(SearchTab *new_table,Table *table, FILE *, Item *tmp, int);

#endif //LAB3_KEYSPACESLIB_H
