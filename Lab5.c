#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define clean() while(getchar() != '\n')

void swap(int *a, int *b){
int temp = *a;
    *a = *b;
    *b = temp;
}

void mat_malloc(int n, int m, int*** mat) {
    *mat = (int**)malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++) {
        (*mat)[i] = (int*)malloc(sizeof(int) * m);
    }
}

void mat_keyboard(int n, int m, int** mat){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",  &mat[i][j]);
        }
    }
}

void mat_random(int n, int m, int** mat){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] = rand()%200 - 100;
        }
    }
}

void mat_arr(int n, int m, int** mat, int arr[]){
int index = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[index] = mat[i][j];
            index++;
        }
    }
}

void arr_sort(int n, int m, int arr[], int** mat){
mat_arr(n, m, mat, arr);
int min = 0;
    for(int i = 0; i < n*m; i++){
        for(int j = i; j < n*m; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}

void mat_sort(int n, int m, int** mat){
int arr[n*m];
arr_sort(n, m, arr, mat);
int index = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] = arr[index];
            index++;
        }
    }
}


void mat_print(int n, int m, int **mat){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}

void mat_free(int*** mat, int n) {
    for (int i = 0; i < n; i++) {
        free((*mat)[i]);
    }
    free(*mat);
}

void Kulev(){
int i = 0;
int n = 0;
int m = 0;
int** mat = NULL;
srand(time(NULL));
printf("Input number of rows in 2D array: ");
scanf("%d", &n);
printf("Input number of columns in 2D array: ");
scanf("%d", &m);
start:
printf("\t1 - Dynamic memory allocation for arrays TWO-DIMENSIONAL\n");
printf("\t2 - Entering tableau elements from the keyboard\n");
printf("\t3 - Completing the table with random values\n");
printf("\t4 - Sorting the table elements using Selection sort\n");
printf("\t5 - Displaying tableau elements on the screen\n");
printf("\t6 - Freeing the memory allocated for the table\n");
printf("\t0 - Exit the program\n");
clean();
scanf("%d", &i);
    switch(i){
case 1:
    mat_malloc(n, m, &mat);
    break;
case 2:
    mat_keyboard(n, m, mat);
    break;
case 3:
    mat_random(n, m, mat);
    break;
case 4:
    mat_sort(n, m, mat);
    break;
case 5:
    mat_print(n, m, mat);
    break;
case 6:
    mat_free(&mat, n);
    break;
case 0:
    return;
    }
    goto start;
}

void arr_max_min(){
int* max;
int* ptr;
int* min;
int n = 0;
start:
printf("Input number of elements in array: ");
scanf("%d", &n);
int* arr = (int*)malloc(sizeof(int) * n);
printf("Input %d elements:", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
ptr = arr;
min = arr;
max = arr;
    for(int i = 0; i < n; i++){
        if(*max < *ptr){
            max = ptr;
        }
            ptr++;
    }
    ptr = arr;
    printf("\tMax element: %d\n", *max);
    for(int i = 0; i < n; i++){
        if(*min > *ptr){
            min = ptr;
        }
            ptr++;
    }
    printf("\tMin element: %d\n", *min);
    free(arr);
goto start;
}

void sum_negativ(){
int n;
start:
srand(time(NULL));
printf("Input number of elements in array: ");
scanf("%d", &n);
int* arr = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        arr[i] = rand()%20 - 10;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
int sum = 0;
int* i;
    for( i = &arr[0]; i < &arr[n]; i++){
        if(*i < 0){
            sum += *i;
        }
    }
    printf("\nSum of negative numbers in array: %d\n", sum);
    free(arr);
    goto start;
}

void reverse(){
int n;
int* ptr;
start:
printf("\nInput number of elements in array: ");
scanf("%d", &n);
int* arr = (int*)malloc(sizeof(int) * n);
printf("\nInput elements %d of array: \n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    ptr = &arr[n - 1];
    for(int i = 0; i < n; i++){
        printf("%d ", *ptr);
        ptr--;
    }
    free(arr);
    goto start;
}

void transpose(){
int n;
int m;
start:
srand(time(NULL));
printf("Input number of rows in mat: ");
scanf("%d", &n);
printf("Input number of columns in mat: ");
scanf("%d", &m);
int** mat = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        mat[i] = (int*)malloc(sizeof(int) * m);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] = rand()%20 - 10;
        }
        printf("\n");
    }
    mat_sort(n, m, mat);
    mat_print(n, m, mat);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < m; j++){
            swap(&mat[i][j], &mat[j][i]);
        }
    }
printf("\n");
mat_print(n, m, mat);
goto start;
}

void sum_rows_columns(){
int n;
int m;
start:
srand(time(NULL));
printf("Input number of rows in mat: ");
scanf("%d", &n);
printf("Input number of columns in mat: ");
scanf("%d", &m);
int** mat = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        mat[i] = (int*)malloc(sizeof(int) * m);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] = rand()%20 - 10;
            printf("\t%d ", mat[i][j]);
        }
        printf("\n");
    }
int sum_rows = 0;
int sum_columns = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum_rows += *(*(mat + i) + j);
        }
        printf("\tSum of row %d: %d\n", i + 1, sum_rows);
        sum_rows = 0;
    }
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            sum_columns += *(*(mat + i) + j);
        }
        printf("\tSum of column %d: %d\n", j + 1, sum_columns);
        sum_columns = 0;
    }
goto start;
}

int main()
{
int k = 0;
start:
printf("\t1 - Kulev: Sort the tableau columns in order ascending using the linear selection method.\n");
printf("\t2 - Easy: Largest and smallest values in the array using pointers.\n");
printf("\t3 - Easy: Sum of all negative numbers in the array using pointer arithmetic.\n");
printf("\t4 - Easy: Reverses the elements of the 1D integer array using pointers.\n");
printf("\t5 - Easy: Transposes it (rows become columns, and vice versa) in-place using pointers.\n");
printf("\t6 - Medium: Sums of each row and each column in the array using pointers.\n");
printf("\t0 - Exit.\n");
scanf("%d", &k);
    switch(k){
case 1:
Kulev();
break;
case 2:
arr_max_min();
break;
case 3:
sum_negativ();
break;
case 4:
reverse();
break;
case 5:
transpose();
break;
case 6:
sum_rows_columns();
break;
case 0:
return 0;
    }
}
