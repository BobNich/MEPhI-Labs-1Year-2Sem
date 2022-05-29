#include "keySpace2.h"

int keySpace2Init(Table *table, int ms2) {
    table->max_size2 = ms2;
    table->cur_size2 = 0;
    table->ks2 = calloc(ms2, sizeof(*table->ks2));

    for (int i = 0; i < ms2; i++) {
        table->ks2[i].max_release = 0;
        table->ks2[i].busy = 0;
        table->ks2[i].node = NULL;
    }
    return 0;
}

int hash(Table *table, char *element) {
    int ms2 = table->max_size2;
    int sum = 0;
    for (int i = 0; i < strlen(element); i++) {
        sum += element[i];
    }
    int h1 = sum % ms2;
    int h2 = 2 + sum % ms2;
    return (h1 + h2) % ms2;
}

int searchKey2(Table *table, char *key2) {
    int ms2 = table->max_size2;
    int id2 = hash(table, key2);
    for (int i = 0; i < ms2; i++) {
        if (table->ks2[(id2 + i) % ms2].busy == 1) {
            if (strcmp(table->ks2[(id2 + i) % ms2].key, key2) == 0) {
                return id2 + i;
            }
        }
    }
    return searchEmptyPosKey2(table, id2);
}

int searchEmptyPosKey2(Table *table, int hash_id) {
    int ms2 = table->max_size2;
    for (int i = 0; i < ms2; i++) {
        if (table->ks2[(hash_id + i) % ms2].busy == 0) {
            return hash_id + i;
        }
    }
    return -1;
}

void freeKeySpace2(Table *table) {
    Node2 *tmp;
    for (int i = 0; i < table->max_size2; i++) {
        tmp = table->ks2[i].node;
        free(table->ks2[i].key);
        while (table->ks2[i].node) {
            tmp = tmp->next;
            free(table->ks2[i].node);
            table->ks2[i].node = tmp;
        }
    }
    free(tmp);
    free(table->ks2);
}


int ks2SearchVerKey(Table *table, Table *new_table, char *key, int version, int choice) {
    if (choice == 1) {
        choice = 2;
    }
    else {
        choice = 4;
    }
    int res;
    Item * *items = calloc(table->num_of_el ,sizeof (char *));
    int len = 0;
    res = Table_Single_Search(table,key, choice, &items, &len, version);
    if (res != 0) {
        free(items);
        return 5;
    }
    for (int i = 0; i < len; i++) {
        keyspaceAdd(new_table, items[i]);
    }
    free(items);
    return 0;
}

int ks2DeleteVerKey(Table *table, char *key, int version, int choice) {
    if (choice == 1) {
        choice = 2;
    } else {
        choice = 4;
    }
    Item **items = calloc(table->num_of_el, sizeof(char *));
    int len = 0;
    int res = Table_Single_Search(table, key, choice, &items, &len, version);
    if (res != 0) {
        free(items);
        return 5;
    }
    for (int i = 0; i < len; i++) {
        Table_Multiple_Delete(table, items[i]->key1, items[i]->key2);
    }
    free(items);
    return 0;
}