#ifndef LAB3_LIB_H
#define LAB3_LIB_H
#include "general.h"

int Table_Init(Table *, FILE *, int, int);
int Table_Add(Table *, FILE *, char *, char *, char *);
int Table_Single_Delete(Table *, FILE *, char *, int, int);
int Table_Multiple_Delete(Table *, FILE *, char *, char *);

int printElementFile(Table *, FILE *, Item *);

int Table_Single_Search(Table *, char *, int, Item ***, int *, int);
int Table_Single_S1(Table *, char *, Item **, int *);
int Table_Single_S1_R(Table *, int, Item **, int *);
int Table_Single_S2_R(Table *, int, Item **, int *);
int Table_Single_S2(Table *, char *, Item **, int *);

int Table_Multiple_Search(Table *, FILE *, char *, char *, Node2 **);
int Table_Output(Table *, FILE *);

void Table_Free(Table *);

int addItem(Table *, FILE *, char *, char *, char *, int);
bool overflow(Table *, int);
int deleteKey1(Table *table, FILE *, char *, Item *);
int deleteKey2(Table *table, FILE *, char *, Item *);
int deleteElement(Table *, FILE *, Item *);

#endif //LAB3_LIB_H
