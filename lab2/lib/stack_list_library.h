#ifndef LAB2_STACK_LIST_LIBRARY_H
#define LAB2_STACK_LIST_LIBRARY_H

typedef struct Item{
    struct Item *next;
    double data;
} Item;

typedef struct Stack_List{
    Item *head;
} Stack_List;

void stack_create_list(Stack_List *stack);

int push_stack_list(Stack_List *stack, double value);

int pop_stack_list(Stack_List *stack, double *output);

void free_stack_list(Stack_List *stack);

void print_stack_list(Stack_List *stack);

int check_size_list(Stack_List *stack, char *s);

#endif //LAB2_STACK_LIST_LIBRARY_H
