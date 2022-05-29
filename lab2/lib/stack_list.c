#include "stack_library.h"
#include "stack_list_library.h"
#include <stdlib.h>

void stack_create(Stack *stack)
{
    stack->choice = malloc(sizeof(Stack_List));
    stack_create_list(stack->choice);
}

int push_stack(Stack *stack, double value){
    push_stack_list(stack->choice, value);
}

int pop_stack(Stack *stack, double *output){
    pop_stack_list(stack->choice, output);
}

void free_stack(Stack *stack){
    free_stack_list(stack->choice);
}

void print_stack(Stack *stack){
    print_stack_list(stack->choice);
}

int check_size_stack(Stack *stack, char *s){
    check_size_list(stack->choice, s);
}