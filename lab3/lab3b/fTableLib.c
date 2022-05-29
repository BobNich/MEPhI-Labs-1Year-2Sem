#include "general.h"


int Table_Rewrite_Description(Table *table, FILE *fTable) {
    if (!(fTable = fopen(table->fName, "r+b"))) {
        return 7;
    }
    fwrite(&table->num_of_el, sizeof(int), 1, fTable);
    fwrite(&table->max_size1, sizeof(int), 1, fTable);
    fwrite(&table->max_size2, sizeof(int), 1, fTable);
    fwrite(&table->cur_size1, sizeof(int), 1, fTable);
    fwrite(&table->cur_size2, sizeof(int), 1, fTable);
    fclose(fTable);
    return 0;
}

int Table_Import(Table * table, FILE * fTable) {
    if (!(fTable = fopen(table->fName, "rb"))) {
        return 7;
    }
    fread(&table->num_of_el, sizeof (int), 1, fTable);
    fread(&table->max_size1, sizeof (int), 1, fTable);
    fread(&table->max_size2, sizeof (int), 1, fTable);
    fread(&table->cur_size1, sizeof (int), 1, fTable);
    fread(&table->cur_size2, sizeof (int), 1, fTable);

    keySpace1Init(table, table->max_size1, table->cur_size1);
    keySpace2Init(table, table->max_size2, table->cur_size2);

    int offset = 5 * sizeof (int);
    int nOfEl = table->num_of_el;
    while (nOfEl) {
        if (addElementFile(table, fTable, &offset)) {
            nOfEl--;
        }
    }
    fclose(fTable);
    return 0;
}

int addElementFile(Table *table, FILE *fTable, int *offset) {
    fseek(fTable, *offset, SEEK_SET);
    int set = 0;
    int flag = 0;
    int *item_descriptor = malloc(6 * sizeof(int));
    for (int j = 0; j < 6; j++) {
        fread(&item_descriptor[j], sizeof(int), 1, fTable);
    }
    if (item_descriptor[0] != -1) {
        flag = 1;
        set = item_descriptor[1] + item_descriptor[2] + item_descriptor[3] + 6 * sizeof (int);
        char *key1 = malloc(sizeof(char) * item_descriptor[1]);
        fread(key1, sizeof (char), item_descriptor[1], fTable);
        char *key2 = malloc(sizeof(char) * item_descriptor[2]);
        fread(key2, sizeof (char), item_descriptor[2], fTable);
        char *data = malloc(sizeof (char) * item_descriptor[3]);
        fread(data, sizeof (char), item_descriptor[3], fTable);
        addKeysImport(table, key1, key2, item_descriptor[4], item_descriptor[5], *offset);
        free(data);
    }
    set = item_descriptor[1] + item_descriptor[2] + item_descriptor[3] + 6 * sizeof (int);
    free(item_descriptor);
    *offset +=set;
    return flag;
}

int addKeysImport(Table *table, char *key1, char *key2, int release1, int release2, int offset) {
    int id2;
    id2 = searchKey2(table, key2);

    Node2 *tmp = table->ks2[id2].node;
    table->ks2[id2].node = malloc(sizeof(KeySpace2));
    table->ks2[id2].node->info = malloc(sizeof(Item));
    table->ks2[id2].node->info->key2 = key2;
    table->ks2[id2].node->next = tmp;
    table->ks2[id2].node->release = release2;
    table->ks2[id2].max_release = release2;
    if (table->ks2[id2].busy == 0){
        table->ks2[id2].key = key2;
    }
    else {
        free(key2);
    }
    table->ks2[id2].busy = 1;

    KeySpace1 *tmp1 = table->ks1;
    table->ks1 = malloc(sizeof(KeySpace1));
    table->ks1->info = table->ks2[id2].node->info;
    table->ks1->info->key1 = key1;
    table->ks1->info->offset = offset;
    table->ks1->next = tmp1;
    table->ks1->release = release1;
    table->ks1->key = key1;

    return 0;
}


int printElementFile(Table *table, FILE *fTable, Item * item){
    int offset = item->offset;
    if (!(fTable = fopen(table->fName, "rb"))) {
        return 7;
    }
    fseek(fTable, offset, SEEK_SET);
    fread(&offset, sizeof(int), 1, fTable);
    int *item_descriptor = malloc(5 * sizeof(int));
    for (int j = 0; j < 5; j++) {
        fread(&item_descriptor[j], sizeof(int), 1, fTable);
    }
    char *key1 = malloc(sizeof(char) * item_descriptor[0]);
    char *key2 = malloc(sizeof(char) * item_descriptor[1]);
    char *data = malloc(sizeof(char) * item_descriptor[2]);
    fread(key1, sizeof(char), item_descriptor[0], fTable);
    fread(key2, sizeof(char), item_descriptor[1], fTable);
    fread(data, sizeof(char), item_descriptor[2], fTable);
    printf("Key1 - %s, Key2 - %s, Item - %s\n", key1, key2, data);
    free(item_descriptor);
    free(key1);
    free(key2);
    free(data);
    fclose(fTable);
    return 0;
}