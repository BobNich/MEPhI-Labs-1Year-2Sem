#include "../Model/general.h"

int freqWords(char *fileName, BinTree **tree) {
    char *buffer = NULL;
    long length;
    FILE *file;

    if (!(file = fopen(fileName, "rb"))) {
        printf("File's not accessible for reading...\n");
        free(fileName);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = malloc(length + 1);
    if (buffer) {
        fread(buffer, 1, length, file);
    }
    buffer[length] = '\0';
    fclose(file);
    free(fileName);

    char *result = filteredText(buffer);
    free(buffer);
    freqFinal(tree, result);
    return 0;
}

void freqFinal(BinTree **tree, char *text) {
    char *tok = strtok(text, " ");
    while (tok != NULL) {
        *tree = addNode(*tree, "1", tok, 1);
        tok = strtok(NULL, " ");
    }
    FILE *file = fopen("freqRes.txt", "w");
    addToFile(*tree, file);
    fclose(file);
}

char *filteredText(char *text) {
    char *div = ".,!?:;\"";
    char *tmpString = calloc(sizeof(char), (strlen(text) + 2));

    char *tok = strtok(text, "\n");
    while (tok != NULL) {
        if (tok[strlen(tok) - 1] == '\n') {
            tok[strlen(tok) - 1] = ' ';
        }
        strcat(tmpString, tok);
        strcat(tmpString, " ");
        tok = strtok(NULL, "\n");
    }
    char *res = tokenize(tmpString, " \t\r");
    res = tokenize(res, div);
    res = tokenize(res, " ");
    res = regSimplifyEng(res);
    return res;
}

char *tokenize(char *plain, char *divisor) {
    char *res = calloc(sizeof(char), strlen(plain) + 2);
    char *token = strtok(plain, divisor);
    while (token != NULL) {
        strncat(res, token, strlen(token));
        strncat(res, " ", 1);
        token = strtok(NULL, divisor);
    }
    free(plain);
    return res;
}

char *regSimplifyEng(char *text) {
    for (int i = 0; i < strlen(text); i++) {
        char a = text[i];
        if (a >= 'A' && a <= 'Z') {
            text[i] = (char) (a + ('a' - 'A'));
        }
    }
    return text;
}