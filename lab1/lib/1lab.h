#ifndef UNTITLED5_1LAB_H
#define UNTITLED5_1LAB_H

typedef struct {
    int n;
    int *a;
} Line;

typedef struct {
    int lines;
    Line *matr;
} Matrix;

void create_matrix(Matrix *);

void free_matrix(Matrix *);

void print_cur_matrix(Matrix *);

void task_matr(Matrix *, Matrix *, Matrix *);

int inf_add_string_elements(Matrix *, int, int *);

void add_string(Matrix *, Matrix *, int , int , int );

#endif //UNTITLED5_1LAB_H
