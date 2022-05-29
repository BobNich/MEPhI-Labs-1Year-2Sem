#include "general.h"

int main() {

    int (*func[])(Table *, const char *err_msgs[]) = {NULL, D_Table_Add, D_Table_Single_Search,
                                                      D_Table_Multiple_Search, D_Table_Single_Delete,
                                                      D_Table_Multiple_Delete, D_Table_Output, D_ks1SearchVerKey,
                                                      D_ks1DeleteVerKey, D_ks2SearchVerKey,
                                                      D_ks2DeleteVerKey, D_Iterator};

    const char *msgs[] = {"0: Exit", "1: Add element", "2: Search by 1-Key Space", "3: Search by 2-Key Spaces",
                          "4: Delete by 1-Key Space", "5: Delete by 2-Key Spaces", "6: Table Output",
                          "7: Search by Key or Release in 1-Key Space", "8: Delete by Key or Release in 1-Key Space",
                          "9: Search by Key or Release in 2-Key Space", "10: Delete by Key or Release in 2-Key Space",
                          "11: Iterator"};
    const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);

    const char *err_msgs[] = {"Ok", "Overflow", "Error with input", "Existing Keys",
                              "No elements with (key1, key2)", "No elements with this key",
                              "No elements with this key or release"};

    Table *table = malloc(sizeof(*table));
    D_Table_Init(table, err_msgs);

    int choice = dialog(msgs, NMsgs, err_msgs);

    while (choice) {
        if (choice) {
            func[choice](table, err_msgs);
        }
        choice = dialog(msgs, NMsgs, err_msgs);
    }

    Table_Free(table);

    printf("Bye!\n");
    return 0;
}