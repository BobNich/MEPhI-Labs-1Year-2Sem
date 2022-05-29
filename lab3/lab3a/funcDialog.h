#ifndef LAB3_FUNCDIALOG_H
#define LAB3_FUNCDIALOG_H
#include "general.h"

int D_Table_Add(Table *, const char *err_msgs[]);
int D_Table_Single_Delete(Table *, const char *err_msgs[]);
int D_Table_Multiple_Delete(Table *, const char *err_msgs[]);
int D_Table_Single_Search(Table *, const char *err_msgs[]);
int D_Table_Multiple_Search(Table *, const char *err_msgs[]);
int D_Table_Output(Table *, const char *err_msgs[]);
int D_Table_Init(Table *, const char *err_msgs[]);
int D_ks1SearchVerKey(Table *, const char *err_msgs[]);
int D_ks1DeleteVerKey(Table *, const char *err_msgs[]);
int D_ks2SearchVerKey(Table *, const char *err_msgs[]);
int D_ks2DeleteVerKey(Table *, const char *err_msgs[]);

int D_Iterator(Table *, const char *err_msgs[]);
#endif //LAB3_FUNCDIALOG_H
