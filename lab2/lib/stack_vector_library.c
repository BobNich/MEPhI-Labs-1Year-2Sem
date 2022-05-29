#include "stack_vector_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stack_create_vector(Stack_Vector *stack, int max_size){
   stack->max_size = max_size;
   stack->current = 0;
   stack->stack = calloc(max_size, sizeof(double));
}

void print_stack_vector(Stack_Vector *stack) {
    int n = stack->current;
    while (n > 0) {
        printf("%f ", stack->stack[n - 1]);
        n--;
    }
    printf("\n");
}

void free_stack_vector(Stack_Vector *stack) {
    free(stack->stack);
//    free(stack);
}


int push_stack_vector(Stack_Vector *stack,double value) {
    if (stack->current < stack->max_size) {
        stack->stack[stack->current] = value;
        stack->current++;
    } else {
        printf("Overflow!\n");
        return -1;
    }
    return 0;
}

int pop_stack_vector(Stack_Vector *stack, double *output) {
    if (stack->current > 0) {
        stack->current--;
        *output = stack->stack[stack->current];
    } else {
        printf("Error!\n");
        return -1;
    }
    return 0;
}

int check_size_vector(Stack_Vector *stack, char *s){
    int count = 0;
    int max = 0;
    for (int i = 0; i < strlen(s); i++){
        if (s[i] <= '9' && s[i] >= '0'){
            count ++;
        }
        else{
            if (max < count){
                max = count;
            }
            count = 0;
        }
    }
    if (stack->max_size < count){
        printf("Overflow!\n");
        return 0;
    }
    return 1;
}