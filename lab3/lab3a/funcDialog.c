#include "general.h"


int D_Iterator(Table *table, const char *err_msgs[]) {
    int choice;
    printf("Choose (1 - key1, 2 - key2, 3 - [key1,key2])\n");
    choice = getInt(1);
    iterateTable(table, choice);
    return 1;
}



int D_Table_Init(Table *table, const char *err_msgs[]){
    int err;
    printf("Print max size of the 1st Key Space:\n");
    int ms1 = getInt(1);
    printf("Print max size of the 2nd Key Space:\n");
    int ms2 = getInt(1);
    err = Table_Init(table, ms1, ms2);
    printf("Initialization status: %s\n", err_msgs[err]);
    return 1;
}

int D_Table_Add(Table *table, const char *err_msgs[]){
    int err;
    char *new_element;
    char *key1;
    char *key2;

    printf("Print element:\n");
    new_element = get_str();
    if (new_element == NULL){
        return 0;
    }

    printf("Print Key for the 1st Key Space:\n");
    key1 = get_str();
    if (key1 == NULL){
        free(new_element);
        return 0;
    }

    printf("Print Key for the 2nd Key Space:\n");
    key2 = get_str();
    if (key2 == NULL){
        free(key2);
        free(key1);
        free(new_element);
        return 0;
    }

    err = Table_Add(table, new_element, key1, key2);
    printf("Adding status: %s\n", err_msgs[err]);
    return 1;
}


int D_Table_Single_Search(Table *table, const char *err_msgs[]){
    int err;
    char *key;
    Item * *items = calloc(table->num_of_el ,sizeof (char *));
    int len = 0;

    printf("Choose Key Space (1 or 2):\n");
    int choice = getInt(1);
    while (choice > 2 || choice < 1){
        printf("Invalid choice!\n");
        choice = getInt(1);
    }
    printf("Choose Key:\n");
    key = get_str();

    err = Table_Single_Search(table, key, choice, &items, &len, 0);

    if (err == 0) {
        for (int i = 0; i < len; i++) {
            printf("Element - %s\n", items[i]->info);
        }
    }
    free(items);

    printf("Single search status: %s\n", err_msgs[err]);
    free(key);
    return 1;
}

int D_Table_Multiple_Search(Table *table, const char *err_msgs[]){
    int err;
    char *key1;
    char *key2;

    printf("Print Key for the 1st Key Space:\n");
    key1 = get_str();
    if (key1 == NULL){
        return 0;
    }

    printf("Print Key for the 2nd Key Space:\n");
    key2 = get_str();
    if (key2 == NULL){
        free(key1);
        return 0;
    }

    Node2 *item = NULL;
    err = Table_Multiple_Search(table, key1, key2, &item);
    if (err == 0) {
        printf("Element - %s\n", item->info->info);
    }
    printf("Multiple search status: %s\n", err_msgs[err]);
    free(key1);
    free(key2);
    return 1;
}

int D_Table_Output(Table *table, const char *err_msgs[]){
    int err = 0;

    err = Table_Output(table);

    printf("Output status: %s\n", err_msgs[err]);
    return 1;
}

int D_Table_Multiple_Delete(Table *table, const char *err_msgs[]){
    int err;
    char *key1;
    char *key2;

    printf("Print Key for the 1st Key Space:\n");
    key1 = get_str();
    if (key1 == NULL){
        return 0;
    }

    printf("Print Key for the 2nd Key Space:\n");
    key2 = get_str();
    if (key2 == NULL){
        free(key1);
        return 0;
    }

    err = Table_Multiple_Delete(table, key1, key2);
    free(key1);
    free(key2);
    printf("Multiple delete status: %s\n", err_msgs[err]);
    return 1;
}

int D_Table_Single_Delete(Table *table, const char *err_msgs[]){
    int err;
    char *key;

    printf("Choose Key Space (1 or 2):\n");
    int choice = getInt(1);
    while (choice > 2 || choice < 1){
        printf("Invalid choice!\n");
        choice = getInt(1);
    }
    printf("Choose Key:\n");
    key = get_str();

    err = Table_Single_Delete(table, key, choice, 0);
    free(key);
    printf("Single delete status: %s\n", err_msgs[err]);
    return 1;
}

int D_ks1SearchVerKey(Table *table, const char *err_msgs[]){

    Table *new_table = malloc(sizeof(Table));
    Table_Init(new_table, table->max_size1, table->max_size2);

    int err;
    char *key = NULL;
    int release;

    printf("Choose (1 - Key or 2 - Release):\n");
    int choice = getInt(1);
    while (choice > 2 || choice < 1){
        printf("Invalid choice!\n");
        choice = getInt(1);
    }

    if (choice == 1){
        printf("Print key:\n");
        key = get_str();
    }
    else{
        printf("Print Release:\n");
        release = getInt(0);
    }

    err = ks1SearchVerKey(table, new_table, key, release, choice);
    printf("Search by Key or Release status: %s\n", err_msgs[err]);
    Table_Output(new_table);
    Table_Free(new_table);
    free(key);
    return 1;
}

int D_ks1DeleteVerKey(Table *table, const char *err_msgs[]){
    int err;
    char *key = NULL;
    int release;

    printf("Choose (1 - Key or 2 - Release):\n");
    int choice = getInt(1);
    while (choice > 2 || choice < 1){
        printf("Invalid choice!\n");
        choice = getInt(1);
    }

    if (choice == 1){
        printf("Print key:\n");
        key = get_str();
    }
    else{
        printf("Print Release:\n");
        release = getInt(0);
    }

    err = ks1DeleteVerKey(table, key, release, choice);

    printf("Delete by Key or Release status: %s\n", err_msgs[err]);
    free(key);
    return 1;
}

int D_ks2SearchVerKey(Table *table, const char *err_msgs[]){

    Table *new_table = malloc(sizeof(Table));
    Table_Init(new_table, table->max_size1, table->max_size2);

    int err;
    char *key = NULL;
    int release;

    printf("Choose (1 - Key or 2 - Release):\n");
    int choice = getInt(1);
    while (choice > 2 || choice < 1){
        printf("Invalid choice!\n");
        choice = getInt(1);
    }

    if (choice == 1){
        printf("Print key:\n");
        key = get_str();
    }
    else{
        printf("Print Release:\n");
        release = getInt(0);
    }

    err = ks2SearchVerKey(table, new_table, key, release, choice);
    printf("Search by Key or Release status: %s\n", err_msgs[err]);
    Table_Output(new_table);
    Table_Free(new_table);
    free(key);
    return 1;
}

int D_ks2DeleteVerKey(Table *table, const char *err_msgs[]){
    int err;
    char *key = NULL;
    int release;

    printf("Choose (1 - Key or 2 - Release):\n");
    int choice = getInt(1);
    while (choice > 2 || choice < 1){
        printf("Invalid choice!\n");
        choice = getInt(1);
    }

    if (choice == 1){
        printf("Print key:\n");
        key = get_str();
    }
    else{
        printf("Print Release:\n");
        release = getInt(0);
    }

    err = ks2DeleteVerKey(table, key, release, choice);
    printf("Delete by Key or Release status: %s\n", err_msgs[err]);
    free(key);
    return 1;
}
