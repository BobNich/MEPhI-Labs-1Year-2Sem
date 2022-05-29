#ifndef LAB3A_FTABLELIB_H
#define LAB3A_FTABLELIB_H

int Table_Import(Table *, FILE *);
int addKeysImport(Table *, char *, char *, int, int, int);
int addElementFile(Table *, FILE *, int *);
int Table_Rewrite_Description(Table *, FILE *);

#endif //LAB3A_FTABLELIB_H
