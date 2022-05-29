#include "general.h"

void * searchKeys(Table *table, char *key1, char *key2) {
    KeySpace1 *tmp = table->ks1;
    while (tmp) {
        if (strcmp(tmp->key, key1) == 0 && strcmp(tmp->info->key2, key2) == 0) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}



int keysExistence(Table *table, int id2, char *key1) {
    Node2 *tmp;
    if (table->ks2[id2].busy == 1) {
        tmp = table->ks2[id2].node;
        while (tmp) {
            if (strcmp(tmp->info->key1, key1) == 0) {
                return 1;
            }
            tmp = tmp->next;
        }
    }
    return 0;
}

int keyspaceAdd(Table *new_table, Item *tmp) {
    char *item = malloc(sizeof (char) * (strlen(tmp->info) + 1));
    strcpy(item, tmp->info);
    char *key1 = malloc(sizeof (char) * (strlen(tmp->key1) + 1));
    strcpy(key1, tmp->key1);
    char *key2 = malloc(sizeof (char) * (strlen(tmp->key2) + 1));
    strcpy(key2, tmp->key2);
    Table_Add(new_table, item, key1, key2);
    return 0;
}

int addKeys(Table *table, char *key1, char *key2, int id2) {
    int release1 = releaseKey1(table, key1);
    table->cur_size1++;

    int release2 = 0;
    if (table->ks2[id2].busy == 0) {
        table->cur_size2++;
    }
    else {
        release2 = table->ks2[id2].max_release + 1;
    }

    Node2 *tmp = table->ks2[id2].node;
    table->ks2[id2].node = malloc(sizeof(KeySpace2));
    table->ks2[id2].node->next = tmp;
    table->ks2[id2].node->release = release2;
    table->ks2[id2].max_release = release2;
    table->ks2[id2].key = key2;
    table->ks2[id2].busy = 1;

    KeySpace1 *tmp1 = table->ks1;
    table->ks1 = malloc(sizeof(KeySpace1));
    table->ks1->next = tmp1;
    table->ks1->release = release1;
    table->ks1->key = key1;

    return 0;
}