#include <stdio.h>
#include "lab2_library_other.h"
#include "stack_library.h"
#include <string.h>
#include <stdlib.h>

int main() {
    Stack new;
    double result;
    char *s;
    do {
        stack_create(&new);
        printf("Enter your exercise:\n");
        s = get_str();
        if (s) {
            if (check_size_stack(&new, s) == 0){
                free(s);
            }
            else{
                result = task_stack(&new, s);
                printf("Result's %f\n", result);
                free(s);
                free_stack(&new);
            }
            }
        } while (s);
    return 0;
}
