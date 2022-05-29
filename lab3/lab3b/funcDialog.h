#ifndef LAB3_FUNCDIALOG_H
#define LAB3_FUNCDIALOG_H
#include "general.h"

int D_Table_Add(Table *, FILE *, const char *err_msgs[]);
int D_Table_Single_Delete(Table *, FILE *, const char *err_msgs[]);
int D_Table_Multiple_Delete(Table *, FILE *, const char *err_msgs[]);
int D_Table_Single_Search(Table *, FILE *, const char *err_msgs[]);
int D_Table_Multiple_Search(Table *, FILE *, const char *err_msgs[]);
int D_Table_Output(Table *, FILE *, const char *err_msgs[]);
int D_Table_Init(Table *, FILE *, const char *err_msgs[]);
int D_ks1SearchVerKey(Table *, FILE *, const char *err_msgs[]);
int D_ks1DeleteVerKey(Table *, FILE *, const char *err_msgs[]);
int D_ks2SearchVerKey(Table *, FILE *, const char *err_msgs[]);
int D_ks2DeleteVerKey(Table *, FILE *, const char *err_msgs[]);

#endif //LAB3_FUNCDIALOG_H
