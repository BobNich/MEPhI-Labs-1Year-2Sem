#include "general.h"

int D_Table_Init(Table *table, FILE *fTable, const char *err_msgs[]) {
    int err;

    printf("Print filename you want work with (.bin):\n");
    char *fileName = get_str();
    table->fName = fileName;

    printf("Choose: 1 - Import table from file, 2 - Create new one\n");
    int choice = getInt(1);

    if (choice == 2) {
        printf("Print max size of the 1st Key Space:\n");
        int ms1 = getInt(1);
        printf("Print max size of the 2nd Key Space:\n");
        int ms2 = getInt(1);
        if (!(fTable = fopen(fileName, "wb"))) {
            return 1;
        };
        fclose(fTable);
        err = Table_Init(table, fTable, ms1, ms2);
    } else {
        err = Table_Import(table, fTable);
    }
    if (err == 7) {
        printf("Rewrite name of the file!\n");
        free(table->fName);
        return D_Table_Init(table, fTable, err_msgs);
    }
    printf("Initialization status: %s\n", err_msgs[err]);
    return 1;
}

int D_Table_Add(Table *table, FILE *fTable, const char *err_msgs[]) {
    int err;
    char *new_element;
    char *key1;
    char *key2;

    printf("Print element:\n");
    new_element = get_str();
    if (new_element == NULL) {
        return 0;
    }

    printf("Print Key for the 1st Key Space:\n");
    key1 = get_str();
    if (key1 == NULL) {
        free(new_element);
        return 0;
    }

    printf("Print Key for the 2nd Key Space:\n");
    key2 = get_str();
    if (key2 == NULL) {
        free(key2);
        free(key1);
        free(new_element);
        return 0;
    }

    err = Table_Add(table, fTable, new_element, key1, key2);
    printf("Adding status: %s\n", err_msgs[err]);
    return 1;
}


int D_Table_Single_Search(Table *table, FILE *fTable, const char *err_msgs[]) {
    int err;
    char *key;
    Item **items = calloc(table->num_of_el, sizeof(char *));
    int len = 0;

    printf("Choose Key Space (1 or 2):\n");
    int choice = getInt(1);
    while (choice > 2 || choice < 1) {
        printf("Invalid choice!\n");
        choice = getInt(1);
    }
    printf("Choose Key:\n");
    key = get_str();

    err = Table_Single_Search(table, key, choice, &items, &len, 0);

    if (err == 0) {
        for (int i = 0; i < len; i++) {
            printElementFile(table, fTable, items[i]);
        }
    }
    free(items);

    printf("Single search status: %s\n", err_msgs[err]);
    free(key);
    return 1;
}

int D_Table_Multiple_Search(Table *table, FILE *fTable, const char *err_msgs[]) {
    int err;
    char *key1;
    char *key2;

    printf("Print Key for the 1st Key Space:\n");
    key1 = get_str();
    if (key1 == NULL) {
        return 0;
    }

    printf("Print Key for the 2nd Key Space:\n");
    key2 = get_str();
    if (key2 == NULL) {
        free(key1);
        return 0;
    }

    Node2 *item = NULL;
    err = Table_Multiple_Search(table, fTable, key1, key2, &item);
    if (err == 0) {
        Item *nItem = item->info;
        printElementFile(table, fTable, nItem);
    }
    printf("Multiple search status: %s\n", err_msgs[err]);
    free(key1);
    free(key2);
    return 1;
}


int D_Table_Output(Table *table, FILE *fTable, const char *err_msgs[]) {
    int err;

    err = Table_Output(table, fTable);

    printf("Output status: %s\n", err_msgs[err]);
    return 1;
}

