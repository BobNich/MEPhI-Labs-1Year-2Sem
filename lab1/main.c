#include <stdio.h>
#include "1lab.h"

int main() {

    Matrix new_matrix;
    Matrix end_matrix;
    Matrix task_matrix;

    create_matrix(&new_matrix);
    printf("---------------\n");
    printf("Your matrix:\n");
    print_cur_matrix(&new_matrix);
    printf("---------------\n");
    task_matr(&new_matrix, &end_matrix, &task_matrix);
    printf("Your end_matrix:\n");
    print_cur_matrix(&end_matrix);
    printf("---------------\n");
    free_matrix(&task_matrix);
    free_matrix(&end_matrix);
    free_matrix(&new_matrix);
    return 0;
}

