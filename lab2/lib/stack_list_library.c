#include "stack_list_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_size_list(Stack_List *stack, char *s){
    return 1;
}

void stack_create_list(Stack_List *stack){
    stack->head = NULL;
}

void print_stack_list(Stack_List *stack){
    Item *head = stack->head;
    while (head->next){
        printf("%f ", head->data);
        head = head->next;
    }
    printf("%f ", head->data);
    printf("\n");
}

void free_stack_list(Stack_List *stack){
    while (stack->head){
        Item *head = stack->head;
        stack->head = head->next;
        free(head);
    }
    free(stack);
}


int push_stack_list(Stack_List *stack, double value){
    Item *new = calloc(1, sizeof (Item));
    if (!new){
        printf("Error with memory!\n");
        return -1;
    }
    new->data = value;
    new->next = stack->head;
    stack->head = new;
    return 0;
}

int pop_stack_list(Stack_List *stack, double *output){
    if (!stack->head){
        return -1;
    }
    *output = stack->head->data;
    Item *head = stack->head;
    stack->head = head->next;
    free(head);
    return 0;
}