int D_Table_Multiple_Delete(Table *table, FILE *fTable, const char *err_msgs[]) {
    int err;
    char *key1;
    char *key2;

    printf("Print Key for the 1st Key Space:\n");
    key1 = get_str();
    if (key1 == NULL) {
        return 0;
    }

    printf("Print Key for the 2nd Key Space:\n");
    key2 = get_str();
    if (key2 == NULL) {
        free(key1);
        return 0;
    }

    err = Table_Multiple_Delete(table, fTable, key1, key2);
    free(key1);
    free(key2);
    printf("Multiple delete status: %s\n", err_msgs[err]);
    return 1;
}

int D_Table_Single_Delete(Table *table, FILE *fTable, const char *err_msgs[]) {
    int err;
    char *key;

    printf("Choose Key Space (1 or 2):\n");
    int choice = getInt(1);
    while (choice > 2 || choice < 1) {
        printf("Invalid choice!\n");
        choice = getInt(1);
    }
    printf("Choose Key:\n");
    key = get_str();

    err = Table_Single_Delete(table, fTable, key, choice, 0);
    free(key);
    printf("Single delete status: %s\n", err_msgs[err]);
    return 1;
}

int D_ks1SearchVerKey(Table *table, FILE *fTable, const char *err_msgs[]) {

    SearchTab *new_table = malloc(sizeof(SearchTab) * table->num_of_el);
    int err;
    char *key = NULL;
    int release;

    printf("Choose (1 - Key or 2 - Release):\n");
    int choice = getInt(1);
    while (choice > 2 || choice < 1) {
        printf("Invalid choice!\n");
        choice = getInt(1);
    }

    if (choice == 1) {
        printf("Print key:\n");
        key = get_str();
    } else {
        printf("Print Release:\n");
        release = getInt(0);
    }

    err = ks1SearchVerKey(table, new_table, fTable, key, release, choice);

    printf("Search by Key or Release status: %s\n", err_msgs[err]);
    free(new_table);
    free(key);
    return 1;
}

int D_ks1DeleteVerKey(Table *table, FILE *fTable, const char *err_msgs[]) {
    int err;
    char *key = NULL;
    int release;

    printf("Choose (1 - Key or 2 - Release):\n");
    int choice = getInt(1);
    while (choice > 2 || choice < 1) {
        printf("Invalid choice!\n");
        choice = getInt(1);
    }

    if (choice == 1) {
        printf("Print key:\n");
        key = get_str();
    } else {
        printf("Print Release:\n");
        release = getInt(0);
    }

    err = ks1DeleteVerKey(table, fTable, key, release, choice);

    printf("Delete by Key or Release status: %s\n", err_msgs[err]);
    free(key);
    return 1;
}

int D_ks2SearchVerKey(Table *table, FILE *fTable, const char *err_msgs[]) {

    SearchTab *new_table = malloc(sizeof(SearchTab) * table->num_of_el);
    int err;
    char *key = NULL;
    int release;

    printf("Choose (1 - Key or 2 - Release):\n");
    int choice = getInt(1);
    while (choice > 2 || choice < 1) {
        printf("Invalid choice!\n");
        choice = getInt(1);
    }

    if (choice == 1) {
        printf("Print key:\n");
        key = get_str();
    } else {
        printf("Print Release:\n");
        release = getInt(0);
    }

    err = ks2SearchVerKey(table, new_table, fTable, key, release, choice);
    printf("Search by Key or Release status: %s\n", err_msgs[err]);
    free(new_table);
    free(key);
    return 1;
}

int D_ks2DeleteVerKey(Table *table, FILE *fTable, const char *err_msgs[]) {
    int err;
    char *key = NULL;
    int release;

    printf("Choose (1 - Key or 2 - Release):\n");
    int choice = getInt(1);
    while (choice > 2 || choice < 1) {
        printf("Invalid choice!\n");
        choice = getInt(1);
    }

    if (choice == 1) {
        printf("Print key:\n");
        key = get_str();
    } else {
        printf("Print Release:\n");
        release = getInt(0);
    }

    err = ks2DeleteVerKey(table, fTable, key, release, choice);
    printf("Delete by Key or Release status: %s\n", err_msgs[err]);
    free(key);
    return 1;
}
