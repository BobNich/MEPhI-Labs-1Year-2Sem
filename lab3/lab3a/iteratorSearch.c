#include "general.h"

void *iteratorSearch(void * mas, void * (*next)(void *)) {
    return next(mas);
}

void *nextKey2(void *cur) {
    Node2 *iterate = (Node2 *) cur;
    if (iterate->next == NULL) {
        return NULL;
    }
    return iterate->next;
}

void *nextKey1(void *cur) {
    KeySpace1 *iterate = (KeySpace1 *) cur;
    char *key1 = iterate->key;
    iterate = iterate->next;
    while (iterate) {
        if (strcmp(iterate->key, key1) == 0) {
            return iterate;
        }
        iterate = iterate->next;
    }
    return NULL;
}

void *nextKeys(void *cur) {
    KeySpace1 *iterate = (KeySpace1 *) cur;
    char *key1 = iterate->info->key1;
    char *key2 = iterate->info->key2;
    iterate = iterate->next;
    while (iterate) {
        if (strcmp(iterate->info->key1, key1) == 0 && strcmp(iterate->info->key2, key2) == 0) {
            return iterate;
        }
        iterate = iterate->next;
    }
    return NULL;
}

int iterateKey2(Table *table) {
    int choice;
    printf("Print Key2:\n");
    char *key2 = get_str();
    int id2 = searchKey2(table, key2);
    if (table->ks2[id2].busy == 0) {
        printf("No elements\n");
        free(key2);
        return 1;
    }

    void *iter_f = table->ks2[id2].node;
    printf("Your element - %s\n", ((Node2 *)iter_f)->info->info);

    printf("Next?(1-yes, 2-no)\n");
    choice = getInt(1);
    void *iterate = iteratorSearch(iter_f, nextKey2);
    while (choice == 1) {
        Node2 *iterated = (Node2 *) iterate;

        if (!iterated) {
            printf("End of the list!\n");
            free(key2);
            return 0;
        }
        printf("Your element - %s\n", iterated->info->info);
        printf("Next?(1-yes, 2-no)\n");
        choice = getInt(1);
        if (choice == 1){
            iterate = iteratorSearch((void *)iterated, nextKey2);
        }
    }
    free(key2);
    return 0;
}

int iterateKey1(Table *table) {
    int choice;
    printf("Print Key1:\n");
    char *key1 = get_str();
    void *iter_f = searchKey1(table, key1);
    if (iter_f == NULL) {
        free(key1);
        return 1;
    }
    printf("Your element - %s\n", ((KeySpace1 *)iter_f)->info->info);
    printf("Next?(1-yes, 2-no)\n");
    choice = getInt(1);
    void *iterate = iteratorSearch(iter_f, nextKey1);
    while (choice == 1) {
        KeySpace1 *iterated = (KeySpace1 *) iterate;

        if (!iterated) {
            free(key1);
            printf("End of the list!\n");
            return 1;
        }

        printf("Your element - %s\n", iterated->info->info);
        printf("Next?(1-yes, 2-no)\n");
        choice = getInt(1);
        if (choice == 1){
            iterate = iteratorSearch((void *)iterated, nextKey1);
        }
    }
    free(key1);
    return 0;
}

int iterateKeys(Table *table) {
    int choice;
    printf("Print Key1:\n");
    char *key1 = get_str();
    printf("Print Key2:\n");
    char *key2 = get_str();
    void *iter_f = searchKeys(table, key1, key2);
    if (iter_f == NULL) {
        free(key1);
        free(key2);
        return 1;
    }
    printf("Your element - %s\n", ((KeySpace1 *)iter_f)->info->info);
    printf("Next?(1-yes, 2-no)\n");
    choice = getInt(1);
    void *iterate = iteratorSearch(iter_f, nextKeys);
    while (choice == 1) {
        KeySpace1 *iterated = (KeySpace1 *) iterate;

        if (!iterated) {
            free(key1);
            free(key2);
            printf("End of the list!\n");
            return 1;
        }

        printf("Your element - %s\n", iterated->info->info);
        printf("Next?(1-yes, 2-no)\n");
        choice = getInt(1);
        if (choice == 1){
            iterate = iteratorSearch((void *)iterated, nextKeys);
        }
    }
    free(key1);
    free(key2);
    return 0;
}


int iterateTable(Table *table, int choice) {
    switch (choice) {
        case 1:
            iterateKey1(table);
            break;
        case 2:
            iterateKey2(table);
            break;
        case 3:
            iterateKeys(table);
            break;
        default:
            break;
    }
    return 0;
}

