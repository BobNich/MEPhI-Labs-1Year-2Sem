#include "stack_library.h"
#include <string.h>
#include <stdio.h>

double task_stack(Stack *stack, char *s){
    double output_1;
    double output_2;
    for (int i = strlen(s) - 1; i >= 0; i--){
        if (s[i] == '+'){
            printf("+\n");
            pop_stack(stack, &output_1);
            pop_stack(stack, &output_2);
            push_stack(stack, output_1 + output_2);
        }
        else if (s[i] == '-'){
            pop_stack(stack, &output_1);
            pop_stack(stack, &output_2);
            push_stack(stack, output_1 - output_2);
        }
        else if (s[i] == '*'){
            pop_stack(stack, &output_1);
            pop_stack(stack, &output_2);
            push_stack(stack, output_1 * output_2);
        }
        else if (s[i] == '/'){
            pop_stack(stack, &output_1);
            pop_stack(stack, &output_2);
            push_stack(stack, output_1 / output_2);
        }
        else {
            push_stack(stack, s[i] - 48);
        }
    }
    pop_stack(stack, &output_1);
    return output_1;
}