#ifndef LAB2_STACK_VECTOR_LIBRARY_H
#define LAB2_STACK_VECTOR_LIBRARY_H

typedef struct Stack_Vector{
    double * stack;
    int max_size;
    int current;
} Stack_Vector;

void stack_create_vector(Stack_Vector *stack, int max_size);

int push_stack_vector(Stack_Vector *stack, double value);

int pop_stack_vector(Stack_Vector *stack, double *output);

void free_stack_vector(Stack_Vector *stack);

void print_stack_vector(Stack_Vector *stack);

int check_size_vector(Stack_Vector *stack, char *s);

#endif //LAB2_STACK_VECTOR_LIBRARY_H
