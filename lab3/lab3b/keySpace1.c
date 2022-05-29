#include "keySpace1.h"

int keySpace1Init(Table *table, int ms1, int cs1) {
    table->max_size1 = ms1;
    table->cur_size1 = cs1;
    table->ks1 = NULL;
    return 0;
}

void freeKeySpace1(Table *table) {
    KeySpace1 *tmp = table->ks1;
    while (table->ks1) {
        tmp = tmp->next;
        free(table->ks1->key);
        free(table->ks1->info);
        free(table->ks1);
        table->ks1 = tmp;
    }
}

int releaseKey1(Table *table, char *key1) {
    int release = 0;
    KeySpace1 *tmp = table->ks1;
    for (int i = 0; i < table->cur_size1; i++) {
        if (strcmp(tmp->key, key1) == 0) {
            release++;
        }
        tmp = tmp->next;
    }
    return release;
}


int ks1SearchVerKey(Table *table, SearchTab *new_table,FILE * fTable, char *key, int version, int choice) {
    int res;
    if (choice == 2) {
        choice = 3;
    }
    Item * *items = calloc(table->num_of_el ,sizeof (char *));
    int len = 0;
    res = Table_Single_Search(table,key,choice, &items, &len, version);
    if (res != 0) {
        free(items);
        return 5;
    }
    for (int i = 0; i < len; i++) {
        keyspaceAdd(new_table, table, fTable, items[i], i);
    }

    for (int i = 0; i < len; i++) {
        printf("Key1 - %s, Key2 - %s, Item - %s\n", new_table[i].key1, new_table[i].key2, new_table[i].element);
        free(new_table[i].key1);
        free(new_table[i].key2);
        free(new_table[i].element);
    }
    free(items);
    return 0;
}

int ks1DeleteVerKey(Table *table, FILE *fTable, char *key, int version, int choice) {
    if (choice == 2) {
        choice = 3;
    }
    Item * *items = calloc(table->num_of_el ,sizeof (char *));
    int len = 0;
    int res = Table_Single_Search(table, key, choice, &items, &len, version);
    if (res != 0) {
        free(items);
        return 5;
    }
    for (int i = 0; i < len; i++){
        Table_Multiple_Delete(table, fTable, items[i]->key1 ,items[i]->key2);
    }
    free(items);
    return 0;
}