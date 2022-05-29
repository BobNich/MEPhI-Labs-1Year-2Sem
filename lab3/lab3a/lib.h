#ifndef LAB3_LIB_H
#define LAB3_LIB_H
#include "general.h"

int Table_Init(Table *, int, int);
int Table_Add(Table *, char *, char *, char *);
int Table_Single_Delete(Table *, char *, int, int);
int Table_Multiple_Delete(Table *, char *, char *);

int Table_Single_Search(Table *, char *, int, Item ***, int *, int);
int Table_Single_S1(Table *, char *, Item **, int *);
int Table_Single_S1_R(Table *, int, Item **, int *);
int Table_Single_S2_R(Table *, int, Item **, int *);
int Table_Single_S2(Table *, char *, Item **, int *);

int Table_Multiple_Search(Table *, char *, char *, Node2 **);
int Table_Output(Table *);

void Table_Free(Table *);
void freeElements(Table *);

int addItem(Table *, char *, char *, char *, int);
bool overflow(Table *, int);
int deleteKey1(Table *table, char *, char *);
int deleteKey2(Table *table, char *, char *);
int deleteElement(Table *, Item *);
void freeElement(KeySpace1 *);

#endif //LAB3_LIB_H
