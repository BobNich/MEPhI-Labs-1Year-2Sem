#include "1lab.h"
#include <stdio.h>
#include <stdlib.h>
#include "1lab_errors.h"

void task_matr(Matrix *matrix, Matrix *end_matrix, Matrix *task_matrix) {
    task_matrix->lines = matrix->lines;
    task_matrix->matr = (Line *) calloc(matrix->lines, sizeof(Line));
    end_matrix->matr = (Line *) calloc(matrix->lines, sizeof(Line));
    end_matrix->lines = 0;
    int lines = 0;
    for (int i = 0; i < matrix->lines; i++) {
        int k;
        int pointer;
        task_matrix->matr[i].n = matrix->matr[i].n;
        int *p = calloc(matrix->matr[i].n, sizeof(int));
        task_matrix->matr[i].a = p;
        k = inf_add_string_elements(matrix, i, &pointer);
        add_string(matrix, task_matrix, pointer, k, i);
        if (k != 0) {
            end_matrix->lines += 1;
            end_matrix->matr[lines].n = k;
            end_matrix->matr[lines].a = calloc(k, sizeof(int));
            for (int l = 0; l < k; l++) {
                end_matrix->matr[lines].a[l] = task_matrix->matr[i].a[l];
            }
            lines++;
        }
    }
}

void add_string(Matrix *matrix, Matrix *task_matrix, int pointer, int len, int i){
    int g = 0;
    for (int j = pointer + 1; j < pointer + 1 + len; j ++){
        task_matrix->matr[i].a[g] = matrix->matr[i].a[j];
        g++;
    }
}

int inf_add_string_elements(Matrix *matrix, int i, int *pointer){
    int flag_1 = 0;
    int flag_2 = 0;
    int k = 0;
    for (int j = 0; j < matrix->matr[i].n; j++) {
        if (matrix->matr[i].a[j] > 0 && flag_1 == 0 && flag_2 == 0) {
            *pointer = j;
            flag_1 = 1;
        } else if (matrix->matr[i].a[j] < 0 && flag_1 == 0 && flag_2 == 0) {
            *pointer = j;
            flag_2 = 1;
        } else if (matrix->matr[i].a[j] >= 0 && flag_1 == 1 && flag_2 == 0) {
            k++;
        } else if (matrix->matr[i].a[j] <= 0 && flag_1 == 0 && flag_2 == 1) {
            k++;
        } else if (matrix->matr[i].a[j] < 0 && flag_1 == 1 && flag_2 == 0) {
            flag_2 = 1;
        } else if (matrix->matr[i].a[j] > 0 && flag_1 == 0 && flag_2 == 1) {
            flag_1 = 1;
        }
    }
    return k;
}


void free_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->lines; i++) {
        free(matrix->matr[i].a);
    }
    free(matrix->matr);
}

void print_cur_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->lines; i++) {
        for (int j = 0; j < matrix->matr[i].n; j++) {
            printf("%d ", matrix->matr[i].a[j]);
        }
        printf("\n");
    }
}

void create_matrix(Matrix *new_matrix) {
    int m;
    int num;
    printf("Print num of lines:\n");
    m = get_int(1);
    new_matrix->lines = m;
    new_matrix->matr = (Line *) calloc(m, sizeof(Line));
    for (int i = 0; i < m; i++) {
        printf("Print num of elements: (%d)\n", i+1);
        num = get_int(1);
        new_matrix->matr[i].n = num;
        int *p = calloc(num, sizeof(int));
        new_matrix->matr[i].a = p;
        for (int j = 0; j < num; j++) {
            printf("Print element:\n");
            new_matrix->matr[i].a[j] = get_int(0);
        }
    }
}
