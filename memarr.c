#include <stdio.h>
#include <stdlib.h>

int main(void){
    int **arr;
    arr = (int **)malloc(sizeof(int *) * 5);
    arr[0] = (int *)malloc(sizeof(int) * 6);
    arr[1] = (int *)malloc(sizeof(int) * 3);
    arr[2] = (int *)malloc(sizeof(int) * 4);
    arr[3] = (int *)malloc(sizeof(int) * 2);
    arr[4] = (int *)malloc(sizeof(int) * 8);

    arr[0][0] = 4;
    arr[0][1] = 6;
    arr[2][0] = 1;
    arr[4][4] = 37;

    printf("%d\n",arr[0][0]);
    printf("%d\n",arr[0][1]);
    printf("%d\n",arr[2][0]);
    printf("%d\n",arr[4][4]);

    return (0);
}