#include "general.h"

bool getAnswer(char *ans) {
    if (strlen(ans) == 1 && ans[0] == 'y' || ans[0] == 'Y') {
        free(ans);
        return true;
    }
    else if (strlen(ans) == 1 && ans[0] == 'n' || ans[0] == 'N') {
        free(ans);
        return false;
    }
    return false;
}

int getInt(int type) {
    int num;
    int check = 1;
    while (check == 1) {
        char *n = get_str();
        if (type == 1 && n[0] == '-') {
            check = 0;
        } else if (strlen(n) == 0) {
            check = 0;
        } else if (n[0] != '-' && !(n[0] >= '0' && n[0] <= '9')) {
            check = 0;
        } else {
            for (int i = 1; i < strlen(n); i++) {
                if (!(n[i] >= '0' && n[i] <= '9')) {
                    check = 0;
                }
            }
        }
        if (check != 0) {
            num = (int) atoi(n);
            free(n);
            return num;
        } else {
            errors(1);
            free(n);
            check = 1;
        }
    }
}

char *get_str() {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = (int) strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else {
            scanf("%*c");
        }
    } while (n > 0);
    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }
    return res;
}


// 1 - {1>2}, 2 - {2>1}, 3 - {1=2} //
int cmpStrings(char *first, char* second) {
   int cmp = strcmp(first, second);
   if (cmp > 0) {
       return 1;
   }
   else if (cmp < 0){
       return 2;
   }
   else {
       return 3;
   }
}

char *get_str_file(FILE *file) {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = fscanf(file, "%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = (int) strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else {
            fscanf(file, "%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }
    return res;
}
