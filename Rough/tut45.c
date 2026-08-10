#include<stdio.h>
#include<stdlib.h>

int main(){
    int* arr1 = (int*)malloc(5 * sizeof(int));
    for(int i = 0; i < 5; i++) {
        arr1[i] = i + 1;
    }

    int* arr2 = (int*)calloc(5, sizeof(int));

    arr1 = (int*)realloc(arr1, 10*sizeof(int));
    for(int i = 5; i < 10; i++) {
        arr1[i] = i + 1;
    }

    printf("arr1 : ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    printf("arr2 : ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");


    free(arr1);
    free(arr2);
    return 0; 
}