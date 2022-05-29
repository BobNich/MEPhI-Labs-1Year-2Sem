#ifndef LAB2_2_STACK_LIBRARY_H
#define LAB2_2_STACK_LIBRARY_H

typedef struct{
    void *choice;
} Stack;

void stack_create(Stack *stack);

int push_stack(Stack *stack, double value);

int pop_stack(Stack *stack, double *output);

void free_stack(Stack *stack);

void print_stack(Stack *stack);

int check_size_stack(Stack *stack, char *);

#endif //LAB2_2_STACK_LIBRARY_H
