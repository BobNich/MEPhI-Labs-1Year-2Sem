#include "general.h"

int Table_Init(Table *table, int ms1, int ms2) {
    table->num_of_el = 0;
    keySpace1Init(table, ms1);
    keySpace2Init(table, ms2);
    return 0;
}

int Table_Output(Table *table) {
    KeySpace1 *tmp = table->ks1;
    while (tmp) {
        printf("Element - %s, Key1 - %s, Key2 - %s\n", tmp->info->info, tmp->info->key1, tmp->info->key2);
        tmp = tmp->next;
    }
    return 0;
}

void Table_Free(Table *table) {
    freeElements(table);
    freeKeySpace1(table);
    freeKeySpace2(table);
    free(table);
}

void freeElements(Table *table) {
    KeySpace1 *tmp = table->ks1;
    while (tmp) {
        freeElement(tmp);
        tmp = tmp->next;
    }
}

void freeElement(KeySpace1 *tmp) {
    free(tmp->info->info);
    free(tmp->info);
}

int Table_Add(Table *table, char *element, char *key1, char *key2) {
    int id2;

    id2 = searchKey2(table, key2);

    if (overflow(table, id2)) {
        free(key1);
        free(key2);
        free(element);
        return 1;
    }

    if (keysExistence(table, id2, key1)) {
        free(key1);
        free(key2);
        free(element);
        return 3;
    }

    if (table->ks2[id2].busy == 1) {
        free(key2);
        key2 = table->ks2[id2].key;
    }

    addKeys(table, key1, key2, id2);
    addItem(table, element, key1, key2, id2);

    return 0;
}

bool overflow(Table *table, int id2) {
    bool res1 = table->cur_size1 == table->max_size1;
    bool res2 = false;
    if (table->ks2[id2].busy == 0 && table->cur_size2 == table->max_size2) {
            res2 = true;
    }
    return res1 || res2;
}

int addItem(Table *table, char *element, char *key1, char *key2, int id2) {
    table->num_of_el++;
    table->ks1->info = malloc(sizeof(Item));
    table->ks2[id2].node->info = table->ks1->info;
    table->ks1->info->info = element;
    table->ks1->info->key1 = key1;
    table->ks1->info->key2 = key2;
    return 0;
}

int Table_Multiple_Search(Table *table, char *key1, char *key2, Node2 **item) {
    int ind2 = searchKey2(table, key2);
    if (table->ks2[ind2].busy == 0) {
        return 4;
    } else {
        Node2 *tmp = table->ks2[ind2].node;
        while (tmp) {
            if (strcmp(tmp->info->key1, key1) == 0) {
                *item = tmp;
                return 0;
            }
            tmp = tmp->next;
        }
        return 4;
    }
}


int Table_Single_Search(Table *table, char *key, int choice, Item ***items, int *len, int release) {
    switch (choice) {
        case 1:
            return Table_Single_S1(table, key, *items, len);
        case 2:
            return Table_Single_S2(table, key, *items, len);
        case 3:
            return Table_Single_S1_R(table, release, *items, len);
        case 4:
            return Table_Single_S2_R(table, release, *items, len);
        default:
            break;
    }
    return 0;
}

int Table_Single_S1(Table *table, char *key, Item **items, int *len) {
    KeySpace1 *tmp;
    tmp = table->ks1;
    while (tmp) {
        if (strcmp(tmp->key, key) == 0){
            items[*len] = tmp->info;
            *len += 1;
        }
        tmp = tmp->next;
    }
    if (*len == 0) {
        return 5;
    }
    return 0;
}

int Table_Single_S1_R(Table *table, int release, Item **items, int *len) {
    KeySpace1 *tmp;
    tmp = table->ks1;
    while (tmp) {
        if (tmp->release == release){
            items[*len] = tmp->info;
            *len += 1;
        }
        tmp = tmp->next;
    }
    if (*len == 0) {
        return 5;
    }
    return 0;
}

int Table_Single_S2(Table *table, char *key, Item **items, int *len) {
    int ind2 = searchKey2(table, key);
    if (table->ks2[ind2].busy == 0) {
        return 5;
    } else {
        Node2 *tmp;
        tmp = table->ks2[ind2].node;
        while (tmp) {
            items[*len] = tmp->info;
            *len += 1;
            tmp = tmp->next;
        }
    }
    return 0;
}

int Table_Single_S2_R(Table *table, int release, Item **items, int *len) {
    Node2 *tmp;
    for (int i = 0; i < table->max_size2; i++) {
        tmp = table->ks2[i].node;
        while (tmp) {
            if (tmp->release == release){
                items[*len] = tmp->info;
                *len += 1;
            }
            tmp = tmp->next;
        }
    }
    return 0;
}

int Table_Multiple_Delete(Table *table, char *key1, char *key2) {
    Node2 *item = NULL;
    if (Table_Multiple_Search(table, key1, key2, &item) != 0) {
        return 4;
    }
    Item* data = item->info;
    table->num_of_el--;
    deleteKey2(table, key2, data->info);
    deleteKey1(table, key1, data->info);
    deleteElement(table, data);
    return 0;

}

int deleteKey2(Table *table, char *key2, char *data) {
    int id2 = searchKey2(table, key2);
    Node2 *tmp = table->ks2[id2].node;
    Node2 *tmp_prev = NULL;

    while (tmp) {
        if (!strcmp(tmp->info->info, data)) {
            if (tmp == table->ks2[id2].node) {
                table->ks2[id2].node = tmp->next;
                if (table->ks2[id2].max_release == 0) {
                    table->ks2[id2].busy = 0;
                    free(table->ks2[id2].key);
                    table->ks2[id2].key = NULL;
                }
                table->cur_size2--;
                free(tmp);
                return 0;
            } else {
                tmp_prev->next = tmp->next;
                free(tmp);
                return 0;
            }
        }
        tmp_prev = tmp;
        tmp = tmp->next;
    }
    return 1;
}

int deleteKey1(Table *table, char *key1, char *data) {
    KeySpace1 *tmp = table->ks1;
    KeySpace1 *tmp_prev = NULL;
    table->cur_size1--;

    while (tmp) {
        if (!strcmp(tmp->info->info, data)) {
            if (tmp == table->ks1) {
                table->ks1 = tmp->next;
                free(tmp->key);
                free(tmp);
                return 0;
            }
            else {
                tmp_prev->next = tmp->next;
                free(tmp->key);
                free(tmp);
                return 0;
            }
        }
        tmp_prev = tmp;
        tmp = tmp->next;
    }
    return 1;
}

int deleteElement(Table *table, Item *data) {
    free(data->info);
    free(data);
    return 0;
}

int Table_Single_Delete(Table *table, char *key, int choice, int release) {
    Item * *items = calloc(table->num_of_el ,sizeof (char *));
    int len = 0;
    int res = Table_Single_Search(table, key, choice, &items, &len, release);
    if (res != 0) {
        free(items);
        return 5;
    }
    for (int i = 0; i < len; i++){
        Table_Multiple_Delete(table, items[i]->key1 ,items[i]->key2);
    }
    free(items);
    return 0;
}
