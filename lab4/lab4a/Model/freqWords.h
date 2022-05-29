#ifndef LAB4_FREQWORDS_H
#define LAB4_FREQWORDS_H

int freqWords(char *fileName, BinTree **tree);
char *filteredText(char *text);
void freqFinal(BinTree **tree, char *text);
char *tokenize(char *plain, char *divisor);
char *regSimplifyEng(char *text);

#endif
