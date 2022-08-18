// Program to bubble sort an array
#include <stdio.h>

void main(){
    int array[] = {15,48,22,6,1,79,5,48,2,3156,4,8,1,561,2,19,84,5};
    int n = sizeof(array) / sizeof(array[0]);
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}