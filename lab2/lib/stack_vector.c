#include "stack_library.h"
#include "stack_vector_library.h"
#include <stdlib.h>
#include <stdio.h>
#include "lab2_library_other.h"

int check_size_stack(Stack *stack, char *s){
    if (check_size_vector(stack->choice, s) == 0){
        return 0;
    }
    else{
        return 1;
    }
}

void stack_create(Stack *stack)
{
    printf("Print max_size of your stack:\n");
    int max_size = get_int(0);
    stack->choice = malloc(sizeof(Stack_Vector));
    stack_create_vector(stack->choice, max_size);
}


int push_stack(Stack *stack, double value){
    push_stack_vector(stack->choice, value);
}

int pop_stack(Stack *stack, double *output){
    pop_stack_vector(stack->choice, output);
}

void free_stack(Stack *stack){
    free_stack_vector(stack->choice);
}

void print_stack(Stack *stack){
    print_stack_vector(stack->choice);
}
