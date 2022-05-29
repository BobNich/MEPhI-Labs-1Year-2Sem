#include "general.h"

int dialog(const char *msgs[],int N, const char *err_msgs[]){

    int choice;

    do{
        printf("-------------------------\n");
        for (int i = 0; i < N; i++){
            printf("%s\n",msgs[i]);
        }
        printf("-------------------------\n");
        printf("Your choice -->");
        choice = getInt(0);
        printf("-------------------------\n");

        if (choice < 0 || choice >= N){
            printf("Wrong. Repeat!\n");
        }

    } while(choice < 0 || choice >= N);

    return choice;
}